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

        QString result = "This is your lovely data :*";
        while (sqlQuery.next()) {
            for(int i=0;i<sqlQuery.record().count();i++)
                result.append(sqlQuery.value(i).toString()).append("|");
            result.append("\n");
        }
        qDebug()<<result;

        return result;
}

