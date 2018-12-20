//
// Created by michal on 12/16/18.
//

#include "ConditionParser.h"

class IfCommand: public ConditionParser {

public:
    IfCommand(map<string,Command*> &commands, list<ParamsCommand*> &innerCommands) :
            ConditionParser(commands, innerCommands) {

    }

    int doCommand(vector<string> &x) {
        try {
            Expression *boolean = new BooleanExpression(x);
            if (boolean->calculate()) {
                for (auto &command: innerCommands) {
                    Command *command1 = command->getCommand();
                    vector<string> temp = command->getParams();
                    command1->doCommand(temp);
                }
            }
        } catch (string &str){
            throw "Illegal condition";
        }
    }



};