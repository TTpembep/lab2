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
        clear();
    }
    void clear(){
        while (top != nullptr) {
            sNode* temp = top;
            top = top->next;
            delete temp;
        }
    }
    void push(const string& value) {
        sNode* newNode = new sNode(value);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top != nullptr) {
            sNode* temp = top;
            top = top->next;
            delete temp;
        }
    }

    string peek() const {
        if (top != nullptr) {
            return top->data;
        }
        return "";
    }

    bool isEmpty() const {
        return top == nullptr;
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