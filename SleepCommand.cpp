

#include "Command.h"
#include "ShuntingYard.h"
#include <time.h>

class SleepCommand: public Command {

    int doCommand(vector<string> &x) {
        if (x.size() != 1) {
            throw "Illegal argument";
        }
        try {
            auto *shuntingYard = new ShuntingYard();
            //evaluate the expression
            queue<string> queue1 = shuntingYard->shuntingYard(x.at(0));
            Expression *exp = shuntingYard->postfixEvaluate(queue1);
            double milliseconds = exp->calculate();
            auto ms = (useconds_t)milliseconds;
            usleep(1000 * ms);
            delete exp;
            delete shuntingYard;
            return 0;
        } catch (out_of_range &e) {
            throw "Illegal argument";
        }
    }
    ~SleepCommand(){

    }
};