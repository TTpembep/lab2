#include "task1.h"

bool isDepPossible(char dep1, char dep2, Stack tasks){
    char temp1 = ' ';
    char temp2 = ' ';
    while (!tasks.isEmpty()){   //Пока стек не пустой.
        if ((tasks.peek())[0] == dep1 || (tasks.peek())[0] == dep2){    //Если взятое значение равно одному из нужных.
            if (temp1 == ' ') {temp1 = (tasks.peek())[0];}  //Присваиваем в пустую временную ячейку.
            else if (temp2 == ' ') {temp2 = (tasks.peek())[0];}
        }

        if (temp1 == dep1 && temp2 == dep2) {return true;}  //Случай верной зависимости.
        else if (temp1 == dep2 && temp2 == dep1) {return false;}    //Случай не верной зависимости.

        tasks.pop();    //Убираем проверенный элемент из стека.
    }
    return false;   //Для остальных случаев.
}


void taskOneInit() {
    cout << "Введите задачи и их зависимости" << endl;
    cout << "Формат: tasks = ['A', 'B', 'C'], dependencies = [('A', 'B'), ('B', 'C')]" << endl;
    cout << "Запрос: ";
    string query;   //Обработка входного запроса.
    getline(cin, query);
    stringstream ss(query);
    string item;
    getline(ss, item, ' ');
    if (item != "tasks") {
        cout << "Syntax error" << endl;
        return;
    }
    getline(ss, item, ' ');
    if (item != "=") {
        cout << "Syntax error" << endl;
        return;
    }
    getline(ss, item, ']');
    item.erase(0, 1);
    stringstream tempSS(item);
    string temp;  
    Stack tasks;    //Запись задач.
    while (getline(tempSS, temp, '\'')) {
        if (temp.find(',') == string::npos) {
            tasks.push(temp);
        }
    }
    getline(ss, item, ' ');
    if (item != ",") {
        cout << "Syntax error" << endl;
        return;
    }
    getline(ss, item, ' ');
    if (item != "dependencies") {
        cout << "Syntax error" << endl;
        return;
    }
    getline(ss, item, ' ');
    if (item != "=") {
        cout << "Syntax error" << endl;
        return;
    }
    getline(ss, item, ']');
    item.erase(0, 1);
    stringstream tempss(item);
    temp = "";
    string dependencies;    //Запись зависимостей.
    while (getline(tempss, temp, '\'')) {
        if (temp[0] != '(' && temp[0] != ',' && temp[0] != ')') {
            dependencies += temp;
        }
    }

    for (int i = (dependencies.length() - 1); i >= 0; i -= 2){
        char dep1 = dependencies[i];    //Берём одну зависимость.
        char dep2 = dependencies[i -1];

        Stack temp = tasks; //Создаем временный стек копированием.
        if (!isDepPossible(dep1, dep2, temp)){  //Проверяем на возможность.
            cout << "Impossible tasks combination. \n";
            return;
        }
    }   //Если все прошли проверку - ввод верный.
    cout << "Possible tasks combination. \n";
    return;
}