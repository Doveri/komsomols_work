/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *Name;
    QLineEdit *login;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Surname;
    QLineEdit *pass;
    QLabel *pppp;
    QVBoxLayout *verticalLayout_3;
    QPushButton *auth;
    QPushButton *reg;
    QPushButton *get_stats;
    QLabel *stat;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(730, 365);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(-1, 0, -1, -1);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(-1, 0, -1, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        Name = new QLabel(centralwidget);
        Name->setObjectName("Name");

        horizontalLayout->addWidget(Name);

        login = new QLineEdit(centralwidget);
        login->setObjectName("login");

        horizontalLayout->addWidget(login);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        Surname = new QLabel(centralwidget);
        Surname->setObjectName("Surname");

        horizontalLayout_2->addWidget(Surname);

        pass = new QLineEdit(centralwidget);
        pass->setObjectName("pass");

        horizontalLayout_2->addWidget(pass);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_2);

        pppp = new QLabel(centralwidget);
        pppp->setObjectName("pppp");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pppp->sizePolicy().hasHeightForWidth());
        pppp->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(pppp);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(-1, 0, -1, -1);
        auth = new QPushButton(centralwidget);
        auth->setObjectName("auth");

        verticalLayout_3->addWidget(auth);

        reg = new QPushButton(centralwidget);
        reg->setObjectName("reg");

        verticalLayout_3->addWidget(reg);

        get_stats = new QPushButton(centralwidget);
        get_stats->setObjectName("get_stats");

        verticalLayout_3->addWidget(get_stats);

        stat = new QLabel(centralwidget);
        stat->setObjectName("stat");
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(stat->sizePolicy().hasHeightForWidth());
        stat->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(stat);


        verticalLayout_4->addLayout(verticalLayout_3);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 730, 29));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Name->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217", nullptr));
        Surname->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        pppp->setText(QString());
        auth->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        reg->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        get_stats->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \321\201\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\321\203", nullptr));
        stat->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
