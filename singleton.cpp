#include "singleton.h"

// Это реализация паттерна Singleton, который гарантирует, что у нас будет только один экземпляр класса
Singleton& Singleton::getInstance()
{
    // Создаем статический объект instance при первом вызове getInstance()
    static Singleton instance;
    return instance;
}

// Метод для соединения с базой данных
bool Singleton::connectToDB()
{
    // добавляем драйвер базы данных и задаем имя базы данных
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./database.db");

    // проверяем, удалось ли открыть базу данных
    if (!db.open()) {
        qDebug() << "Database not connected!";
        qDebug() << db.lastError().text();
        return false;
    }

    // Проверяем, существует ли таблица "users"
    QSqlQuery query(db);
    bool success = query.exec("SELECT name FROM sqlite_master WHERE type='table' AND name='users';");

    if (!success) {
        qDebug() << "Error checking for table: " << query.lastError().text();
        db.close();
        return false;
    }

    if (query.next()) {
        qDebug() << "Table 'users' already exists.";
    } else {
        qDebug() << "Table 'users' does not exist. Creating...";
        success = query.exec("CREATE TABLE users ("
                             "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                             "login TEXT NOT NULL,"
                             "password TEXT NOT NULL"
                             ");");

        if (!success) {
            qDebug() << "Error creating table: " << query.lastError().text();
            db.close();
            return false;
        }
    }

    qDebug() << "Database connected!";
    return true;
}

// Метод для закрытия соединения с базой данных
void Singleton::close()
{
    db.close();
    qDebug() << "Connection to database closed!";
}

// Конструктор класса Singleton
Singleton::Singleton() {}

// Закрываем конструктор копирования и оператор присваивания, чтобы не создавать дубликаты объектов
Singleton::Singleton(Singleton const&)  {}

void Singleton::operator=(Singleton const&)  {}
