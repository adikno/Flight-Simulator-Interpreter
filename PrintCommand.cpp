//
// Created by michal on 12/16/18.
//

#include "Command.h"
#include "ShuntingYard.h"

class printCommand: public Command{

    int doCommand(string x[]){
        for (int i = 0; i < x->length(); i++) {
            if (x[i][0] == '\"') {
                cout << x[i].substr(1, x[i].length() - 1);
                continue;
            } else if (x[i] == "+") {
                continue;
            }
            char data[x[i].size()];
            strcpy(data, x[i].data());
            ShuntingYard *shuntingYard = new ShuntingYard();
            queue<string> queue1 = shuntingYard->shuntingYard(data);
            Expression *exp = shuntingYard->postfixEvaluate(queue1);
            cout << exp->clculate();
        }
        cout << endl;
    }


};