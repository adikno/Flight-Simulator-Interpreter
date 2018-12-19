//
// Created by michal on 12/16/18.
//

#include <stack>
#include <string.h>
#include "Expression.h"
#include <map>
#include "Command.h"
#include "ConditionParser.h"
#include "Interpreter.h"

void Interpreter::lexer(string fileName) {
    vector<string> v;
    string line;
    ifstream myFile(fileName);
    if (myFile.is_open()) {
        while (getline(myFile, line)) {
            if (line[line.length() - 1] == '{') {
                v = explode(line, ' ', ',');
                string condition = v.at(0);
                v.erase(v.begin());
                list<ParamsCommand*> block = ParagraphLexer(myFile, condition, v);
                for (auto &command: block) {
                    Command *command1 = command->getCommand();
                    command1->doCommand(command->getParams());
                }
            } else {
                v = explode(line, ' ', ',');
                parser(v);
            }
        }
    }
}

list<ParamsCommand*> Interpreter::ParagraphLexer(ifstream &file, string condition, vector<string> args) {
    list<ParamsCommand*> commandMap;
    vector<string> vector;
    string line;
    getline(file, line);
    while (line[line.length() - 1] != '}') {
        //inner block
        if (line[line.length() - 1] == '{') {
            vector = explode(line, ' ', ',');
            string condition2 = vector.at(0);
            vector.erase(vector.begin());
            list<ParamsCommand*> block = ParagraphLexer(file, condition2, vector);
            for (auto &node: block) {
                commandMap.push_back(node);
            }
            getline(file, line);
            continue;
        }
        //inner commands
        vector = explode(line, ' ', ',');
        bool flag = false;
        string key;
        for (auto &str: vector) {
            if (str == "=") {
                key = "equals";
                flag = true;
            }
        }
        if (!flag) {
            key = vector.at(0);
            vector.erase(vector.begin());
        }
        Command *command = commands[key];
        ParamsCommand *paramsCommand = new ParamsCommand(command, vector);
        commandMap.push_back(paramsCommand);
        getline(file, line);
    }
    if (condition == "if") {
        Command *conditionParser = new IfCommand(commands, commandMap);
        commandMap.clear();
        ParamsCommand *paramsCommand = new ParamsCommand(conditionParser, args);
        commandMap.push_back(paramsCommand);
        return commandMap;
    } else {
        Command *conditionParser = new LoopCommand(commands, commandMap);
        commandMap.clear();
        ParamsCommand *paramsCommand = new ParamsCommand(conditionParser, args);
        commandMap.push_back(paramsCommand);
        return commandMap;
    }
}

const vector<string> Interpreter::explode(const string &s, const char &c1, const char &c2) {
    string buff{s[0]};
    vector<string> v;
    for (int i = 1; i < s.length(); i++) {
        if ((s[i] == '<' || s[i] == '>' || s[i] == '=') && buff == "" && (s[i + 1] == '=')) {
            buff = s[i];
            buff += s[i + 1];
            v.push_back(buff);
            buff = "";
            i++;
            continue;
        }
        if (s[i] == '=' && buff != "") {
            v.push_back(buff);
            buff = "=";
            v.push_back(buff);
            buff = "";
            continue;
        }
        if (s[i] != c1 && s[i] != c2) {
            if (s[i] == '\"') {
                buff += '\"';
            } else {
                buff += s[i];
            }
        } else {
            if (s[i] == ' ' && (s[i - 1] == '/' || s[i - 1] == '*' || s[i - 1] == '-' || s[i - 1] == '+' ||
                                s[i + 1] == '/' || s[i + 1] == '*' || s[i + 1] == '-' || s[i + 1] == '+')) {
                buff += s[i];
            } else {
                if(buff == ""){
                    continue;
                }
                v.push_back(buff);
                buff = "";
            }
        }
    }
    v.push_back(buff);
    return v;
}

void Interpreter::parser(vector<string> vector) {
    bool flag = false;
    string key;
    for (auto &str: vector) {
        if (str == "=") {
            key = "equals";
            flag = true;
        }
    }
    if (!flag) {
        key = vector.at(0);
        vector.erase(vector.begin());
    }
    Command *command = commands[key];
    command->doCommand(vector);
}



