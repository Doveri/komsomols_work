#include <QCoreApplication>
#include "singleton.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<Singleton::getInstance()->query("SELECT * FROM demo;");

    return a.exec();
}
