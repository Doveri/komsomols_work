#include "mainwindow.h"

#include <QApplication>
#include <QThread>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow q;
    //q.resize(400, 200);
    //q.show();
    return a.exec();
}
