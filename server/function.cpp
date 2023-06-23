#include "function.h"

// Метод для обработки запросов
QString parsing(QString request)
{
    // Распарсиваем запрос на команду и параметры
    QStringList parts = request.split(" ");
    QString command = parts[0];
    QString response = "";
    // Обрабатываем различные команды
    if (command == "reg" && parts.size() == 3) {
        // Получаем логин и пароль пользователя из параметров команды
        QString login = parts[1];
        QString password = parts[2];

        // Регистрируем пользователя в базе данных и отправляем ответ клиенту
        if (registerUser(login, password)) {
            response = "User successfully registered!";
        } else {
            response = "Error registering user!";
        }
    } else if (command == "auth" && parts.size() == 3) {
        // Получаем логин и пароль пользователя из параметров команды
        QString login = parts[1];
        QString password = parts[2];

        // Авторизуем пользователя и отправляем ответ клиенту
        if (authUser(login, password)) {
            response = "User successfully authorized!";
        } else {
            response = "Error authorizing user!";
        }
    } else if (command == "get_users" && parts.size() == 3) {
        // Получаем логин и пароль пользователя из параметров команды
        QString login = parts[1];
        QString password = parts[2];

        // Если пользователь авторизован, получаем список всех пользователей и отправляем его клиенту
        if (authUser(login, password)) {
            QStringList users = getUsers();
            response = "Users: " + users.join(", ");
        } else {
            response = "You are not authorized!";
        }
    } else if (command == "get_stat" && parts.size() == 3) {
        // Получаем логин и пароль пользователя из параметров команды
        QString login = parts[1];
        QString password = parts[2];

        // Если пользователь авторизован, получаем статистику и отправляем ее клиенту
        if (authUser(login, password)) {
            QStringList stat = getStat();
            response = "Stat: " + stat.join(", ");
        } else {
            response = "You are not authorized!";
        }
    } else if (command == "clean_db") {
        // Очищаем базу данных и отправляем ответ клиенту
        if (cleanDatabase()) {
            response = "Database cleaned successfully!";
        } else {
            response = "Error cleaning database!";
        }
    } else if (command == "get_task" && parts[1] == "1" && parts.size() == 4) {
        // Получаем логин и пароль пользователя из параметров команды
        QString login = parts[2];
        QString password = parts[3];

        // Если пользователь авторизован, получаем случайные ребра, генерируем код Прюфера и отправляем их клиенту
        if (authUser(login, password)) {
            //            QVector<QPair<int, int>> edges = getRandomEdges();
            //            QVector<QPair<int, int>> testEdges = {{1, 2}, {1, 7}, {1, 8}, {2, 6}, {3, 5}, {4, 5}, {5, 6}, {5, 9}};
            //            QVector<int> pruferCodeTest = pruferCodeFromEdges(testEdges);
            //            QString pruferCodeTestString = pruferCodeToString(pruferCodeTest);
            //            qDebug() << pruferCodeTestString;
            QVector<QPair<int, int>> edges;

            std::vector<std::pair<int, int>> stdEdges = getRandomStdEdges();
            std::vector<int> stdPruferCode = pruferCodeFromStdEdges(stdEdges);
            QVector<int> pruferCode(stdPruferCode.begin(), stdPruferCode.end());
            for (const auto& edge : stdEdges)
            {
                edges.append(QPair<int, int>(edge.first, edge.second));

            }
            // Формируем строку с ребрами
            //QString edgeString = edgesToString(edges);
            std::stringstream ss;
            ss << "[";
            for (const auto& edge : stdEdges)
            {
                ss << "(" << edge.first << ", " << edge.second << "), ";
            }
            ss.seekp(-2, std::ios_base::end); // remove the last ", "
            ss << "]";

            std::string stdEdgeString = ss.str();
            QString edgeString = QString::fromStdString(stdEdgeString);

            // Получаем ответ на таск
            qDebug() << "get_random code";

            //QVector<int> pruferCode = pruferCodeFromEdges(edges);
            // Добавляем данные в базу данных
            addTaskToDatabase(login, edges, pruferCode, 1);

            // Формируем ответ сервера
            response = "Edges: " + edgeString;
        } else {
            response = "You are not authorized!";
        }
    } else if (command == "get_task" && parts[1] == "2" && parts.size() == 4) {
        // Получаем логин и пароль пользователя из параметров команды
        QString login = parts[2];
        QString password = parts[3];

        // Если пользователь авторизован, добавляем задачу в таблицу tasks с task_type = 2
        if (authUser(login, password)) {
            // Генерируем случайный код Прюфера
            QVector<int> pruferCode = getRandomPruferCode();

            // Декодируем код Прюфера
            QVector<QPair<int, int>> edges = pruferDecode(pruferCode);
            // Преобразуем вектор кода Прюфера в строку
            QString pruferCodeString = pruferCodeToString(pruferCode);

            // Добавляем задачу в таблицу tasks with Prufer code as task data and decoded edges as answers
            addTaskToDatabase(login, edges, pruferCode, 2);

            // Формируем ответ сервера в формате "Prufer code: x1 x2 x3 ..."
            response = "Prufer code: " + pruferCodeString;
        } else {
            response = "You are not authorized!";
        }
    } else if (command == "get_task" && parts[1] == "3" && parts.size() == 4) {
        // Получаем логин и пароль пользователя из параметров команды
        QString login = parts[2];
        QString password = parts[3];

        // Если пользователь авторизован, вызываем функцию get_task3() и отправляем ее результат клиенту
        if (authUser(login, password)) {
            QString task3 = get_task3(login, password);
            response = task3;
        } else {
            response = "You are not authorized!";
        }
    } else if (command == "get_task" && parts[1] == "4" && parts.size() == 4) {
        // Получаем логин и пароль пользователя из параметров команды
        QString login = parts[2];
        QString password = parts[3];

        // Если пользователь авторизован, вызываем функцию get_task4() и отправляем ее результат клиенту
        if (authUser(login, password)) {
            QString task4 = get_task4(login, password);
            response = task4;
        } else {
            response = "You are not authorized!";
        }
    } else if (command == "check_answer" && parts.size() == 5) {
        //check answer
        QString login = parts[1];
        QString password = parts[2];
        QString userAnswer = parts[4];
        if (checkAnswer(userAnswer) && authUser(login, password)) {
            response = "Answer is correct!";
        } else {
            response = "Answer is incorrect!";
        }
    } else if (command == "check_rating" && parts.size() == 3) {
        QString login = parts[1];
        QString password = parts[2];
        int rating = checkRating(login, password);
        if (rating != -1) {
            response = "User rating is: " + QString::number(rating);
        } else {
            response = "Failed to retrieve user rating.";
        }
    } else {
        response = "Unknown command!";
    }

    return response;
}


