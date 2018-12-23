//
// Created by michal on 12/13/18.
//

#ifndef UNTITLED9_COMMANDEXPRESSION_H
#define UNTITLED9_COMMANDEXPRESSION_H

#include "Expression.h"
#include "Command.h"
class CommandExpression: public Expression {
protected:
    Command* command;
    vector<string> arr;
public:


    CommandExpression(Command *a) {
        this->command = a;
    }

    double calculate(){
        command->doCommand(arr);
    }

    void setArr(vector<string> x){
        this->arr = x;
    }

};
#endif //UNTITLED9_COMMANDEXPRESSION_H
