#ifndef INCLUDE_TASK1_H
#define INCLUDE_TASK1_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "stack.h"
#include "array.h"
using namespace std;
struct ListNode {
    string data;
    ListNode* next;
    ListNode(const string& value) : data(value), next(nullptr) {}
};

struct LinkedList {
    ListNode* head;

    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        clear();
    }

    void clear() {
        while (head != nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void add(const string& value) {
        ListNode* newNode = new ListNode(value);
        newNode->next = head;
        head = newNode;
    }

    bool contains(const string& value) const {
        ListNode* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void remove(const string& value) {
        ListNode* current = head;
        ListNode* prev = nullptr;
        while (current != nullptr) {
            if (current->data == value) {
                if (prev == nullptr) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
};

struct Graph {
    LinkedList* adjList;
    int* inDegree;
    int numTasks;

    Graph(int numTasks) : numTasks(numTasks) {
        adjList = new LinkedList[numTasks];
        inDegree = new int[numTasks];
        for (int i = 0; i < numTasks; ++i) {
            inDegree[i] = 0;
        }
    }

    ~Graph() {
        clear();
    }

    void clear() {
        adjList->clear();
        delete[] inDegree;
    }
    int getIndex(const string& task, Array tasks, int numTasks) const {
        for (int i = 0; i < numTasks; ++i) {
            if (tasks[i] == task) {
                return i;
            }
        }
        return -1;
    }

    void addEdge(const string& from, const string& to, const Array& tasks) {
        int fromIndex = getIndex(from, tasks, numTasks);
        int toIndex = getIndex(to, tasks, numTasks);
        if (fromIndex != -1 && toIndex != -1) {
            adjList[toIndex].add(from);
            inDegree[fromIndex]++;
        }
    }

    bool canFinish(Array tasks) {
        Stack stack;
        for (int i = 0; i < numTasks; ++i) {
            if (inDegree[i] == 0) {
                stack.push(tasks[i]);
            }
        }

        int count = 0;
        while (!stack.isEmpty()) {
            string task = stack.peek();
            stack.pop();
            count++;

            int taskIndex = getIndex(task, tasks, numTasks);
            ListNode* current = adjList[taskIndex].head;
            while (current != nullptr) {
                int dependentIndex = getIndex(current->data, tasks, numTasks);
                inDegree[dependentIndex]--;
                if (inDegree[dependentIndex] == 0) {
                    stack.push(tasks[dependentIndex]);
                }
                current = current->next;
            }
        }
        stack.clear();
        return count == numTasks;
    }
};
void taskOneInit();

#endif