bool checkAnswer(QString userAnswer)
{
    // Получаем объект класса Singleton для работы с базой данных
    Singleton& db = Singleton::getInstance();
    bool answer = false;
    // Подготавливаем запрос на поиск пользователя в базе данных
    QSqlQuery q(db.db);
    if (q.exec("SELECT * FROM tasks;"))
    {
        while (q.next()) // Iterate over the result set
        {
            // Get the values of each column and append them to the QStringList
            QString answers = q.value(4).toString();
            answers.remove(" ");
            answers.remove(",");
            if (answers == userAnswer){
                answer = true;
            }
        }
    }
    return answer;
}

int checkRating(QString login, QString password)
{
    // Получаем объект класса Singleton для работы с базой данных
    Singleton& db = Singleton::getInstance();

    // Подготавливаем запрос на поиск пользователя в базе данных
    QSqlQuery q(db.db);
    q.prepare("SELECT rate FROM users WHERE login = :login AND password = :password");
    q.bindValue(":login", login);
    q.bindValue(":password", password);

    // Выполняем запрос и проверяем его результат
    if (q.exec() && q.first()) {
        int rating = q.value(0).toInt();
        return rating;
    } else {
        return -1; // Return -1 to indicate failure
    }
}

void addTaskToDatabase(QString login, QVector<QPair<int, int>> edges, QVector<int> pruferCode, int taskType) {
    // Получаем объект класса Singleton для работы с базой данных
    Singleton& db = Singleton::getInstance();

    // Преобразуем вектор ребер в строку
    QString edgeString = edgesToString(edges);

    // Преобразуем вектор кода Прюфера в строку
    QString pruferCodeString = pruferCodeToString(pruferCode);

    // Добавляем задачу в таблицу tasks
    QSqlQuery q(db.db);
    q.prepare("INSERT INTO tasks (user_id, task_type, task_data, answers) VALUES (:user_id, :task_type, :task_data, :answers);");
    q.bindValue(":user_id", getUserId(login));
    q.bindValue(":task_type", taskType);

    if (taskType == 1) {
        // Добавляем сгенерированный список ребер в качестве task_data
        q.bindValue(":task_data", edgeString);

        // Добавляем сгенерированный код Прюфера в качестве answers
        q.bindValue(":answers", pruferCodeString);
    } else if (taskType == 2) {
        // Добавляем сгенерированный код Прюфера в качестве task_data
        q.bindValue(":task_data", pruferCodeString);

        // Добавляем декодированный список ребер в качестве answers
        q.bindValue(":answers", edgeString);
    }

    bool success = q.exec();
    if (success) {
        qDebug() << "Task added to database!";
    } else {
        qDebug() << "Error adding task to database: " << q.lastError().text();
    }
}

