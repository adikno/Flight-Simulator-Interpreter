//
// Created by michal on 12/16/18.
//

#ifndef UNTITLED9_CONDITIONPARSER_H
#define UNTITLED9_CONDITIONPARSER_H

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
#include "Expression.h"
#include "Number.h"
#include <map>
#include "Plus.cpp"
#include "Minus.cpp"
#include "Div.cpp"
#include "Mult.cpp"



extern map<string, Command*> commands;
extern map<string, double> symbolTable;

class ConditionParser: public Command {
private:
    Command* condition;
protected:
    vector<vector<string>> paragraph;
public:
     ConditionParser(Command *condition, vector<vector<string>> &commands) :
     condition(condition), paragraph(commands) {}

     int doCommand(string x[]) {
         condition->doCommand(x);
     }

    void execute();


};
#endif //UNTITLED9_CONDITIONPARSER_H
