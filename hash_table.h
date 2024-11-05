#ifndef INCLUDE_HASH_TABLE_H
#define INCLUDE_HASH_TABLE_H

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
using namespace std;

struct KeyValuePair {   //Элемент хеш-таблицы
    string key; //Ключ
    string value;   //Значение
    KeyValuePair* next; //Указатель на следующий элемент

    KeyValuePair(const string& k, const string& v) : key(k), value(v), next(nullptr) {}
};

struct HashTable {
    KeyValuePair** table;   //Массив указателей на элементы таблицы
    size_t tableSize;   //Размер таблицы
    //Конструктор
    HashTable(size_t initialCapacity = 10) : tableSize(initialCapacity) {
        table = new KeyValuePair*[tableSize];
        for (size_t i = 0; i < tableSize; ++i) {
            table[i] = nullptr;
        }
    }

    ~HashTable() {  //Деструктор
        for (size_t i = 0; i < tableSize; ++i) {
            KeyValuePair* current = table[i];
            while (current != nullptr) {
                KeyValuePair* next = current->next;
                delete current;
                current = next;
            }
        }
        delete[] table;
    }

    size_t hashFunction(const string& key) const {  //Хеш-функция
        size_t hash = 0;
        for (char letter : key) {   //Вычисляет значение ключа в таблице
            hash = hash * 32 + letter;
        }
        return hash % tableSize;
    }

    void push(const string& key, const string& value) {
        size_t hash = hashFunction(key);
        KeyValuePair* current = table[hash];
        while (current != nullptr) {
            if (current->key == key) {
                cout << "Key already exists." << endl;
                return;
            }
            current = current->next;
        }
        KeyValuePair* newPair = new KeyValuePair(key, value);
        newPair->next = table[hash];
        table[hash] = newPair;
    }

    bool get(const string& key, string& result) const {
        size_t hash = hashFunction(key);
        KeyValuePair* current = table[hash];
        while (current != nullptr) {
            if (current->key == key) {
                result = current->value;
                return true;
            }
            current = current->next;
        }
        return false;   //Ключ не найден
    }

    bool remove(const string& key) {
        size_t hash = hashFunction(key);
        KeyValuePair* current = table[hash];
        KeyValuePair* prev = nullptr;
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
            KeyValuePair* current = table[i];
            while (current != nullptr) {
                file << current->key << " " << current->value << endl;
                current = current->next;
            }
        }
        file.close();
    }

    void read(const string& filename) {
        ifstream file(filename);
        string line;
        while (getline(file, line)) {
            size_t pos = line.find(' ');
            if (pos != string::npos) {
                string key = line.substr(0, pos);
                string value = line.substr(pos + 1);
                push(key, value);
            }
        }
        file.close();
    }
};

void hashInitiate(string file, string actions);
bool toNum(const string& temporary, int& index);
bool emptyFile (string fileName);

#endif