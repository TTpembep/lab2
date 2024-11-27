#include "task1.h"
#include "task3.h"
#include "task4.h"
#include "array.h"
//#include "stack.h"
#include "set.h"
#include "hash_table.h"


int main(int argc, char* argv[]){   // argv[0] = ./dbms
    /*string query = argv[1];  // argv[1] = --file
    if (query == "task1"){
        taskOneInit();
        return 0;
    }else if (query == "task3"){
        taskThreeInit();
        return 0;
    }else if (query != "--file"){   
        cout << "Syntaxys error. " << endl;
        return 0;
    }
    string fileName = argv[2];  // argv[2] = flist.data
    if (fileName.find(".data") == string::npos){
        cout << "Wrong file name. " << endl;
        return 0;
    }
    query = argv[3]; // argv[3] = --query
    if (query != "--query"){   
        cout << "Syntaxys error. " << endl;
        return 0;
    }
    query = argv[4]; // argv[4] = 'FPUSH value'
    char structType = query[0];
    query.erase(0,1);
    if (structType == 'M'){
        arrayInitiate(query, fileName);
    }else if (structType == 'S'){
        setInitiate (query, fileName);
    }else if (structType == 'H'){
        hashInitiate (query, fileName);
    }else if (structType == 'P' && query == "RINT"){
        ifstream file("containers/" + fileName);
        string result;
        while (getline(file, result)){
            cout << result << endl;
        }
        file.close();
    }else {
        cout << "Syntaxys error. " << endl;
        return 0;
    }
    */
    taskOneInit();
    //taskThreeInit();
    //taskFourInit();
    return 0;
}
/*
g++ main.cpp array.cpp stack.cpp hash_table.cpp set.cpp task1.cpp task3.cpp task4.cpp -o lab2

./lab2 task1
tasks = ['A', 'B', 'C'], dependencies = [('A', 'B'), ('B', 'C')]
tasks = ['A', 'B', 'C'], dependencies = [('A', 'B'), ('B', 'A')]
tasks = ['A', 'B', 'C'], dependencies = [('A', 'B')]
tasks = ['A', 'B', 'C'], dependencies = [('A', 'B'), ('B', 'D')]

./lab2 --file test.data --query 'SETADD aboba'
./lab2 --file test.data --query 'SETDEL aboba'
./lab2 --file test.data --query 'SET_AT aboba'

./lab2 task3
ABBACAB BCABB

./lab2 task4
4
cAnnot
cannOt
fOund
pAge
thE pAge cAnnot be fouNd -> 2
thE PAGE cannot be found -> 4


*/