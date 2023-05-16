#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "singleton.h"
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QList>
#include <QtSql>

class MyTcpServer : public QObject{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();
public slots:
    void slotNewConnection();
    void slotClientDisconnected();
    void slotServerRead();
    //void slotReadClient();
private:
    QTcpServer * mTcpServer;
    QList<QTcpSocket*> mTcpSocket;
    int server_status;
};
#endif // MYTCPSERVER_H
