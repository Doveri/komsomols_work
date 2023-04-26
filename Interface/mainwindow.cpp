#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    window = new SecondWindow(this);
    window->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    close();
}


void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::warning(this, "Внимание", "Ошибка");
}


void MainWindow::on_pushButton_4_clicked()
{
    QMessageBox::information(this, "Внимание", "Ошибка");
}

