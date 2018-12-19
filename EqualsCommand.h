//
// Created by michal on 12/16/18.
//

#ifndef UNTITLED9_EQUALCOMMAND_H
#define UNTITLED9_EQUALCOMMAND_H


#include <map>
#include <cstring>
#include "Command.h"
#include "ShuntingYard.h"


class EqualsCommand : public Command {

public:
    int doCommand(vector<string> x) {
        if (x.at(3) == "bind") {
            if (x.at(1)[0] == '\"') {
                pathTable[x.at(4).substr(1, x.at(4).length() - 1)] = x.at(1);
                symbolTable[x.at(1)] = xmlTable[x.at(4).substr(1, x.at(4).length() - 1)];
                return 0;
            } else {
                //pathTable[x.at(4).substr(1, x.at(4).length() - 1)] = x.at(1).substr(1, x.at(1).length() - 1);

                symbolTable[x.at(1)] = xmlTable[x.at(4)];
                return 0;
            }
        }
        if (x.at(0) == "var") {
            ShuntingYard *shuntingYard = new ShuntingYard();
            queue<string> queue1 = shuntingYard->shuntingYard(x.at(3));
            Expression *exp = shuntingYard->postfixEvaluate(queue1);
            symbolTable[x.at(1)] = exp->calculate();
            char *value = (char *) (&symbolTable[x.at(1)]);
            char *instruction;
            strcpy(instruction, pathTable[x.at(1)].data());
            strcat(instruction, value);
            params->setInstruction(instruction);
            return 0;
        }
        ShuntingYard *shuntingYard = new ShuntingYard();
        queue<string> queue1 = shuntingYard->shuntingYard(x.at(2));
        Expression *exp = shuntingYard->postfixEvaluate(queue1);
        symbolTable[x.at(0)] = exp->calculate();
        char *instruction;
        strcpy(instruction, pathTable[x.at(0)].data());
        char *value = (char *) (&symbolTable[x.at(0)]);
        strcat(instruction, value);
        params->setInstruction(instruction);
    }

};


#endif //UNTITLED9_EQUALCOMMAND_H
