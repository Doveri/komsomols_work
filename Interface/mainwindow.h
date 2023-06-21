#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "consoleclientt.h"
#include "registration.h"
#include "taskswindow.h"
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

    void on_get_stats_1_clicked();

    void on_update1_clicked();

    void on_SecondTask_clicked();

    void on_get_stats_2_clicked();

    void on_update2_clicked();

    void on_ThirdTask_clicked();

    void on_get_stats_3_clicked();

    void on_update3_clicked();

    void on_OutBut_clicked();

    void on_ans1_clicked();

    void on_ans2_clicked();

    void on_ans3_clicked();

private:
    Ui::MainWindow *ui;
    registration* RW;
    tasksWindow* TW;

};
#endif // MAINWINDOW_H
