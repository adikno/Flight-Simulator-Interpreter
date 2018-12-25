

#include "EqualsCommand.h"

int EqualsCommand::doCommand(vector<string> &x) {

    //if its a bind command
    if (x.size() >= 4 && x.at(3) == "bind") {
        pthread_mutex_lock(&mutexXml);
        //bind with path
        if (x.at(4)[0] == '\"') {
            pathTable[x.at(1)] = x.at(4).substr(1, x.at(4).length() - 2);
            try {
                symbolTable[x.at(1)] = xmlTable.at(x.at(4).substr(1, x.at(4).length() - 2));
            } catch (exception &e) {
                //if the path is not at the xml
                symbolTable[x.at(1)] = 0;
            }
            pthread_mutex_unlock(&mutexXml);
            return 0;
            //bins with specific var
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
            pthread_mutex_unlock(&mutexXml);
            return 0;
        }
    }
    //assignment operation - making change in the simulator
    if (x.at(0) == "var") {
        ShuntingYard *shuntingYard = new ShuntingYard();
        queue<string> queue1 = shuntingYard->shuntingYard(x.at(3));
        Expression *exp = shuntingYard->postfixEvaluate(queue1);
        //evaluate the string and set it in the symbol table
        symbolTable[x.at(1)] = exp->calculate();
        //get the path of the var
        string instruction = pathTable[x.at(1)];
        ostringstream os;
        //get the value
        double val = symbolTable[x.at(1)];
        os << val;
        string value = os.str();
        instruction.erase(0, 1);
        instruction = instruction + " " + value;
        instruction = "set " + instruction + "\r\n";
        //set instruction to the client
        pthread_mutex_lock(&mutexIns);
        clientParams.instruction = instruction;
        pthread_mutex_unlock(&mutexIns);
        return 0;
    }
    //assignment operation by given name of another var - making change in the simulator
    ShuntingYard *shuntingYard = new ShuntingYard();
    //evaluate the expression
    queue<string> queue1 = shuntingYard->shuntingYard(x.at(2));
    Expression *exp = shuntingYard->postfixEvaluate(queue1);
    symbolTable[x.at(0)] = exp->calculate();
    //get the path of the var
    string instruction = pathTable[x.at(0)];
    ostringstream os;
    //get the value
    double val = symbolTable[x.at(0)];
    os << val;
    string value = os.str();
    instruction.erase(0, 1);
    instruction = instruction + " " + value;
    instruction = "set " + instruction + "\r\n";
    //set instruction to the client
    pthread_mutex_lock(&mutexIns);
    clientParams.instruction =instruction;
    pthread_mutex_unlock(&mutexIns);
}