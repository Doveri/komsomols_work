#include "testmyclass.h"

void TestMyClass::testPruferCode_data()
{
    QTest::addColumn<QVector<QPair<int,int>>>("edges");
    QTest::addColumn<QVector<int>>("expected");

    QTest::newRow("test1") << QVector<QPair<int,int>>{{1,2},{1,7},{1,8},{2,6},{3,5},{4,5},{5,6},{5,9}}
                           << QVector<int>{5, 5, 1, 1, 2, 6, 5};

    QTest::newRow("test2") << QVector<QPair<int,int>>{{1,2},{1,7},{1,8},{2,6},{3,5},{4,5},{5,6},{5,9}}
                           << QVector<int>{5, 5, 1, 1, 2, 6, 5};
}

void TestMyClass::testPruferCode()
{
    QFETCH(QVector<QPair<int,int>>, edges);
    QFETCH(QVector<int>, expected);

    QCOMPARE(pruferCode(edges), expected);
}

void TestMyClass::testPruferDecode_data()
{
    QTest::addColumn<QVector<int>>("c");
    QTest::addColumn<QVector<QPair<int,int>>>("expected");

    QTest::newRow("test1") << QVector<int>{5, 5, 1, 1, 2, 6, 5}
                           << QVector<QPair<int,int>>{{1,2},{1,7},{1,8},{2,6},{3,5},{4,5},{5,6},{5,9}};

    QTest::newRow("test2") << QVector<int>{5, 5, 1, 1, 2, 6, 5}
                           << QVector<QPair<int,int>>{{1,2},{1,7},{1,8},{2,6},{3,5},{4,5},{5,6},{5,9}};
}

void TestMyClass::testPruferDecode()
{
    QFETCH(QVector<int>, c);
    QFETCH(QVector<QPair<int,int>>, expected);

    QCOMPARE(pruferDecode(c), expected);
}

QTEST_APPLESS_MAIN(TestMyClass)
#include "testmyclass.moc"
