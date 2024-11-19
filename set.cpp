#include "set.h"

void setInitiate(string query, string fileName){
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
        }else if (c = '_'){
            //filler
        }else {
            cout << "Action syntaxys error. " << endl;
            return;
        }
    }

    Set st;
    if (filesystem::exists(fileName)){
        ifstream fin (fileName);
        string line;
        getline(fin, line);
        fin.close();

        stringstream ss(line);
        string elem;

        while (getline(ss, elem, ' ')){
            st.push(elem);
        }
    }else{
        ofstream file(fileName);
        file.close();
    }

    if (action == "etadd"){st.push(key);}
    else if (emptyFile(fileName)){
        cout << "Error. Empty file. " << endl;
        filesystem::remove(fileName);
        return;
    }else if (action == "et_at"){
        if (st.get(key)){
            cout << "Key exists. " << endl;
        }
        else cout << "Key not found. " << endl;
    }else if (action == "etdel"){
        if (!st.remove(key)) cout << "Key not found. " << endl;
    }else{
        cout << "Action is not defined. " << endl;
        return;
    }

    st.write(fileName);
    if (emptyFile(fileName)) filesystem::remove(fileName);
}