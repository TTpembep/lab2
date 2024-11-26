#ifndef INCLUDE_TASK1_H
#define INCLUDE_TASK1_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "stack.h"
#include "array.h"
using namespace std;

struct Graph {
    Array* adjList;  //Массив для хранения зависимостей
    Array* inDegree; //Ммассив для хранения степеней входа задач
    int numTasks;   //Количество задач

    Graph(int numTasks) : numTasks(numTasks) {
        adjList = new Array(numTasks);
        inDegree = new Array(numTasks);
        for (int i = 0; i < numTasks; ++i) {
            inDegree->push_index("0", i);
        }
    }

    ~Graph() {
        clear();
    }
    void clear() {
        delete adjList;
        delete inDegree;
        adjList = nullptr;
        inDegree = nullptr;
    }

    int getIndex(const string& task, Array tasks) const {
        for (int i = 0; i < tasks.size; ++i) {
            if (tasks[i] == task) {
                return i;
            }
        }
        return -1;
    }

    void addEdge(const string& from, const string& to, Array tasks) {
        int fromIndex = getIndex(from, tasks);
        int toIndex = getIndex(to, tasks);
        if (fromIndex != -1 && toIndex != -1) {
            adjList->push_index(from, toIndex);
            string temp;
            inDegree->get(fromIndex,temp);
            string result = to_string(stoi(temp) + 1); 
            inDegree->replace(result, fromIndex);
            //cout << "u good? ";
        }
    }

    bool canFinish(Array tasks) {
        Stack stack;
        for (int i = 0; i < numTasks; ++i) {
            string temp;
            inDegree->get(i, temp);
            if (temp == "0") {
                stack.push(tasks[i]);
            }
        }

        int count = 0;
        while (!stack.isEmpty()) {
            string task = stack.peek();
            stack.pop();
            count++;
            int taskIndex = getIndex(task, tasks);
            string current;
            adjList->get(taskIndex, current);
            while (current != "") {
                int dependentIndex = getIndex(current, tasks);
                string temp;
                inDegree->get(dependentIndex, temp);
                string result = to_string(stoi(temp) - 1);
                inDegree->replace(result, dependentIndex);
                if (result == "0") {
                    stack.push(tasks[dependentIndex]);
                } cout << "World ";
                adjList->remove(taskIndex);
                adjList->get(taskIndex, current);
            }
        }
        //stack.clear();
        return count == numTasks;
    }
};
void taskOneInit();

#endif