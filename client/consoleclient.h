#ifndef CONSOLECLIENT_H
#define CONSOLECLIENT_H
#include <QTcpSocket>
#include <QDebug>
#include <QtNetwork>
#include <QCoreApplication>

class SingClient;

class SingClientDestroyer{
    private:
        SingClient * p_instance;
    public:
        ~SingClientDestroyer() { delete p_instance;}
        void initialize(SingClient * p){p_instance = p;};
};


class SingClient : public QObject{
    Q_OBJECT
private:
        static SingClient * p_instance;
        static SingClientDestroyer destroyer;
        QTcpSocket* socket;

    protected:
        SingClient(){
            socket = new QTcpSocket;
            socket->connectToHost("127.0.0.1", 33333);
            if(socket->waitForConnected(3000)){
                qDebug() << "Connected!";
            }
            else{
                qDebug() << "Not connected!";
            }
        }
        SingClient(const SingClient& ) = delete ;
        SingClient& operator = (SingClient &) = delete;
        ~SingClient() {socket->close();}
        friend class SingClientDestroyer;
        void readyRead();
    public:
        static SingClient* getInstance(){
            if (!p_instance){
                p_instance = new SingClient();
                destroyer.initialize(p_instance);
            }
            return p_instance;
        }
        bool sendToServer(QString msg){
        socket->write(msg.toUtf8());
        return true;
        };
};

#endif // CONSOLECLIENT_H
