/********************************************************************************
** Form generated from reading UI file 'taskswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKSWINDOW_H
#define UI_TASKSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tasksWindow
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *get_stats_1;
    QLabel *stats_2;
    QPushButton *FirstTask;
    QPushButton *ThirdTask;
    QPushButton *SecondTask;
    QLabel *stats_1;
    QPushButton *get_stats_2;
    QLabel *stats_3;
    QPushButton *get_stats_3;
    QPushButton *OutBut;

    void setupUi(QDialog *tasksWindow)
    {
        if (tasksWindow->objectName().isEmpty())
            tasksWindow->setObjectName("tasksWindow");
        tasksWindow->resize(1141, 500);
        layoutWidget = new QWidget(tasksWindow);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(130, 70, 881, 271));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        get_stats_1 = new QPushButton(layoutWidget);
        get_stats_1->setObjectName("get_stats_1");

        gridLayout->addWidget(get_stats_1, 1, 0, 1, 1);

        stats_2 = new QLabel(layoutWidget);
        stats_2->setObjectName("stats_2");

        gridLayout->addWidget(stats_2, 2, 1, 1, 1);

        FirstTask = new QPushButton(layoutWidget);
        FirstTask->setObjectName("FirstTask");

        gridLayout->addWidget(FirstTask, 0, 0, 1, 1);

        ThirdTask = new QPushButton(layoutWidget);
        ThirdTask->setObjectName("ThirdTask");

        gridLayout->addWidget(ThirdTask, 5, 0, 1, 1);

        SecondTask = new QPushButton(layoutWidget);
        SecondTask->setObjectName("SecondTask");

        gridLayout->addWidget(SecondTask, 0, 1, 1, 1);

        stats_1 = new QLabel(layoutWidget);
        stats_1->setObjectName("stats_1");

        gridLayout->addWidget(stats_1, 2, 0, 1, 1);

        get_stats_2 = new QPushButton(layoutWidget);
        get_stats_2->setObjectName("get_stats_2");

        gridLayout->addWidget(get_stats_2, 1, 1, 1, 1);

        stats_3 = new QLabel(layoutWidget);
        stats_3->setObjectName("stats_3");

        gridLayout->addWidget(stats_3, 7, 0, 1, 1);

        get_stats_3 = new QPushButton(layoutWidget);
        get_stats_3->setObjectName("get_stats_3");

        gridLayout->addWidget(get_stats_3, 6, 0, 1, 1);

        OutBut = new QPushButton(layoutWidget);
        OutBut->setObjectName("OutBut");

        gridLayout->addWidget(OutBut, 5, 1, 3, 1);


        retranslateUi(tasksWindow);

        QMetaObject::connectSlotsByName(tasksWindow);
    } // setupUi

    void retranslateUi(QDialog *tasksWindow)
    {
        tasksWindow->setWindowTitle(QCoreApplication::translate("tasksWindow", "Dialog", nullptr));
        get_stats_1->setText(QCoreApplication::translate("tasksWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \321\201\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\321\203 \320\277\320\276 1 \320\267\320\260\320\264\320\260\320\275\320\270\321\216", nullptr));
        stats_2->setText(QCoreApplication::translate("tasksWindow", "\320\235\320\265 \320\276\320\261\320\275\320\276\320\262\320\273\320\265\320\275\320\276", nullptr));
        FirstTask->setText(QCoreApplication::translate("tasksWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 1 \320\267\320\260\320\264\320\260\320\275\320\270\320\265", nullptr));
        ThirdTask->setText(QCoreApplication::translate("tasksWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 3 \320\267\320\260\320\264\320\260\320\275\320\270\320\265", nullptr));
        SecondTask->setText(QCoreApplication::translate("tasksWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 2 \320\267\320\260\320\264\320\260\320\275\320\270\320\265", nullptr));
        stats_1->setText(QCoreApplication::translate("tasksWindow", "\320\235\320\265 \320\276\320\261\320\275\320\276\320\262\320\273\320\265\320\275\320\276", nullptr));
        get_stats_2->setText(QCoreApplication::translate("tasksWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \321\201\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\321\203 \320\277\320\276 2 \320\267\320\260\320\264\320\260\320\275\320\270\321\216", nullptr));
        stats_3->setText(QCoreApplication::translate("tasksWindow", "\320\235\320\265 \320\276\320\261\320\275\320\276\320\262\320\273\320\265\320\275\320\276", nullptr));
        get_stats_3->setText(QCoreApplication::translate("tasksWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \321\201\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\321\203 \320\277\320\276 3 \320\267\320\260\320\264\320\260\320\275\320\270\321\216", nullptr));
        OutBut->setText(QCoreApplication::translate("tasksWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tasksWindow: public Ui_tasksWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKSWINDOW_H
