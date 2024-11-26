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
    stringstream tempSS(item);
    string temp;
    Array tasks;    //Запись задач
    while (getline(tempSS, temp, '\'')){
        if (temp.find(',') == string::npos){
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
    stringstream tempss(item);
    temp = "";
    Array dependencies; //Запись последовательностей
    while (getline(tempss, temp, '\'')){
        if (temp[0] != '(' && temp[0] != ',' && temp[0] != ')'){
            dependencies.push_back(temp);
        }
    }
    Graph graph(tasks.size);
    int numDependencies = dependencies.size;
    string result;
    string resultScnd;

    for (int i = 0; i < (numDependencies-4); i+=2) {
        dependencies.get(i,result);
        dependencies.get(i+1,resultScnd);
        graph.addEdge(result, resultScnd, tasks);
    }
    if (graph.canFinish(tasks)) {
        cout << "Возможно. " << endl;
    } else {
        cout << "Невозможно. " << endl;
    }
    //tasks.clear();
    //dependencies.clear();
    //graph.clear();
    return;
}