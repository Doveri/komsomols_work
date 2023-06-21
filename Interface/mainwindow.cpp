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

    QString message = client->TakeMessage();
    int maxCharsPerLine = 67;
    for (int i = 0; i < message.size(); i += maxCharsPerLine) {
        message.insert(i, "\n");
    }
    ui->one->setText(message);
    ui->one->setAlignment(Qt::AlignTop | Qt::AlignLeft);
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
    QString message = client->TakeMessage();
    int maxCharsPerLine = 67;
    for (int i = 0; i < message.size(); i += maxCharsPerLine) {
        message.insert(i, "\n");
    }
    ui->two->setText(message);
    ui->two->setAlignment(Qt::AlignTop | Qt::AlignLeft);
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
    QString message = client->TakeMessage();
    int maxCharsPerLine = 67;
    for (int i = 0; i < message.size(); i += maxCharsPerLine) {
        message.insert(i, "\n");
    }
    ui->three->setText(message);
    ui->three->setAlignment(Qt::AlignTop | Qt::AlignLeft);
}


void MainWindow::on_OutBut_clicked()
{
    close();
}


void MainWindow::on_ans1_clicked()
{
    client->sendToServer("check_answer " + RW->login + " " + RW->password + " 1 " + ui->ansOne->text());
    qDebug() << "-----1-------";
}


void MainWindow::on_ans2_clicked()
{
    client->sendToServer("check_answer " + RW->login + " " + RW->password + " 2 " + ui->ansTwo->text());
    qDebug() << "-----2-------";
}


void MainWindow::on_ans3_clicked()
{
    client->sendToServer("check_answer " + RW->login + " " + RW->password + " 3 " + ui->ansThree->text());
    qDebug() << "-----3-------";
}

