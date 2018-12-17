//
// Created by michal on 12/17/18.
//
#include <string>
#include <string.h>
#include "Expression.h"
#include "ShuntingYard.h"

using namespace std;

class BooleanExpression: public Expression {
    Expression *first;
    Expression *second;
    string oper;
public:
    BooleanExpression(string x[]) {
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
        first = shuntingYard->postfixEvaluate(queue1);
        data[x[2].size()];
        strcpy(data, x[2].data());
        queue1 = shuntingYard->shuntingYard(data);
        second = shuntingYard->postfixEvaluate(queue1);
        oper = x[1];
    }

    double calculate() {
        if (oper == "<") {
            return first->calculate() < second->calculate();
        }
        if (oper == ">") {
            return first->calculate() < second->calculate();
        }
        if (oper == "<=") {
            return first->calculate() < second->calculate();
        }
        if (oper == "<=") {
            return first->calculate() < second->calculate();
        }
        if (oper == "==") {
            return first->calculate() < second->calculate();
        }
        if (oper == "!=") {
            return first->calculate() < second->calculate();
        }
    }
};
