//
// Created by michal on 12/16/18.
//

#ifndef UNTITLED9_SHUNTINGYARD_H
#define UNTITLED9_SHUNTINGYARD_H

#include "Expression.h"
#include "Command.h"
#include "OpenServerCommand.cpp"
#include "ConnectCommand.cpp"
#include "Expression.h"
#include "queue"
#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <stack>
#include "Number.h"
#include <map>
#include "Plus.cpp"
#include "Minus.cpp"
#include "Div.cpp"
#include "Mult.cpp"

extern map<string, Command*> commands;
extern map<string, double> symbolTable;

class ShuntingYard {
public:
    queue<string> shuntingYard(char* x);

    Expression* postfixEvaluate(queue<string> que);

    char* removeSpaces(string x);
};

#endif //UNTITLED9_SHUNTINGYARD_H
