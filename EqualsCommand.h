
#ifndef UNTITLED9_EQUALCOMMAND_H
#define UNTITLED9_EQUALCOMMAND_H


#include <map>
#include <cstring>
#include <sstream>
#include "Command.h"
#include "ShuntingYard.h"


class EqualsCommand : public Command {

public:
    int doCommand(vector<string> &x) {
        if (x.at(3) == "bind") {
            if (x.at(4)[0] == '\"') {
                pathTable[x.at(1)] = x.at(4).substr(1, x.at(4).length() - 2);
                symbolTable[x.at(1)] = xmlTable[x.at(4).substr(1, x.at(4).length() - 2)];
                return 0;
            } else {
                pathTable[x.at(1)] = pathTable[x.at(4)];
                map<string,string>::iterator it;
                it = pathTable.find(x.at(4));
                symbolTable[x.at(1)] = xmlTable[it.operator*().second];
                return 0;
            }
        }
        if (x.at(0) == "var") {
            ShuntingYard *shuntingYard = new ShuntingYard();
            queue<string> queue1 = shuntingYard->shuntingYard(x.at(3));
            Expression *exp = shuntingYard->postfixEvaluate(queue1);
            symbolTable[x.at(1)] = exp->calculate();

            string instruction = pathTable[x.at(1)];
            ostringstream os;
            double val = symbolTable[x.at(1)];
            os << val;
            string value = os.str();
            instruction = instruction + " " + value;

            clientParams->setInstruction(instruction);
            return 0;
        }
        ShuntingYard *shuntingYard = new ShuntingYard();
        queue<string> queue1 = shuntingYard->shuntingYard(x.at(2));
        Expression *exp = shuntingYard->postfixEvaluate(queue1);
        symbolTable[x.at(0)] = exp->calculate();

        string instruction = pathTable[x.at(0)];
        ostringstream os;
        double val = symbolTable[x.at(0)];
        os << val;
        string value = os.str();
        instruction = instruction + " " + value;

        clientParams->setInstruction(instruction);
    }

};


#endif //UNTITLED9_EQUALCOMMAND_H
