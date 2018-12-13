//
// Created by michal on 12/13/18.
//

#ifndef UNTITLED9_COMMANDEXPRESSION_H
#define UNTITLED9_COMMANDEXPRESSION_H

#include "Expression.h"
#include "Command.h"
class CommandExpression: public Expression{
    Command* command;
public:
    CommandExpression(Command *a){
        this->command = a;
    }
    double Calculate(){
        command->doCommand();
    }

};
#endif //UNTITLED9_COMMANDEXPRESSION_H
