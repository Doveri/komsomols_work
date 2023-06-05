#ifndef FUNCTION_H
#define FUNCTION_H

#include <QSqlQuery>
#include <QSqlError>
#include <QVector>
#include <QPair>
#include <QHash>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <utility>
#include <sstream>
#include <string>


#include "singleton.h"


// Define edge structure for Kruskal's algorithm
struct Edge {
    int u, v, weight;
};
bool cmp(Edge a, Edge b);
int findParent(int v, QVector<int>& parent);
void join(int u, int v, QVector<int>& parent);
QVector<Edge> findLowestWeightedFrame(int n, QVector<Edge>& edges);

std::vector<std::pair<int, int>> getRandomStdEdges();
std::vector<int> pruferCodeFromStdEdges(std::vector<std::pair<int, int>> edges);
QString parsing(QString request);
bool registerUser(QString login, QString password);
bool authUser(QString login, QString password);
bool cleanDatabase();
QStringList getStat();
QStringList getUsers();
QVector<int> pruferCodeFromEdges(QVector<QPair<int,int>> edges);
QVector<QPair<int,int>> pruferDecode(QVector<int> c);
QVector<QPair<int, int>> getRandomEdges();
QVector<int> getRandomPruferCode();
QString get_task3(QString login, QString password);
QString get_task4(QString login, QString password);
int getUserId(QString login);
void addTaskToDatabase(QString login, QVector<QPair<int, int>> edges, QVector<int> pruferCode, int taskType);
QString edgesToString(QVector<QPair<int, int>> edges);
QString pruferCodeToString(QVector<int> pruferCode);
bool checkAnswer(QString login, QString password, int taskType, QString userAnswer);
int checkRating(QString login, QString password);

#endif // FUNCTION_H

//Эти файлы реализуют следующие функции:

//parsing - разбор запроса и выполнение соответствующих действий (регистрация, авторизация, получение пользователей)
//registerUser - регистрация нового пользователя в БД
//authUser - авторизация пользователя
//getUsers - получение списка пользователей для авторизованного пользователя
//Для удобства работы с БД используется singleton.

//Эти функции позволяют реализовать основную бизнес-логику сервера - регистрацию и авторизацию пользователей, получение данных из БД.
