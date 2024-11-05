#include "task1.h"



// Функция для выполнения топологической сортировки
bool topologicalSort(const string& tasks, Array dependencies) {
    int maxTasks = 26; // Предполагаем, что задачи обозначены буквами от 'A' до 'Z'
    int inDegree[maxTasks] = {0};
    Stack graph[maxTasks];

    // Инициализация графа и степеней входа
    for (int i = 0; i < tasks.size(); ++i) {
        char task = tasks[i];
        int index = task - 'A';
        inDegree[index] = 0;
    }

    for (int i = 0; i < dependencies.sizeArr(); i += 2) {
        string first, second;
        if (!dependencies.get(i, first) || !dependencies.get(i + 1, second)) {
            cerr << "Error: Invalid dependency index" << endl;
            return false;
        }
        int firstIndex = first[0] - 'A';
        int secondIndex = second[0] - 'A';
        if (firstIndex < 0 || firstIndex >= maxTasks || secondIndex < 0 || secondIndex >= maxTasks) {
            cerr << "Error: Invalid task index" << endl;
            return false;
        }
        graph[secondIndex].push(string(1, first[0]));
        inDegree[firstIndex]++;
    }

    Stack zeroInDegree;

    // Добавление задач с нулевой степенью входа в стек
    for (int i = 0; i < tasks.size(); ++i) {
        char task = tasks[i];
        int index = task - 'A';
        if (inDegree[index] == 0) {
            zeroInDegree.push(string(1, task));
        }
    }

    int count = 0;

    // Топологическая сортировка
    while (zeroInDegree.top != nullptr) {
        char current = zeroInDegree.top->data[0];
        zeroInDegree.remove();
        count++;

        int currentIndex = current - 'A';
        while (graph[currentIndex].top != nullptr) {
            char neighbor = graph[currentIndex].top->data[0];
            graph[currentIndex].remove();
            int neighborIndex = neighbor - 'A';
            inDegree[neighborIndex]--;
            if (inDegree[neighborIndex] == 0) {
                zeroInDegree.push(string(1, neighbor));
            }
        }
    }

    // Если количество обработанных задач равно общему количеству задач, то возможно выполнить все задачи
    return count == tasks.size();
}

void taskOneInit() {
    string tasks = "ABC";
    Array dependencies(10);
    dependencies.push_back("A");
    dependencies.push_back("B");
    dependencies.push_back("B");
    dependencies.push_back("C");

    if (topologicalSort(tasks, dependencies)) {
        cout << "Возможно" << endl;
    } else {
        cout << "Невозможно" << endl;
    }
    cout << "check chek" << endl;
    return;
}
