#include "consoleclient.h"

SingClient * SingClient::p_instance;
SingClientDestroyer SingClient::destroyer;

void SingClient::readyRead(){
    socket->connectToHost("127.0.0.1", 33333);
    if (socket->waitForConnected(3000)) {
        socket->write("Hello, server!");
        socket->waitForBytesWritten();
    }
}
