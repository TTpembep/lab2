#ifndef INCLUDE_ARRAY_H
#define INCLUDE_ARRAY_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>   //Для проверки наличия файла
using namespace std;

struct Array {
    string* data;   //Данные
    int size = 0;   //Количество занятых ячеек
    int capacity;   //Общее количество ячеек массива
    //Конструктор, задает пустой массив объёмом 5
    Array(int initialCapacity = 5) {
        size = 0;
        capacity = initialCapacity; // Устанавливаем начальную емкость
        data = new string[capacity]; // Выделяем память под массив
    }
    
    ~Array() {  //Деструктор
        delete[] data;
    }

    void resize() { //Увеличение размера массива в два раза, при заполнении старого
        size_t newCapacity = capacity * 2;
        string* newData = new string[newCapacity]; //Создание нового массива
        for (size_t i = 0; i < size; i++) {        //Объём которого больше в 2 раза
            newData[i] = data[i];
        }
        delete[] data; 
        data = newData; //Указатель на новый массив
        capacity = newCapacity;
    }

    void insert(const string& value) {  //Вставка в начало
        if (size >= capacity) {
            resize();
        }
        for (int i = size; i > 0; --i) {
            data[i] = data[i - 1];
        }
        data[0] = value;
        ++size;
    }

    void push_back(const string& value) {   //Вставка в конец
        if (size >= capacity) { //Проверка на переполнение
            resize();
        }
        data[size++] = value;   //Увеличиваем колисчество занятых ячеек
    }

    void push_index(const string& value, int index) { //Вставка по индексу
        if (index < 0 || index > size) {
            cout << "Index out of range. " << endl;
            return;
        }
        if (size >= capacity) {
            resize();
        }
        for (size_t i = size; i > index; --i) { //Сдвигаем элементы вправо
            data[i] = data[i - 1];
        }
        data[index] = value;
        ++size;
    }

    bool get(size_t index, string& result) {
        if (index < 0 || index >= size) {
            cout << "Index out of range." << endl;
            return false;
        }
        result = data[index];
        return true;
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            cout << "Index out of range. " << endl;
            return;
        }
        for (size_t i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }

    void replace(const string& value, int index) {
        if (index < 0 || index >= size) {
            cout << "Index out of range. " << endl;
            return;
        }
        data[index] = value;
    }

    size_t sizeArr() const {
        return size; //Возвращает текущий размер
    }

    void print() {
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void write(const string& fileName) {
        ofstream fout(fileName);
        for (int i = 0; i < size; ++i) {
            fout << data[i] << " ";
        }
        fout.close();
    }

    void clear() {
        delete[] data;
        data = nullptr;
        size = 0;
        capacity = 0;
    }

    string& operator[] (const int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }
};

void arrayInitiate(string query, string fileName);
bool convertIntoNum(const string& temporary, int& index);
bool emptyFile (string fileName);

#endif