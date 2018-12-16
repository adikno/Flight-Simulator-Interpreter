


//
// Created by michal on 12/16/18.
//
#include "ConditionParser.h"
#include "Number.h"
#include "stack"


void ConditionParser::execute() {
    for (int i = 0 ; i < paragraph.size(); i++) {
        vector<string> line = paragraph.at(i);
        string key = line.at(0);
        string args[line.size() - 1];
        for (int j = 1, k = 0; j < line.size(); i++, k++){
            args[k] = line.at(j);
        }
        Command *command = commands[key];
        command->doCommand(args);
    }
}