#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    window = new SecondTask;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_FirstTask_clicked()
{
    window->setTaskNumber(1);
}

void MainWindow::on_SecondTask_clicked()
{
    window->setTaskNumber(2);
}

void MainWindow::on_ThirdTask_clicked()
{
    window->setTaskNumber(3);
}

void MainWindow::on_OutBut_clicked()
{
    close();
}
