#ifndef INCLUDE_TASK1_H
#define INCLUDE_TASK1_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "stack.h"
#include "array.h"
using namespace std;

bool topologicalSort(const string& tasks, Array dependencies);
void taskOneInit();

#endif