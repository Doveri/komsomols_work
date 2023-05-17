#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->client = SingClient::getInstance();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_FirstTask_clicked()
{
    client->sendToServer("get task");
    ui->label->setText(client->sendToServer("showDB"));
}

void MainWindow::on_SecondTask_clicked()
{
    client->sendToServer("get task");
    ui->label_2->setText(client->sendToServer("showDB"));
}

void MainWindow::on_ThirdTask_clicked()
{
    client->sendToServer("get task");
    ui->label_3->setText(client->sendToServer("showDB"));
}

void MainWindow::on_OutBut_clicked()
{
    close();
}

