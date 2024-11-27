#ifndef INCLUDE_TASK4_H
#define INCLUDE_TASK4_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "set.h"

using namespace std;

bool isVowel(char c);
bool isCorrectAccent(const string& word, const Set& dictionary);
void taskFourInit();

#endif