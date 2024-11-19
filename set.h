#ifndef INCLUDE_SET_H
#define INCLUDE_SET_H

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
using namespace std;

struct KeyNode {   //Элемент set-множества
    string key; //Ключ
    KeyNode* next; //Указатель на следующий элемент

    KeyNode(const string& k) : key(k), next(nullptr) {}
};

struct Set {
    KeyNode** table;   //Массив указателей на элементы таблицы
    size_t tableSize;   //Размер таблицы
    //Конструктор
    Set(size_t initialCapacity = 10) : tableSize(initialCapacity) {
        table = new KeyNode*[tableSize];
        for (size_t i = 0; i < tableSize; ++i) {
            table[i] = nullptr;
        }
    }

    ~Set() {  //Деструктор
        for (size_t i = 0; i < tableSize; ++i) {
            KeyNode* current = table[i];
            while (current != nullptr) {
                KeyNode* next = current->next;
                delete current;
                current = next;
            }
        }
        delete[] table;
    }

    size_t hashFunction(const string& key) const {  //Хеширование для множества
        size_t hash = 0;
        for (char letter : key) {   //Вычисляет значение ключа в таблице
            hash = hash * 32 + letter;
        }
        return hash % tableSize;
    }

    void push(const string& key) {
        size_t hash = hashFunction(key);
        KeyNode* current = table[hash];
        while (current != nullptr) {
            if (current->key == key) {
                cout << "Key already exists." << endl;
                return;
            }
            current = current->next;
        }
        KeyNode* newNode = new KeyNode(key);
        newNode->next = table[hash];
        table[hash] = newNode;
    }

    bool get(const string& key) const {
        size_t hash = hashFunction(key);
        KeyNode* current = table[hash];
        while (current != nullptr) {
            if (current->key == key) {
                return true;
            }
            current = current->next;
        }
        return false;   //Ключ не найден
    }

    bool remove(const string& key) {
        size_t hash = hashFunction(key);
        KeyNode* current = table[hash];
        KeyNode* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[hash] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return true;
            }
            prev = current;
            current = current->next;
        }
        return false;   //Ключ не найден
    }

    void write(const string& filename) const {
        ofstream file(filename);
        for (size_t i = 0; i < tableSize; ++i) {
            KeyNode* current = table[i];
            while (current != nullptr) {
                file << current->key << " ";
                current = current->next;
            }
        }
        file.close();
    }
};

void setInitiate(string file, string actions);
bool toNum(const string& temporary, int& index);
bool emptyFile (string fileName);

#endif