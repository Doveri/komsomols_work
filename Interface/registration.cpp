#include "registration.h"
#include "ui_registration.h"
#include <QMessageBox>
registration::registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registration)
{
    this->client = SingClient::getInstance();
    ui->setupUi(this);
    MW = parent;
    ui->pass->setEchoMode(QLineEdit::Password);
    //setWindowFlags(Qt::Window | Qt::CustomizeWindowHint);
}

registration::~registration()
{
    delete ui;
}


void registration::on_auth_clicked()
{
    login = ui->login->text();
    password = ui->pass->text();
    QString qauth = "auth " + login + " " + password;
    if (client->sendToServer(qauth) == "User successfully authorized!"){
        QMessageBox::information(this, "Уведомление", "Авторизация прошла успешно");
        hide();
        MW->show();
    } else if (i == false){
        i = true;
    }else {
        QMessageBox::warning(this, "Уведомление", "Такого пользователя не существует, попробуйте еще раз");
        i = false;
    }
}

void registration::on_reg_clicked()
{
    login = ui->login->text();
    password = ui->pass->text();
    QString qr = "reg " + login + " " + password;
    client->sendToServer(qr);
}


void registration::on_get_stats_clicked()
{
    login = ui->login->text();
    password = ui->pass->text();
//    QString qa = "auth " + login + " " + password;
//    client->sendToServer(qa);
//    qDebug() << qa;
    QString qs = "get_stat " + login + " " + password;
    qDebug() << qs;
    client->sendToServer(qs);
//    ui->stat->setText(client->TakeMessage());
}

void registration::on_Upload_clicked()
{
    ui->stat->setText(client->TakeMessage());
}
