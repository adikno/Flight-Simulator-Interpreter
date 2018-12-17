//
// Created by michal on 12/16/18.
//
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <queue>
#include <stack>
#include <string.h>
#include "Expression.h"
#include "Number.h"
#include <map>
#include "Command.h"
#include "Plus.cpp"
#include "Minus.cpp"
#include "Div.cpp"
#include "Mult.cpp"
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
                Command *condition = commands[v.at(0)];
                string args[v.size()-1];
                for (int i =1, j=0; i < v.size(); i++, j++){
                    args[j] = v.at(i);
                }
                vector<vector<string>> paragraph;
                while (getline(myFile, line)) {
                    v = explode(line, ' ', ',');
                    paragraph.push_back(v);
                }
                ConditionParser *conditionParser = new ConditionParser(condition, paragraph);
                conditionParser->doCommand(args);
            } else {
                v = explode(line, ' ', ',');
                parser(v);
            }
        }
    }
}

const vector<string> Interpreter::explode(const string& s, const char& c1, const char& c2) {
    string buff{s[0]};
    vector<string> v;
    for(int i = 1; i < s.length(); i++) {
        if (s[i] == '=' && buff != "") {
            v.push_back(buff);
            buff = "=";
            v.push_back(buff);
            buff = "";
            continue;
        }
        if(s[i] != c1 && s[i] != c2) {
            buff += s[i];
        }
        else {
            if (s[i] == ' ' && (s[i - 1] == '/' || s[i - 1] == '*' || s[i - 1] == '-' || s[i - 1] == '+' ||
                    s[i + 1] == '/' || s[i + 1] == '*' || s[i + 1] == '-' || s[i + 1] == '+' )) {
                buff += s[i];
            } else {
                v.push_back(buff);
                buff = "";
            }
        }
    }
    v.push_back(buff);
    return v;
}
void Interpreter::parser(vector<string> vector){
    string key = vector.at(0);
    string args[vector.size()-1];
    for (int i =1, j=0; i < vector.size(); i++, j++){
        args[j] = vector.at(i);
    }
    Command *command = commands[key];
    command->doCommand(args);

}



