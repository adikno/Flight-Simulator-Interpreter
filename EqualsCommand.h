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

            symbolTable[x[1]] = symbolTable[x[3]];

            //client
            //instruction!!!
            return 0;
        }
        char data[x[2].size()];
        strcpy(data, x[2].data());
        ShuntingYard *shuntingYard = new ShuntingYard();
        queue<string> queue1 = shuntingYard->shuntingYard(data);
        Expression *exp = shuntingYard->postfixEvaluate(queue1);
        symbolTable[x[0]] = exp->calculate();
        //instruction!!!
    }

};


#endif //UNTITLED9_EQUALCOMMAND_H
