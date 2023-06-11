#ifndef TESTMYCLASS_H
#define TESTMYCLASS_H

#include "../function.h"

#include <QObject>
#include <QtTest>

class TestMyClass : public QObject
{
    Q_OBJECT

private slots:
    void testPruferCode_data();
    void testPruferCode();
    void testPruferDecode_data();
    void testPruferDecode();
};

#endif // TESTMYCLASS_H
