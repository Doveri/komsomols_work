#ifndef FUNC_H
#define FUNC_H
#include <QByteArray>
#include <QString>
#include <QList>
#include <QStringList>
#include <QDebug>
#include "singleton.h"

QByteArray auth(QStringList str);
QByteArray reg(QStringList str);
QByteArray get_task(QStringList str);
QByteArray get_result(QStringList str);
QByteArray parsing(QString str);
QByteArray conn(QStringList str);

#endif // FUNC_H
