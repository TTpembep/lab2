#include "task1.h"

void taskOneInit() {
    cout << "Введите задачи и их зависимости" << endl;
    cout << "Формат: tasks = ['A', 'B', 'C'], dependencies = [('A', 'B'), ('B', 'C')]" << endl;
    cout << "Запрос: ";
    string query;   //Обработка входного запроса
    getline(cin, query);
    stringstream ss(query);
    string item;
    getline(ss, item, ' ');
    if (item != "tasks"){
        cout << "Syntax error" << endl;
        return;
    }getline(ss, item, ' ');
    if (item != "="){
        cout << "Syntax error" << endl;
        return;
    }getline(ss, item, ']');
    item.erase(0,1);
    cout << item << endl;
    stringstream tempSS;
    string temp;
    Array tasks;
    while (getline(tempSS, temp, '\'')){
        if (temp != ", "){
            tasks.push_back(temp);
        }
    }
    getline(ss, item, ' ');
    if (item != ","){
        cout << "Syntax error" << endl;
        return;
    }getline(ss, item, ' ');
    if (item != "dependencies"){
        cout << "Syntax error" << endl;
        return;
    }getline(ss, item, ' ');
    if (item != "="){
        cout << "Syntax error" << endl;
        return;
    }getline(ss, item, ']');
    item.erase(0,1);
    cout << item << endl;
    tempSS.str(""); //Очищаем поток
    tempSS << item;
    temp = "";
    Array dependencies;
    while (getline(tempSS, temp, '\'')){
        if (temp[0] != '(' && temp[0] != ',' && temp[0] != ')'){
            dependencies.push_back(temp);
        }
    }
    int numTasks = tasks.sizeArr() / sizeof(tasks[0]);
    Graph graph(numTasks);

    //pair<string, string> dependencies[] = {{"A", "B"}, {"B", "C"}};
    int numDependencies = dependencies.sizeArr() / sizeof(dependencies[0]);

    for (int i = 0; i < (numDependencies - 1); i+=2) {
        graph.addEdge(dependencies[i], dependencies[i+1], tasks);
    }

    if (graph.canFinish(tasks)) {
        cout << "Возможно. " << endl;
    } else {
        cout << "Невозможно. " << endl;
    }
    tasks.clear();
    dependencies.clear();
    graph.clear();

    return;
}