#include "task3.h"

void taskThreeInit(){
    string gen1, gen2;  //Считывание строк.
    cout << "Введите первый геном: ";
    getline(cin, gen1);
    cout << "Введите второй геном: ";
    getline(cin, gen2);
    Array firstGen;
    //Разбиение по парам.
    for (int i = 0; i < gen1.length()-1 ; i++){
        char c1 = gen1[i];
        char c2 = gen1[i + 1];
        string temp = string(1, c1) + string(1, c2);
        firstGen.push_back(temp);
    }//Проверка на совпадения.
    int counter = 0;
    for (int i = 0; i < gen2.length()-1 ; i++){
        char c1 = gen2[i];
        char c2 = gen2[i + 1];
        string temp = string(1, c1) + string(1, c2);
        int index = firstGen.find(temp);
        while (index != -1){
            counter++;
            firstGen.remove(index);
            index = firstGen.find(temp);
        }
    }cout << "Совпадений: " << counter << ".\n";
    return;
}