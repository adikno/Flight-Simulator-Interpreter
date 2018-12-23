#include "CommandExpression.h"
#include "Command.h"

struct ParamsCommand {
    CommandExpression *command;
    vector<string> params;
public:
    ParamsCommand(CommandExpression *command, vector<string> params) {
        this->command = command;
        this->params = params;
    }

    CommandExpression* getCommand() {
        return this->command;
    }

    vector<string> getParams() {
        return  this->params;
    }
};
