
#include <stack>
#include <string.h>
#include "Expression.h"
#include <map>
#include "Command.h"
#include "ConditionParser.h"
#include "Interpreter.h"

/**
 * the function split the script to command
 * @param fileName - the script
 */
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
                    CommandExpression *command1 = command->getCommand();
                    vector<string> temp = command->getParams();
                    command1->setArr(temp);
                    try {
                        command1->calculate();
                    } catch (exception &e) {
                        throw e;
                    }
                }
            } else {
                v = explode(line, ' ', ',');
                parser(v);
            }
        }
    }
    clientParams.instruction = "quit";
    serverParams.move = false;
}
/**
 * this function is a lexer for Condition and loop command - it is a recursive function that make list of command
 * @param file -ifstrem of the script
 * @param condition - string of the kind of the condition
 * @param args - vector  ofthe arg of the command
 * @return list of struct of  ParmasCommad that hold command and vector of args
 */
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
        CommandExpression *command = commands[key];
        ParamsCommand *paramsCommand = new ParamsCommand(command, vector);
        commandMap.push_back(paramsCommand);
        getline(file, line);
    }
    if (condition == "if") {
        auto *conditionParser = new CommandExpression(new IfCommand(commands, commandMap));
        commandMap.clear();
        ParamsCommand *paramsCommand = new ParamsCommand(conditionParser, args);
        commandMap.push_back(paramsCommand);
        return commandMap;
    } else {
        auto *conditionParser = new CommandExpression(new LoopCommand(commands, commandMap));
        commandMap.clear();
        ParamsCommand *paramsCommand = new ParamsCommand(conditionParser, args);
        commandMap.push_back(paramsCommand);
        return commandMap;
    }
}
/**
 * the function split string line by space and ,
 * @param s - the line
 * @param c1 - space char
 * @param c2 , char
 * @return vector of string
 */
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
        if (s[i] == '=') {
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
                if(buff == "") {
                    continue;
                }
                if (buff == " ") {
                    buff = "";
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
/**
 * the parser set of the commamd
 * @param vector of the args of the command
 */
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

    CommandExpression *command = commands[key];
    command->setArr(vector);
    command->calculate();
}



