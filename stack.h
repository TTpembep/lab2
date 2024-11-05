#ifndef INCLUDE_STACK_H
#define INCLUDE_STACK_H

#include "array.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>   //Для проверки наличия файла
using namespace std;

struct sNode {
    string data;
    sNode* next;
    sNode(const string& value) : data(value), next(nullptr) {}
};

struct Stack {
    sNode* top;

    Stack() : top(nullptr) {}

    ~Stack() {
        while (top != nullptr) {
            sNode* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(const string& value) {
        sNode* newsNode = new sNode(value);
        newsNode->next = top;
        top = newsNode;
    }

    void remove() {
        if (top != nullptr) {
            sNode* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void write(const string& filename) {
        ofstream file(filename);
        sNode* current = top;
        while (current != nullptr) {
            file << current->data;
            if (current->next != nullptr) {
                file << " ";
            }
            current = current->next;
        }
        file.close();
    }
};

void stackInitiate(string query, string fileName);
bool emptyFile (string fileName);

#endif