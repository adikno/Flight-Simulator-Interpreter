

#include "ConditionParser.h"

class LoopCommand: public ConditionParser {

public:
    LoopCommand(map<string,Command*> &commands, list<ParamsCommand*> &innerCommands) :
    ConditionParser(commands, innerCommands) {     }

    int doCommand(vector<string> &x) {
        try {
            Expression *boolean = new BooleanExpression(x);
            while (boolean->calculate()) {
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