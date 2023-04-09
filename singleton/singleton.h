#ifndef SINGLETON_H
#define SINGLETON_H
#include <QSqlDataBase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QDebug>
#include <QtCore>
class Singleton;

class SingletonDestroyer
{
    private:
        Singleton * p_instance;
    public:
        ~SingletonDestroyer(){delete p_instance;};
        void initialize(Singleton * p);
};


class Singleton
{
    private:
        static Singleton * p_instance;
        static SingletonDestroyer destroyer;
        QSqlDatabase db;
    protected:
        Singleton();
        Singleton(const Singleton& );
        Singleton& operator = (Singleton &);
        ~Singleton();
        friend class SingletonDestroyer;
    public:
        static Singleton* getInstance(){
            if (!p_instance)
            {
                p_instance = new Singleton();
                destroyer.initialize(p_instance);
            }
            return p_instance;
        }

        QString query(QString query);
        bool openDB();
};


#endif // SINGLETON_H
