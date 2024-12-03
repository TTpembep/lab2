#ifndef INCLUDE_TASK6_H
#define INCLUDE_TASK6_H

#include <iostream>
#include <cstring> //Библиотека для memset
#include <string>
#include <sstream>

using namespace std;

class BloomFilter {
private:
    bool* bitArray; //Массив битов для хранения состояния.
    int size; //Размер фильтра Блума.
    int numHashFunctions; //Количество хеш-функций.

    int hash1(const string& str) const {    //Хеш-функция 1.
        int hash = 0;
        for (char ch : str) {
            hash = (hash * 31 + ch) % size; //Простое хеширование.
        }
        return hash;
    }
    
    int hash2(const string& str) const {    //Хеш-функция 2.
        int hash = 0;
        for (char ch : str) {
            hash = (hash * 37 + ch) % size;\
        }
        return hash;
    }

    int hash3(const string& str) const {    //Хеш-функция 3.
        int hash = 0;
        for (char ch : str) {
            hash = (hash * 41 + ch) % size;\
        }
        return hash;
    }

public:
    //Конструктор.
    BloomFilter(int s = 10, int k = 3) : size(s), numHashFunctions(k) {
        bitArray = new bool[size]; //Создание массива битов.
        memset(bitArray, 0, size * sizeof(bool)); //Инициализация массива нулями.
    }

    ~BloomFilter() {    //Деструктор.
        delete[] bitArray; //Освобождение памяти.
    }

    void add(const string& str) {   //Метод для добавления строки в фильтр.
        int h1 = hash1(str); //Получение каждого хеша.
        int h2 = hash2(str);
        int h3 = hash3(str);
       
        bitArray[h1] = true;    //Установка битов по индексам, 
        bitArray[h2] = true;    //полученным из хеш-функций
        bitArray[h3] = true;
    }

    bool contains(const string& str) const {    //Метод для проверки наличия строки в фильтре.
        int h1 = hash1(str); //Получение каждого хеша.
        int h2 = hash2(str);
        int h3 = hash3(str);

        //Проверка установлен ли бит по индексам.
        return bitArray[h1] && bitArray[h2] && bitArray[h3];
    }

    void remove(const string& str) {    //Метод для удаления строки из фильтра.
        int h1 = hash1(str);    //Получение каждого хеша.
        int h2 = hash2(str);
        int h3 = hash3(str);

        bitArray[h1] = false;   //Сброс битов по индексам,
        bitArray[h2] = false;   //полученным из хеш-функций
        bitArray[h3] = false;
    }

};

void taskSixInit();

#endif