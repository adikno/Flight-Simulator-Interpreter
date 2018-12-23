

#include "EqualsCommand.h"

int EqualsCommand::doCommand(vector<string> &x) {
    if (x.size() >= 4 && x.at(3) == "bind") {
        if (x.at(4)[0] == '\"') {
            pathTable[x.at(1)] = x.at(4).substr(1, x.at(4).length() - 2);
            try {
                symbolTable[x.at(1)] = xmlTable.at(x.at(4).substr(1, x.at(4).length() - 2));
            } catch (exception &e) {
                //if the path is not at the xml
                symbolTable[x.at(1)] = 0;
            }
            return 0;
        } else {
            pathTable[x.at(1)] = pathTable[x.at(4)];
            map<string,string>::iterator it;
            it = pathTable.find(x.at(4));
            try {
                symbolTable[x.at(1)] = xmlTable.at(it.operator*().second);
            } catch(exception &e) {
                //if the path is not at the xml
                symbolTable[x.at(1)] = symbolTable[x.at(4)];
            }
            return 0;
        }
    }
    if (x.at(0) == "var") {
        ShuntingYard *shuntingYard = new ShuntingYard();
        queue<string> queue1 = shuntingYard->shuntingYard(x.at(3));
        Expression *exp = shuntingYard->postfixEvaluate(queue1);
        symbolTable[x.at(1)] = exp->calculate();

        string instruction = pathTable[x.at(1)];
        ostringstream os;
        double val = symbolTable[x.at(1)];
        os << val;
        string value = os.str();
        instruction.erase(0, 1);
        instruction = instruction + " " + value;
        instruction = "set " + instruction + "\r\n";
        clientParams.instruction = instruction;
        return 0;
    }
    ShuntingYard *shuntingYard = new ShuntingYard();
    queue<string> queue1 = shuntingYard->shuntingYard(x.at(2));
    Expression *exp = shuntingYard->postfixEvaluate(queue1);
    symbolTable[x.at(0)] = exp->calculate();

    string instruction = pathTable[x.at(0)];
    ostringstream os;
    double val = symbolTable[x.at(0)];
    os << val;
    string value = os.str();
    instruction.erase(0, 1);
    instruction = instruction + " " + value;
    instruction = "set " + instruction + "\r\n";
    clientParams.instruction =instruction;
}