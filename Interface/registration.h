#ifndef REGISTRATION_H
#define REGISTRATION_H
#include "consoleclientt.h"
#include <QDialog>

namespace Ui {
class registration;
}

class registration : public QDialog
{
    Q_OBJECT

public:
    SingClient* client;
    QString login;
    QString password;
    explicit registration(QWidget *parent = nullptr);

    ~registration();

private slots:
    void on_auth_clicked();

    void on_reg_clicked();

    void on_get_stats_clicked();

    void on_Upload_clicked();

private:
    bool i = false;
    Ui::registration *ui;
    QWidget* MW;
};

#endif // REGISTRATION_H
