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

    Stack(const Stack& other) : top(nullptr) {  //Конструктор копирования.
        if (other.top != nullptr) {
            sNode* current = other.top;
            while (current != nullptr) {
                push(current->data);
                current = current->next;
            }
            // Переворачиваем стек, чтобы сохранить порядок элементов
            sNode* prev = nullptr;
            sNode* current1 = top;
            sNode* next = nullptr;
            while (current1 != nullptr) {
                next = current1->next;
                current1->next = prev;
                prev = current1;
                current1 = next;
            }
            top = prev;
        }
    }

    Stack& operator=(const Stack& other) {  //Оператор присваивания копированием.
        if (this == &other) {
            return *this;
        }

        clear();

        if (other.top != nullptr) {
            sNode* current = other.top;
            while (current != nullptr) {
                push(current->data);
                current = current->next;
            }
            // Переворачиваем стек, чтобы сохранить порядок элементов
            sNode* prev = nullptr;
            sNode* current1 = top;
            sNode* next = nullptr;
            while (current1 != nullptr) {
                next = current1->next;
                current1->next = prev;
                prev = current1;
                current1 = next;
            }
            top = prev;
        }

        return *this;
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