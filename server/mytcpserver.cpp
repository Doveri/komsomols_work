#include "mytcpserver.h"

// Конструктор класса MyTcpServer
MyTcpServer::MyTcpServer(QObject *parent) : QTcpServer(parent)
{
    // Запуск сервера на порту 33333 и вывод сообщения, если не удалось запустить сервер
    if (!listen(QHostAddress::Any, 33333)) {
        qDebug() << "Server not started!";
        return;
    }
    qDebug() << "Server started!";

    // Устанавливаем связь между сигналом newConnection и слотом slotNewConnection
    connect(this, &MyTcpServer::newConnection, this, &MyTcpServer::slotNewConnection);
    connectToDatabase();
}

// Метод для отправки сообщений клиенту
void MyTcpServer::sendToClient(QString data) {
    clientSocket->write(data.toUtf8());
}


// Слот, вызываемый при новом подключении клиента
void MyTcpServer::slotNewConnection()
{
    qDebug() << "New user connected!";

    // Получаем указатель на сокет клиента и устанавливаем связь между сигналами readyRead и disconnected и соответствующими слотами
    QTcpSocket* clientSocket = nextPendingConnection();
    clientSockets.append(clientSocket);
    connect(clientSocket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
    connect(clientSocket, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);
}

// Слот, вызываемый при отключении клиента
void MyTcpServer::slotClientDisconnected()
{
    qDebug() << "User disconnected!";

    // Получаем дескриптор сокета клиента и удаляем его из списка
    QTcpSocket* clientSocket = qobject_cast<QTcpSocket*>(sender());
    clientSockets.remove(clientSocket->socketDescriptor());

    // Удаляем объект сокета клиента
    clientSocket->deleteLater();
}

// Слот, вызываемый при чтении данных от клиента
void MyTcpServer::slotServerRead()
{
    // Получаем указатель на сокет клиента, от которого пришли данные
    QTcpSocket* clientSocket = qobject_cast<QTcpSocket*>(sender());

    // Читаем строку из сокета и выводим сообщение о запросе в консоль
    QString request;
    while (clientSocket->bytesAvailable()) {
        QByteArray data = clientSocket->readAll();
        request += QString::fromUtf8(data);
    }
    request = request.trimmed();
    qDebug() << "Request received from client " << clientSocket->socketDescriptor() << ": " << request;    
    // Обрабатываем запрос и отправляем ответ клиенту
    QString response = parsing(request);
    clientSocket->write(response.toUtf8());
}

// Метод для соединения с базой данных
void MyTcpServer::connectToDatabase()
{
    // Создаем объект класса Singleton и подключаемся к базе данных
    Singleton& db = Singleton::getInstance();
    if (!db.connectToDB()) {
        qDebug() << "Failed to connect to database!";
    }
}

// Метод для закрытия соединения с базой данных
void MyTcpServer::close()
{
    // Получаем объект класса Singleton и закрываем соединение с базой данных
    Singleton& db = Singleton::getInstance();
    db.close();  // Закрываем соединение с БД
    qDebug() << "Connection to database closed!";
}
