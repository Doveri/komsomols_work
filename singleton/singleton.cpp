#include "singleton.h"

Singleton * Singleton::p_instance;
SingletonDestroyer Singleton::destroyer;

Singleton::Singleton() {
    db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("D:/workdir/komsomols_work/singleton/sqlite.db");
}

void SingletonDestroyer::initialize(Singleton * p) {
    p_instance = p;
}

bool Singleton::openDB() {
    if (!db.open()){
        qDebug() << "Failed to connect to database :(";
        return false;
    }
    return true;
}

QString Singleton::query(QString qw) {
    if (!openDB()) {
            qDebug() << "Failed to open database :(";
            return "uwu";
        }

        QSqlQuery sqlQuery(db);
        if (!sqlQuery.exec(qw)) {
            qDebug() << "Failed to execute query: ";
            return "uwu";
        }

        while (sqlQuery.next()) {
            QString name = sqlQuery.value(0).toString();
            int salary = sqlQuery.value(1).toInt();
            qDebug() << name << salary;
        }
        QString result = "This is your lovely data :*";
        return result;
}


