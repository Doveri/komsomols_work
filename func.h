#ifndef FUNC_H
#define FUNC_H
#include <QByteArray>
#include <QString>
#include <QList>
#include <QStringList>
#include <QDebug>


QByteArray auth(QStringList str);
QByteArray reg(QStringList str);
QByteArray get_task(QStringList str);
QByteArray get_result(QStringList str);
QByteArray parsing(QString str);

#endif // FUNC_H
