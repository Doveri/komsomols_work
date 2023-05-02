#ifndef CONSOLECLIENT_H
#define CONSOLECLIENT_H

#include <QTcpSocket>
#include <QDebug>
#include <QtNetwork>
#include <QObject>

class SingClient;

class SingClientDestroyer{
    private:
        SingClient * p_instance;
    public:
        ~SingClientDestroyer() { delete p_instance;}
        void initialize(SingClient * p){p_instance = p;}
};


class SingClient : public QObject
{
    Q_OBJECT
private:
        static SingClient * p_instance;
        static SingClientDestroyer destroyer;
        QTcpSocket* socket;

    protected:
        explicit SingClient();
        SingClient(const SingClient& ) = delete ;
        SingClient& operator = (SingClient &) = delete;
        ~SingClient();
        friend class SingClientDestroyer;
    public:
        static SingClient* getInstance();
        bool sendToServer(QString);
    protected slots:
        void slot_readFromServer();
    signals:
};

#endif // CONSOLECLIENT_H
