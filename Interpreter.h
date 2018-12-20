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
#include <unordered_map>
#include "OpenServerCommand.h"
#include "ConditionParser.h"
#include "ConnectCommand.h"
#include "EqualsCommand.h"
#include "IfCommand.cpp"
#include "LoopCommand.cpp"
#include "PrintCommand.cpp"
#include "SleepCommand.cpp"

#include <list>

using namespace std;

class Interpreter {

    map<string, Command*> commands;
public:
    Interpreter(){
        commands["openDataServer"] = new OpenServerCommand();
        commands["connect"] = new ConnectCommand();
        commands["equals"] = new EqualsCommand();
        commands["print"] = new PrintCommand();
        commands["sleep"] = new SleepCommand();
    }
    void lexer(string fileName);

    const vector<string> explode(const string& s, const char& c1, const char& c2);
    void parser(vector<string> vector);
    list<ParamsCommand*> ParagraphLexer(ifstream &file, string condition, vector<string> args);
};


#endif //UNTITLED9_INTERPRETER_H