int getUserId(QString login) {
    Singleton& db = Singleton::getInstance();
    QSqlQuery q(db.db);
    q.prepare("SELECT id FROM users WHERE login = :login");
    q.bindValue(":login", login);
    if (q.exec() && q.next()) {
        return q.value(0).toInt();
    } else {
        return -1; // если пользователь не найден
    }
}

// Метод для регистрации нового пользователя в базе данных
bool registerUser(QString login, QString password)
{
    // Получаем объект класса Singleton для работы с базой данных
    Singleton& db = Singleton::getInstance();

    // Подготавливаем запрос на добавление пользователя в базу данных
    QSqlQuery q(db.db);
    q.prepare("INSERT INTO users (login, password) VALUES (:login, :password)");
    q.bindValue(":login", login);
    q.bindValue(":password", password);

    // Выполняем запрос и проверяем его результат
    if (!q.exec()) {
        qDebug() << "Error registering user!";
        qDebug() << q.lastError().text();
        return false;
    }

    return true;
}

// Метод для авторизации пользователя в базе данных
bool authUser(QString login, QString password)
{
    // Получаем объект класса Singleton для работы с базой данных
    Singleton& db = Singleton::getInstance();

    // Подготавливаем запрос на поиск пользователя в базе данных
    QSqlQuery q(db.db);
    q.prepare("SELECT * FROM users WHERE login = :login AND password = :password");
    q.bindValue(":login", login);
    q.bindValue(":password", password);

    // Выполняем запрос и проверяем его результат
    if (q.exec() && q.first()) {
        return true;
    }
    return false;
}

// Метод для получения списка всех пользователей из базы данных
QStringList getUsers()
{
    // Получаем объект класса Singleton для работы с базой данных
    Singleton& db = Singleton::getInstance();

    // Подготавливаем запрос на выборку всех пользователей из базы данных
    QSqlQuery q(db.db);
    QStringList users;
    if (!q.exec("SELECT login FROM users")) {
        qDebug() << "Error selecting users!";
        qDebug() << q.lastError().text();
    }

    // Получаем список всех пользователей из результата запроса
    while (q.next()) {
        users.append(q.value(0).toString());
    }

    return users;
}

// Метод для получения статистики из базы данных
QStringList getStat()
{
    QStringList values;
    Singleton& db = Singleton::getInstance();
    QSqlQuery q(db.db);

    if (q.exec("SELECT * FROM tasks;")) // Execute the SQL statement
    {
        while (q.next()) // Iterate over the result set
        {
            // Get the values of each column and append them to the QStringList
            QString id = q.value(0).toString();
            QString user_id = q.value(1).toString();
            QString task_type = q.value(2).toString();
            QString task_data = q.value(3).toString();
            QString answers = q.value(4).toString();

            values.append("ID:" + id + "| " + "user_id:" + user_id + "| " + "task_type:" + task_type + "| " + "task_data" + task_data + "| " + "answers" + answers);
        }
    }

    return values;
}

