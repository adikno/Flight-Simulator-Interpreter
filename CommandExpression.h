//
// Created by michal on 12/13/18.
//

#ifndef UNTITLED9_COMMANDEXPRESSION_H
#define UNTITLED9_COMMANDEXPRESSION_H

#include "Expression.h"
#include "Command.h"
class CommandExpression: public Expression{
    Command* command;
    string* arr;
public:

    CommandExpression(Command *a , string x[]){
        this->command = a;
        this->arr = x;
    }
    double Calculate(){
        command->doCommand(arr);
    }

};
#endif //UNTITLED9_COMMANDEXPRESSION_H
