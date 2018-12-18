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
#include <map>
#include "Command.h"
#include "OpenServerCommand.cpp"
#include "ConditionParser.h"
#include "ConnectCommand.h"

using namespace std;
//map<string, Command*> commands;
//map<string, double> symbolTable;
//map<string, string> pathTable;
//map<string, double> xmlTable;

class Interpreter {

    map<string, Command*> commands;
public:
    Interpreter(){
        commands["openDataServer"] = new OpenServerCommand();
        commands["connect"] = new ConnectCommand();
        commands["ifCommnand"];
        commands["while"];
        commands["equals"];
        commands["functions"];

        params = new ClientParams();

    }
    void lexer(string fileName);

    const vector<string> explode(const string& s, const char& c1, const char& c2);
    void parser(vector<string> vector);
    void ParagraphLexer(string fileName, Command *condition, string args[]);

};


#endif //UNTITLED9_INTERPRETER_H