// Метод для очистки базы данных
bool cleanDatabase()
{
    // Получаем объект класса Singleton для работы с базой данных
    Singleton& db = Singleton::getInstance();

    // Подготавливаем запрос на удаление всех пользователей из базы данных
    QSqlQuery q(db.db);
    if (!q.exec("DELETE FROM users") || !q.exec("DELETE FROM tasks")) {
        qDebug() << "Error cleaning database!";
        qDebug() << q.lastError().text();
        return false;
    }
    return true;
}



QVector<QPair<int, int>> getRandomEdges() {
    QVector<QPair<int, int>> randomEdges;
    for (int i = 0; i < 8; i++) {
        int startNode = 0;
        int endNode = 0;
        while (startNode == endNode) {
            startNode = 1 + rand() % 9;
            endNode = 1 + rand() % 9;
        }
        randomEdges.push_back({startNode, endNode});
    }
    QString edgesString = edgesToString(randomEdges);
    qDebug() << edgesString;
    return randomEdges;
}




QVector<int> getRandomPruferCode()
{
    QVector<int> pruferCode;

    for (int i = 0; i < 7; i++)
    {
        int num = rand() % 10;
        pruferCode.append(num);
    }

    return pruferCode;
}


QVector<int> pruferCodeFromEdges(QVector<QPair<int,int>> edges)
{
    QVector<int> pruf_code;
    while (edges.size() > 1)
    {
        QHash <int, int> counts;
        for (const auto &edge :edges)
        {
            counts[edge.first]++;
            counts[edge.second]++;
        }
        QVector<int> leaf;
        for (auto it = counts.begin(); it != counts.end(); ++it) {
            int number = it.key();
            int count = it.value();
            if (count == 1) {
                leaf.push_back(number);
            }
        }
        int min_leaf = *std::min_element(leaf.constBegin(), leaf.constEnd());

        int index_to_remove = -1;
        for (int i = 0; i < edges.size(); i++)
        {
            if (edges[i].first == min_leaf)
            {
                pruf_code.push_back(edges[i].second);
                index_to_remove = i;
                break;
            }
            if (edges[i].second == min_leaf)
            {
                pruf_code.push_back(edges[i].first);
                index_to_remove = i;
                break;
            }
        }
        if (index_to_remove != -1)
        {
            edges.erase(edges.begin() + index_to_remove);
        }

    }

    return pruf_code;
}

std::vector<std::pair<int, int>> getRandomStdEdges() {
    std::vector<std::pair<int, int>> edges; // массив для хранения пар вершин
    // Создаем генератор случайных чисел
    std::random_device rd;
    std::mt19937 g(rd());

    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // массив с номерами вершин

    std::shuffle(nums.begin(), nums.end(), g); // перемешиваем номера вершин

    // Заполняем массив пар вершин
    for (int i = 0; i < 7; ++i) {
        int a = nums[i];
        int b = nums[i + 1];
        // Проверяем, что текущая пара вершин не повторяется и не похожа на уже добавленные.
        while (a == b || std::find_if(edges.begin(), edges.end(), [&](const auto& e) {
                                      return (e.first == a && e.second == b) || (e.first == b && e.second == a);
    }) != edges.end()) {
            std::shuffle(nums.begin(), nums.end(), g); // перемешиваем номера вершин
            a = nums[i];
            b = nums[i + 1];
        }
        edges.emplace_back(a, b); // добавляем новую пару вершин в массив
    }
    return edges;
}

