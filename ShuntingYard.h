

#ifndef UNTITLED9_SHUNTINGYARD_H
#define UNTITLED9_SHUNTINGYARD_H

#include "Expression.h"
#include "Command.h"
#include "Maps.h"
#include "queue"
#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <stack>
#include "Number.h"
#include <map>
#include "Plus.cpp"
#include "Minus.cpp"
#include "Div.cpp"
#include "Mult.cpp"


extern map<string, string> pathTable;

class ShuntingYard {
public:
    ShuntingYard() {
        map<string, string> pathTable;
    }
    queue<string> shuntingYard(string x);

    Expression* postfixEvaluate(queue<string> que);

    string removeSpaces(string x);
    const vector<string> explode(const string& s, const char& a,const char& b,const char& c,const char& d,const char& e,
                                                const char& f, const char& g);

    ~ShuntingYard() = default;
};

#endif //UNTITLED9_SHUNTINGYARD_H
