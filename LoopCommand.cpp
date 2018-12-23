

#include "ConditionParser.h"

class LoopCommand: public ConditionParser {

public:
    LoopCommand(map<string,CommandExpression*> &commands, list<ParamsCommand*> &innerCommands) :
    ConditionParser(commands, innerCommands) {     }

    int doCommand(vector<string> &x) {
        try {
            Expression *boolean = new BooleanExpression(x);
            while (boolean->calculate()) {
                for (auto &command: innerCommands) {
                    CommandExpression *command1 = command->getCommand();
                    vector<string> temp = command->getParams();
                    command1->setArr(temp);
                    command1->calculate();
                }
            }
        } catch (string &str){
            throw "Illegal condition";
        }
    }



};