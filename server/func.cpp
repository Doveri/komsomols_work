#include "func.h"
#include <QDebug>
#include "singleton.h"

QByteArray auth(QStringList str){
    QByteArray stub;
    stub.append("nAuthorization was successful!");
    return stub;
}

QByteArray reg(QStringList str) {
    QByteArray stub;
    stub.append("Registration was successful!");
    return stub;
}

QByteArray get_task(QStringList str){
    QByteArray stub;
    stub.append("Task: no task, holydays!!!");
    return stub;
}

QByteArray get_result(QStringList str){
    QByteArray stub;
    stub.append("Results: no resuts, holydays!!!");
    return stub;
}

QByteArray showDB(QStringList str){
    QByteArray stub;
    if (!Singleton::getInstance()->connect("D:/workdir/komsomols_work/singleton/sqlite.db"))
        stub.append("Failed to connect to database :(");
    else
        stub.append(Singleton::getInstance()->query("SELECT * FROM demo;").toUtf8());
    return stub;
}

QByteArray parsing(QString func_name){
    QStringList met = func_name.split(' ');
    if(func_name=="auth")
        return auth(met);
    else if (func_name == "reg")
        return reg(met);
    else if (func_name == "get task")
        return get_task(met);
    else if (func_name == "get results")
        return get_result(met);
    else if (func_name == "showDB")
        return showDB(met);
    else
        return "Incorrect command...";
}

