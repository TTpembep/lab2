#include "task3.h"

void taskThreeInit(){
    string gen1, gen2;  //Считывание строк.
    cout << "Введите геном 1: ";
    getline(cin, gen1);
    cout << "Введите геном 2: ";
    getline(cin, gen2);
    Array ar4g1;    //Array for genom one.
    Array ar4g2;    //Array for genom two.
    //Разбиение по парам.
    for (int i = 0; i < gen1.length()-1 ; i++){
        char c1 = gen1[i];
        char c2 = gen1[i + 1];
        string temp = string(1, c1) + string(1, c2);
        ar4g1.push_back(temp);}
    for (int i = 0; i < gen2.length()-1 ; i++){
        char c1 = gen2[i];
        char c2 = gen2[i + 1];
        string temp = string(1, c1) + string(1, c2);
        ar4g2.push_back(temp);}
    //Проверка на совпадения.
    int counter = 0;    //Божественный счётчик.
    for (int i = 0; i < ar4g1.size; i++){
        for (int j = 0; j < ar4g2.size; j++){
            if (ar4g1[i] == ar4g2[j]){
                counter++;
            }
        }
    }cout << "Совпадений: " << counter << ".\n";
    return;
}