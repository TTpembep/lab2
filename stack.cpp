#include "stack.h"

void stackInitiate(string query, string fileName){
    fileName = "containers/" + fileName;
    stringstream ss (query);
    string action;
    getline(ss, action, ' ');
    string value;
    getline(ss, value);
    for (char &c : action) {
        if (isupper(c)) {
            c = tolower(c);
        }else {
            cout << "Action syntaxys error. " << endl;
            return;
        }
    }

    Stack* stack = new Stack();
    if (filesystem::exists(fileName)){
        ifstream fin (fileName);
        string line;
        getline(fin, line);
        fin.close();

        stringstream ss(line);
        string elem;

        Array arr;
        while (getline(ss, elem, ' ')){
            arr.insert(elem);
        }
        int index = arr.sizeArr();
        for (int i = 0 ; i < index ; i++){
            string res;
            arr.get(i,res);
            stack->push(res);
        }
    }else{
        ofstream file(fileName);
        file.close();
    }
    if (action == "push") {stack->push(value);}
    else if (action == "pop") {stack->remove();}
    else{
        cout << "Action is not defined. " << endl;
        return;
    }
    stack->write(fileName);
    if (emptyFile(fileName)) filesystem::remove(fileName);
    return;
}