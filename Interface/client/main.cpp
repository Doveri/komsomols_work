#include <QCoreApplication>
#include "consoleclient.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    SingClient::getInstance()->sendToServer("auth successss");
    return a.exec();
}