std::vector<int> pruferCodeFromStdEdges(std::vector<std::pair<int, int>> edges)
{
    // Создаём пустой вектор `pruf_code`, который будет хранить код Прюфера.
    std::vector<int> pruf_code;

    // Запускаем цикл while, который будет выполняться до тех пор,
    // пока в векторе `edges` не останется только одна пара.
    while (edges.size() > 1)
    {
        // Создаём хеш-таблицу `counts`, которая будет содержать
        // количество вхождений каждого числа в `edges`.
        std::unordered_map<int, int> counts;
        for (const auto &edge : edges)
        {
            counts[edge.first]++;
            counts[edge.second]++;
        }

        // Создаём пустой вектор `leaf`, в который добавляются все уникальные числа из `counts`,
        // которые встречаются только один раз в `edges`.
        std::vector<int> leaf;
        for (const auto &[number, count] : counts)
        {
            if (count == 1)
            {
                leaf.push_back(number);
            }
        }

        // Находим минимальное число в векторе `leaf` с помощью функции `min_element`.
        int min_leaf = *min_element(leaf.begin(), leaf.end());

        // Находим пару в `edges`, в которой содержится минимальное число, и добавляем в `pruf_code` сосед этого числа.
        int index_to_remove = -1;
        for (int i = 0; i < edges.size(); i++)
        {
            if (edges[i].first == min_leaf)
            {
                pruf_code.push_back(edges[i].second);
                index_to_remove = i;
                break;
            }
            if (edges[i].second == min_leaf)
            {
                pruf_code.push_back(edges[i].first);
                index_to_remove = i;
                break;
            }
        }

        // Пара, найденная на предыдущем шаге, удаляется из `edges`.
        if (index_to_remove != -1)
        {
            edges.erase(edges.begin() + index_to_remove);
        }
    }

    // Функция возвращает вектор `pruf_code`.
    return pruf_code;
}

QVector<QPair<int,int>> pruferDecode(QVector<int> c)
{
    QVector<QPair<int,int>> nodes;

    QVector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    while (!c.empty())
    {
        QVector<int> remain_elements;
        int min_element;
        for (int i = 0; i < v.size(); i++)
        {
            // Если элемент не найден в векторе `c`, добавляем его в `remain_elements`.
            if (std::find(c.begin(), c.end(), v[i]) == c.end())
            {
                remain_elements.push_back(v[i]);
            }
        }
        int min_index = remain_elements.indexOf(*std::min_element(remain_elements.begin(), remain_elements.end()));
        min_element = remain_elements[min_index];

        int first_c_element = c.front();
        nodes.push_back(qMakePair(min_element, first_c_element));
        c.removeFirst();
        v.remove(min_index);
        remain_elements.clear();
    }
    nodes.push_back({v[0], v[1]});

    return nodes;
}

// Define comparison function for sorting edges by weight
bool cmp(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Function to find parent of vertex
int findParent(int v, QVector<int>& parent) {
    if (v == parent[v]) return v;
    return parent[v] = findParent(parent[v], parent);
}

// Function to join two components
void join(int u, int v, QVector<int>& parent) {
    u = findParent(u, parent);
    v = findParent(v, parent);
    if (u != v) parent[u] = v;
}

// Function to find lowest weighted frame using Kruskal's algorithm
QVector<Edge> findLowestWeightedFrame(int n, QVector<Edge>& edges) {
    QVector<Edge> frame;
    QVector<int> parent(n+1);
    for (int i = 1; i <= n; i++) parent[i] = i;
    std::sort(edges.begin(), edges.end(), cmp);
    for (auto e : edges) {
        if (findParent(e.u, parent) != findParent(e.v, parent)) {
            frame.push_back(e);
            join(e.u, e.v, parent);
        }
    }
    return frame;
}



QString edgesToString(QVector<QPair<int, int>> edges) {
    QStringList edgeStrings;
    for (auto edge : edges) {
        edgeStrings.append(QString::number(edge.first) + "," + QString::number(edge.second));
    }
    return edgeStrings.join(" ");
}

QString pruferCodeToString(QVector<int> pruferCode) {
    QStringList pruferCodeStringList;
    for (int i = 0; i < pruferCode.size(); i++) {
        pruferCodeStringList.append(QString::number(pruferCode[i]));
    }
    return pruferCodeStringList.join(" ");
}

// Stub for get_task3()
QString get_task3(QString login, QString password)
{
    return "Task 3: place to generate a variant for " + login + password;
}

// Stub for get_task4()
QString get_task4(QString login, QString password)
{
    return "Task 4: place to generate a variant for " + login + password;
}
