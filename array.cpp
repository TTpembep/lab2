#include "array.h"

void arrayInitiate(string query, string fileName) {
    fileName = "containers/" + fileName;
    stringstream ss (query);
    string action;
    getline(ss, action, ' ');
    string value;
    getline(ss, value, ' ');
    string temp;
    getline(ss, temp);
    int index;
    
    for (char &c : action) {
        if (isupper(c)) {
            c = tolower(c);
        }else {
            cout << "Action syntaxys error. " << endl;
            return;
        }
    }

    Array arr;
    if (filesystem::exists(fileName)){
        ifstream fin (fileName);
        string line;
        getline(fin, line);
        fin.close();

        stringstream ss(line);
        string elem;

        while (getline(ss, elem, ' ')){
            arr.push_back(elem);
        }
    }else{
        ofstream file(fileName);
        file.close();
    }
    if (action == "push") {arr.push_back(value);}
    else if (action == "pushi") {
        if (!convertIntoNum(temp, index)){
        cout << "Index syntaxys error. " << endl;
        return;
        }
        arr.push_index(value, index);
    }else if (action == "del") {
        if (!convertIntoNum(value, index)){
        cout << "Index syntaxys error. " << endl;
        return;
        }
        arr.remove(index);
    }else if (action == "replace") {
        if (!convertIntoNum(temp, index)){
        cout << "Index syntaxys error. " << endl;
        return;
        }
        arr.replace(value, index);
    }else if (action == "size") {
        cout << arr.sizeArr() << endl;
        return;
    }else if (action == "get") {
        int index;
        if (!convertIntoNum(value, index)){
            return;
        }
        string result;
        if (!arr.get(index, result)){
            return;
        }cout << result << endl;
    }else{
        cout << "Action is not defined. " << endl;
        return;
    }
    arr.write(fileName);
    return;
}

bool convertIntoNum(const string& temporary, int& index) {
    int result = 0;
    int startIndex = 0;
    if (temporary[0] == '-') {
        cout << "Negative index is not defined. " << endl;
        return false;
    }
    while (temporary[startIndex] != '\0') {
        char charc = temporary[startIndex];
        if (charc < '0' || charc > '9') {
            cout << "Index error. Not a number. " << endl;
            return false;
        }
        result = result * 10 + (charc - '0');
        startIndex++;
    }
    index = result;
    return true;
}
bool emptyFile (string fileName) {
    ifstream file (fileName);

    string temp;
    if(getline(file, fileName)){
        file.close();
        return false;
    }else{
        file.close();
        return true;
    }
}