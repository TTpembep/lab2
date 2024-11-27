#include "task1.h"

void taskOneInit() {
    cout << "Введите задачи и их зависимости" << endl;
    cout << "Формат: tasks = ['A', 'B', 'C'], dependencies = [('A', 'B'), ('B', 'C')]" << endl;
    cout << "Запрос: ";
    string query;   // Обработка входного запроса
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
    Array tasks;    // Запись задач
    while (getline(tempSS, temp, '\'')) {
        if (temp.find(',') == string::npos) {
            tasks.push_back(temp);
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
    Array dependencies; // Запись последовательностей
    while (getline(tempss, temp, '\'')) {
        if (temp[0] != '(' && temp[0] != ',' && temp[0] != ')') {
            dependencies.insert(temp);
        }
    }

    Stack st;   //Заполнение стека
    for (int i = 0; i < tasks.size; i++){
        string result;
        tasks.get(i, result);
        st.push(result);
    }

    bool isPossible = false;
    bool depthRecursionTracker = false;
    while (!st.isEmpty()){  //Пока стек не пустой проверяем
        for (int i = 0; i < (dependencies.size - 1) ; i = i + 2){
            string firstTask;
            string secondTask;
            dependencies.get(i, firstTask);
            dependencies.get(i+1, secondTask);
            cout << firstTask << " " << st.peek() << " " << secondTask << " " << st.checkPrev() << "\n";
            if (firstTask == st.peek() && secondTask == st.checkPrev()){
                isPossible = true;  //Продолжаем если зависимость верна
                st.pop();
            }else if(st.peek() == "" || st.checkPrev() == "") {
                break;
            }else {
                isPossible = false;
                if (depthRecursionTracker == true){
                    cout << "Невозможно. \n";
                    return; //Останавливаем если не верна 
                }
            }
        }
        if (isPossible == false){
            st.pop();   //Отслеживаем глубокую рекурсию
            depthRecursionTracker = true;
        }
        if (st.checkPrev() == "") {st.pop();}
    }

    if (isPossible){
        cout << "Возможно. \n";
        return;
    }else{
        cout << "Невозможно. \n";
        return;
    }
    
}