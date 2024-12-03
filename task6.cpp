#include "task6.h"

void taskSixInit() {
    BloomFilter bloomFilter;

    while (true){
        string query;   //Простая обработка ввода.
        cout << "Enter query: ";
        getline(cin, query);

        stringstream ss(query);
        string action;
        getline(ss, action, ' ');
        string value;
        getline (ss, value);

        if (action == "add"){   //Добавление в фильтр.
            bloomFilter.add(value);
            cout << "The element added succesfully. \n";
        }else if (action == "get"){ //Проверка наличия.
            if (bloomFilter.contains(value)) {
                cout << "The element probably belongs to a set.\n";
            }else {
                cout << "the element doesn`t belong to the set.\n";
            }
        }else if (action == "del"){ //Удаление.
            bloomFilter.remove(value);
            cout << "The element removed succesfully. \n";
        }else if (action == "exit"){    //Завершение работы.
            return;
        }
    }
    return;
}