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
        qDebug() << login;
        MW->show();
    } else {
    QMessageBox::warning(this, "Уведомление", "Вы не авторизировались, попробуйте еще раз");
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
    QString message = client->TakeMessage();
    int maxCharsPerLine = 67;
    for (int i = 0; i < message.size(); i += maxCharsPerLine) {
        message.insert(i, "\n");
    }
    ui->stat->setText(message);
    ui->stat->setAlignment(Qt::AlignTop | Qt::AlignLeft);
}
