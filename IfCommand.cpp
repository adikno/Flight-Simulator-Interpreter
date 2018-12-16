//
// Created by michal on 12/16/18.
//

#include "ConditionParser.h"
#include "ShuntingYard.h"

class IfCommand: public ConditionParser {

public:
    int doCommand(string x[]) {
        if (x->size() != 3) {
            throw "Illegal condition";
        }
        if (x[1] != ">" && x[1] != "<" && x[1] != ">=" && x[1] != "<=" && x[1] != "==" && x[1] != "!=") {
            throw "Illegal condition";
        }
        char data[x[0].size()];
        strcpy(data, x[0].data());
        ShuntingYard *shuntingYard = new ShuntingYard();
        queue<string> queue1 = shuntingYard->shuntingYard(data);
        Expression *first = shuntingYard->postfixEvaluate(queue1);
        data[x[2].size()];
        strcpy(data, x[2].data());
        queue1 = shuntingYard->shuntingYard(data);
        Expression *second = shuntingYard->postfixEvaluate(queue1);
        if ((x[1] == "<") && (first->clculate() < second->clculate()))  {
            execute();
        }
        if ((x[1] == ">") && (first->clculate() > second->clculate()))  {
            execute();
        }
        if ((x[1] == "<=") && (first->clculate() <= second->clculate()))  {
            execute();
        }
        if ((x[1] == ">=") && (first->clculate() >= second->clculate()))  {
            execute();
        }
        if ((x[1] == "==") && (first->clculate() == second->clculate()))  {
            execute();
        }
        if ((x[1] == "!=") && (first->clculate() != second->clculate()))  {
            execute();
        }
    }



};