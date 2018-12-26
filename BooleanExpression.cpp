
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
    BooleanExpression(vector<string> &x) {
        //erase the sigh { from the line
        if (x.at(x.size() - 1) == "{") {
            x.erase(x.begin() + x.size() - 1);
        }
        if (x.size() != 3) {
            throw "Illegal condition";
        }
        if (x.at(1) != ">" && x.at(1) != "<" && x.at(1) != ">=" && x.at(1) != "<=" && x.at(1) != "==" && x.at(1) != "!=") {
            throw "Illegal condition";
        }
        char data[x.at(0).size()];
        strcpy(data, x.at(0).data());
        auto *shuntingYard = new ShuntingYard();
        queue<string> queue1 = shuntingYard->shuntingYard(data);
        //evaluate the  left string
        first = shuntingYard->postfixEvaluate(queue1);
        data[x.at(2).size()];
        strcpy(data, x.at(2).data());
        queue1 = shuntingYard->shuntingYard(data);
        //evaluate the  right string
        second = shuntingYard->postfixEvaluate(queue1);
        oper = x.at(1);
        delete shuntingYard;
    }


    double calculate() {
        if (oper == "<") {
            return first->calculate() < second->calculate();
        }
        if (oper == ">") {
            return first->calculate() > second->calculate();
        }
        if (oper == "<=") {
            return first->calculate() <= second->calculate();
        }
        if (oper == ">=") {
            return first->calculate() >= second->calculate();
        }
        if (oper == "==") {
            return first->calculate() == second->calculate();
        } else {
            return first->calculate() != second->calculate();
        }
    }

    ~BooleanExpression() {
        delete first;
        delete second;
    }
};
