#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->client = SingClient::getInstance();
    ui->setupUi(this);
    RW = new registration(this);
    RW->show();
    TW = new tasksWindow;
    TW->hide();
    //setWindowFlags(Qt::Window | Qt::CustomizeWindowHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_FirstTask_clicked()
{
    QString qs = "get_task " + RW->login + " " + RW->password + " 1";
    client->sendToServer(qs);

}


void MainWindow::on_get_stats_1_clicked()
{
    QString qs = "get_stat " + RW->login + " " + RW->password;
    client->sendToServer(qs);
}


void MainWindow::on_update1_clicked()
{

    ui->one->setText(client->TakeMessage());
}


void MainWindow::on_SecondTask_clicked()
{
    QString qs = "get_task " + RW->login + " " + RW->password + " 2";
    client->sendToServer(qs);
}


void MainWindow::on_get_stats_2_clicked()
{
    QString qs = "get_stat " + RW->login + " " + RW->password;
    client->sendToServer(qs);
}


void MainWindow::on_update2_clicked()
{
    ui->two->setText(client->TakeMessage());
}


void MainWindow::on_ThirdTask_clicked()
{
    QString qs = "get_task " + RW->login + " " + RW->password + " 3";
    client->sendToServer(qs);
}


void MainWindow::on_get_stats_3_clicked()
{
    QString qs = "get_stat " + RW->login + " " + RW->password;
    client->sendToServer(qs);
}


void MainWindow::on_update3_clicked()
{
    ui->three->setText(client->TakeMessage());
}


void MainWindow::on_OutBut_clicked()
{
    close();
}

