#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "registration.h"
#include "secondtask.h"
#include <QMainWindow>
#include "client/consoleclient.h"
#include "func.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    SingClient* client;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_FirstTask_clicked();
    void on_SecondTask_clicked();
    void on_ThirdTask_clicked();
    void on_OutBut_clicked();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    SecondTask *window;
};
#endif // MAINWINDOW_H
