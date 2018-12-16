//
// Created by michal on 12/16/18.
//

#ifndef UNTITLED9_INTERPRETER_H
#define UNTITLED9_INTERPRETER_H


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <queue>
#include <stack>
#include <string>
#include "Expression.h"
#include "Number.h"
#include <map>
#include "Command.h"
#include "Plus.cpp"
#include "Minus.cpp"
#include "Div.cpp"
#include "Mult.cpp"
#include "OpenServerCommand.cpp"
#include "ConnectCommand.cpp"

using namespace std;
extern map<string, Command*> commands;
extern map<string, double> symbolTable;
extern map<string, string> pathTable;
extern map<string, double> xmlTable;
class Interpreter {

    map<string, double> varsPath;

public:
    Interpreter(){
        commands["openDataServer"] = new OpenServerCommand();
        commands["connect"] = new ConnectCommand();
        commands["ifCommnand"];
        commands["while"];
        commands["equals"];
        commands["functions"];




    }
    void lexer() ;

    const vector<string> explode(const string& s, const char& c);
    void parser(vector<string> vector);
    queue<string> shuntingYard(char* x);
    Expression* postfixEvaluate(queue<string> que);

     char *removeSpaces(string x);
};


#endif //UNTITLED9_INTERPRETER_H
