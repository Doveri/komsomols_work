#include "consoleclient.h"
SingClient::SingClient()
{
    socket = new QTcpSocket;
    socket->connectToHost("127.0.0.1", 33333);
    connect(socket,&QTcpSocket::readyRead,this,&SingClient::slot_readFromServer);
}

SingClient* SingClient::getInstance() {
        if(!p_instance)
    {
        p_instance = new SingClient();
        destroyer.initialize(p_instance);
    }
    return p_instance;
}

SingClient::~SingClient()
{
    socket->close();
}

bool SingClient::sendToServer(QString msg)
{
    if (socket->waitForConnected()) {
            QByteArray data = msg.toUtf8(); // преобразуем строку в QByteArray
            socket->write(data); // отправляем данные на сервер
            socket->waitForBytesWritten();
            socket->disconnectFromHost();
            return true;
        } else {
            socket->disconnectFromHost();
            return false;
}
}
void SingClient::slot_readFromServer()
{
    QByteArray data = socket->readAll(); // считываем данные из сокета
    QString message = QString::fromUtf8(data); // преобразуем QByteArray в QString
    qDebug() << "Received message from server:" << message; // выводим сообщение в консоль
}
SingClient * SingClient::p_instance;
SingClientDestroyer SingClient::destroyer;
