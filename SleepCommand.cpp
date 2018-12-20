

#include "Command.h"
#include "ShuntingYard.h"
#include <time.h>

class SleepCommand: public Command {

    int doCommand(vector<string> &x) {
        if (x.size() != 1) {
            throw "Illegal time";
        }
        int milliseconds;
        try {
            milliseconds = stoi(x.at(0));
        } catch (out_of_range &e) {
            throw "Illegal time";
        }
        clock_t time_end;
        time_end = clock() + milliseconds * CLOCKS_PER_SEC/1000;
        while (clock() < time_end)
        {
        }
    }
};