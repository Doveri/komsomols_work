/********************************************************************************
** Form generated from reading UI file 'secondtask.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDTASK_H
#define UI_SECONDTASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SecondTask
{
public:
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *SendAns;

    void setupUi(QDialog *SecondTask)
    {
        if (SecondTask->objectName().isEmpty())
            SecondTask->setObjectName("SecondTask");
        SecondTask->resize(797, 363);
        horizontalLayout = new QHBoxLayout(SecondTask);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(SecondTask);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(SecondTask);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout_2->addWidget(lineEdit);


        horizontalLayout->addLayout(horizontalLayout_2);

        SendAns = new QPushButton(SecondTask);
        SendAns->setObjectName("SendAns");

        horizontalLayout->addWidget(SendAns);


        retranslateUi(SecondTask);

        QMetaObject::connectSlotsByName(SecondTask);
    } // setupUi

    void retranslateUi(QDialog *SecondTask)
    {
        SecondTask->setWindowTitle(QCoreApplication::translate("SecondTask", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("SecondTask", "\320\222\320\260\321\210\320\265 \320\267\320\260\320\264\320\260\320\275\320\270\320\265:", nullptr));
        lineEdit->setText(QCoreApplication::translate("SecondTask", "\320\222\320\260\321\210 \320\276\321\202\320\262\320\265\321\202...", nullptr));
        SendAns->setText(QCoreApplication::translate("SecondTask", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\264\320\260\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecondTask: public Ui_SecondTask {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDTASK_H
