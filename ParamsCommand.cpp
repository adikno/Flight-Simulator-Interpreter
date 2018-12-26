#include "CommandExpression.h"
#include "Command.h"
/**
 * struct which hold command Expression and vector of string with the params of the command
 * this struct use for the list of the CommandExprssion in the condition commands
 */
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

    ~ParamsCommand() {
        delete command;
    }
};
