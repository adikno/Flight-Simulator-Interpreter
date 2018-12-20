#include "Command.h"

struct ParamsCommand {
    Command *command;
    vector<string> params;
public:
    ParamsCommand(Command *command, vector<string> params) {
        this->command = command;
        this->params = params;
    }

    Command* getCommand() {
        return this->command;
    }

    vector<string> getParams() {
        return  this->params;
    }
};
