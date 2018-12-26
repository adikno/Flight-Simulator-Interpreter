

#include "ConditionParser.h"

class IfCommand: public ConditionParser {

public:
    IfCommand(map<string,CommandExpression*> &commands, list<ParamsCommand*> &innerCommands) :
            ConditionParser(commands, innerCommands) {

    }

    int doCommand(vector<string> &x) {
        try {
            Expression *boolean = new BooleanExpression(x);
            if (boolean->calculate()) {
                //do all the command in the list
                for (auto &command: innerCommands) {
                    CommandExpression *command1 = command->getCommand();
                    vector<string> temp = command->getParams();
                    command1->setArr(temp);
                    command1->calculate();
                }
            }
            delete boolean;
        } catch (string &str){
            throw "Illegal condition";
        }
        return 0;
    }


};