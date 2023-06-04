/********************************************************************************
** Form generated from reading UI file 'registration.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_H
#define UI_REGISTRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_registration
{
public:
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *login;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *pass;
    QPushButton *pushButton;

    void setupUi(QDialog *registration)
    {
        if (registration->objectName().isEmpty())
            registration->setObjectName("registration");
        registration->resize(873, 434);
        groupBox = new QGroupBox(registration);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(220, 50, 331, 201));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        login = new QLineEdit(groupBox);
        login->setObjectName("login");

        horizontalLayout->addWidget(login);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        pass = new QLineEdit(groupBox);
        pass->setObjectName("pass");

        horizontalLayout_2->addWidget(pass);


        verticalLayout->addLayout(horizontalLayout_2);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);


        retranslateUi(registration);

        QMetaObject::connectSlotsByName(registration);
    } // setupUi

    void retranslateUi(QDialog *registration)
    {
        registration->setWindowTitle(QCoreApplication::translate("registration", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("registration", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        label->setText(QCoreApplication::translate("registration", "\320\230\320\274\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("registration", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        pushButton->setText(QCoreApplication::translate("registration", "\320\222\320\276\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registration: public Ui_registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
