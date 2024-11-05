#include "hash_table.h"

void hashInitiate(string query, string fileName){
    fileName = "containers/" + fileName;
    stringstream ss (query);
    string action;
    getline(ss, action, ' ');
    string key;
    getline(ss, key, ' ');
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

    HashTable ht;
    if (filesystem::exists(fileName)){
        ht.read(fileName);
    }else{
        ofstream file(fileName);
        file.close();
    }

    if (action == "push"){ht.push(key, value);}
    else if (emptyFile(fileName)){
        cout << "Error. Empty file. " << endl;
        filesystem::remove(fileName);
        return;
    }else if (action == "get"){
        string result;
        if (ht.get(key, result)) {
            cout << result << endl;
        }else{
            cout << "Key not found. " << endl;
        }
    }else if (action == "del"){
        if (!ht.remove(key)) cout << "Key not found. " << endl;
    }else{
        cout << "Action is not defined. " << endl;
        return;
    }

    ht.write(fileName);
    if (emptyFile(fileName)) filesystem::remove(fileName);
}