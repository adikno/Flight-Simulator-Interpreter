

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
#include "EntercCommand.cpp"

#include <list>

using namespace std;

class Interpreter {

    map<string, CommandExpression*> commands;
public:
    Interpreter(){
        commands["openDataServer"] = new CommandExpression(new OpenServerCommand());
        commands["connect"] = new CommandExpression(new ConnectCommand());
        commands["equals"] = new CommandExpression(new EqualsCommand());
        commands["print"] = new CommandExpression(new PrintCommand());
        commands["sleep"] = new CommandExpression(new SleepCommand());
        commands["Enterc"] = new CommandExpression(new EntercCommand());
    }
    void lexer(string fileName);

    const vector<string> explode(const string& s, const char& c1, const char& c2);
    void parser(vector<string> vector);
    list<ParamsCommand*> ParagraphLexer(ifstream &file, string condition, vector<string> args);
};


#endif //UNTITLED9_INTERPRETER_H
