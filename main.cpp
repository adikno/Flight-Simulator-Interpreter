
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <queue>
#include <stack>
#include <string.h>
#include "Expression.h"
#include <map>
#include "Command.h"
#include "ShuntingYard.h"
#include "Interpreter.h"

map<string, double> symbolTable;
map<string, string> pathTable;
map<string, double> xmlTable;
ClientParams* params;

using namespace std;
int main() {
    string file_name = "FILE.txt";
    map<string, double> symbolTable;
    map<string, string> pathTable;
    map<string, double> xmlTable;
    params = new ClientParams();
    Interpreter *interpreter = new Interpreter();
    interpreter->lexer(file_name);
    string x = "2/(1-5)";
    ShuntingYard *shuntingYard = new ShuntingYard();
    queue<string> queue1 = shuntingYard->shuntingYard(x);
    Expression *expression = shuntingYard->postfixEvaluate(queue1);
    cout<< expression->calculate() << endl;
    return 0;


}





