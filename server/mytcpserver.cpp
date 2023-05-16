#include "mytcpserver.h"
#include "func.h"
#include <QDebug>
#include <QtSql>

MyTcpServer::~MyTcpServer(){
    //mTcpSocket->close();
    mTcpServer->close();
    server_status=0;
}

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else{
        server_status=1;
        qDebug() << "server is started";
        //qDebug() << "Connected to database";
//        qDebug()<<Singleton::getInstance()->query("SELECT * FROM demo;");
    }
}

void MyTcpServer::slotNewConnection(){
    if(server_status==1){
        QTcpSocket* curr_mTcpSocket;
        curr_mTcpSocket = mTcpServer->nextPendingConnection();
        curr_mTcpSocket->write("Hello, World!!! I am echo server!\r\n");
        connect(curr_mTcpSocket, &QTcpSocket::readyRead,
                this,&MyTcpServer::slotServerRead);
        connect(curr_mTcpSocket,&QTcpSocket::disconnected,
                this,&MyTcpServer::slotClientDisconnected);
        mTcpSocket.push_back(curr_mTcpSocket);
    }
}

void MyTcpServer::slotServerRead(){
    QByteArray array;
    QString str;
    QTcpSocket* curr_mTcpSocket = (QTcpSocket*)sender();
    while(curr_mTcpSocket->bytesAvailable()>0){
       array.append(curr_mTcpSocket->readAll());
       str+=array;
    }
    array="";
    array.append(str.toUtf8());

    QByteArray mes = array.left(str.size());
    qDebug()<<mes;
    curr_mTcpSocket->write(mes);
    QString task = array.left(str.size());
    QByteArray fun;
    fun = parsing(task);
    qDebug()<<fun;
    curr_mTcpSocket->write(fun);
}

void MyTcpServer::slotClientDisconnected(){
    QTcpSocket* curr_mTcpSocket = (QTcpSocket*)sender();
    curr_mTcpSocket->close();
    curr_mTcpSocket->deleteLater();
}


