#include "task4.h"

bool isVowel(char c) {  //Проверка ударения на гласную
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

bool isCorrectAccent(const string& word, const Set& dictionary) {  //Проверка правильности ударения.
    int uppercaseCount = 0; //Подсчёт количества ударений
    bool isAccentRight = true;

    for (char c : word) {
        if (isupper(c)) {
            uppercaseCount++;
            if (!isVowel(c)){
                isAccentRight = false;
            }
        }
    }

    if (dictionary.get(word)) {
        return true;
    }
    return uppercaseCount == 1 && isAccentRight;
}

void taskFourInit(){
    int N;
    cout << "Введите количество слов: ";
    cin >> N;
    cin.ignore(); //Игнорируем оставшийся символ новой строки.
    cout << "Заполните словарь:\n";
    Set dictionary;
    for (int i = 0; i < N; ++i) {
        string word;
        cin >> word;
        dictionary.push(word);
    }

    string text;
    getline(cin, text);
    getline(cin, text);
    istringstream stream(text);
    string word;
    int errors = 0;

    while (stream >> word) {
        if (!isCorrectAccent(word, dictionary)) {
            errors++;
        }
    }
    cout << "Количество ошибок: " << errors << "\n";
    return ;
}