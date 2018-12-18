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
    int doCommand(string x[]){
        if(x[3] == "bind"){
            pathTable[x[4]] = x[1];
            symbolTable[x[1]] = xmlTable[x[4]];
            return 0;
        }
        if (x[0] == "var") {
            ShuntingYard *shuntingYard = new ShuntingYard();
            queue<string> queue1 = shuntingYard->shuntingYard(x[3]);
            Expression *exp = shuntingYard->postfixEvaluate(queue1);
            symbolTable[x[1]] = exp->calculate();
            char *value = (char*)(&symbolTable[x[1]]);
            char *instruction;
            strcpy(instruction, pathTable[x[1]].data());
            strcat(instruction, value);
            params->setInstruction(instruction);
            return 0;
        }
        ShuntingYard *shuntingYard = new ShuntingYard();
        queue<string> queue1 = shuntingYard->shuntingYard(x[2]);
        Expression *exp = shuntingYard->postfixEvaluate(queue1);
        symbolTable[x[0]] = exp->calculate();
        char *instruction;
        strcpy(instruction, pathTable[x[0]].data());
        char *value = (char*)(&symbolTable[x[0]]);
        strcat(instruction, value);
        params->setInstruction(instruction);
    }

};


#endif //UNTITLED9_EQUALCOMMAND_H
