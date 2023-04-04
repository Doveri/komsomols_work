#include <QCoreApplication>
#include "consoleclient.h"
int main(int argc, char *argv[])
{
    SingClient::getInstance()->sendToServer("auth tyu 123");
    return 0;
}
