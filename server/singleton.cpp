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
    bool success = query.exec("CREATE TABLE IF NOT EXISTS users ("
                              "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                              "login TEXT NOT NULL,"
                              "password TEXT NOT NULL,"
                              "rate INTEGER DEFAULT 0"
                              ");");

    if (!success) {
        qDebug() << "Error creating table 'users': " << query.lastError().text();
        db.close();
        return false;
    }

    // Проверяем, существует ли таблица "tasks"
    success = query.exec("CREATE TABLE IF NOT EXISTS tasks ("
                          "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                          "user_id INTEGER NOT NULL,"
                          "task_type INTEGER NOT NULL,"
                          "task_data TEXT NOT NULL,"
                          "answers TEXT,"
                          "FOREIGN KEY (user_id) REFERENCES users(id)"
                          ");");

    if (!success) {
        qDebug() << "Error creating table 'tasks': " << query.lastError().text();
        db.close();
        return false;
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
