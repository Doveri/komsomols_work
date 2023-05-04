#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    registration w;
    w.show();
    MainWindow q;
    q.show();
    return a.exec();
}
