//
// Created by michal on 12/16/18.
//

#include "ConditionParser.h"

class LoopCommand: public ConditionParser {

public:
    LoopCommand(map<string,Command*> &commands, list<ParamsCommand*> &innerCommands) :
    ConditionParser(commands, innerCommands) {     }

    int doCommand(vector<string> x) {
        try {
            Expression *boolean = new BooleanExpression(x);
            while (boolean->calculate()) {
                for (auto &command: innerCommands) {
                    Command *command1 = command->getCommand();
                    command1->doCommand(command->getParams());
                }
            }
        } catch (string &str){
            throw "Illegal condition";
        }
    }



};