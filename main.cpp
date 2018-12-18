
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

map<string, double> symbolTable;
map<string, string> pathTable;
map<string, double> xmlTable;
ClientParams* params;

using namespace std;
int main() {
    map<string, double> symbolTable;
    map<string, string> pathTable;
    map<string, double> xmlTable;
    params = new ClientParams();
    string x = "2/(1-5)";
    ShuntingYard *shuntingYard = new ShuntingYard();
    queue<string> queue1 = shuntingYard->shuntingYard(x);
    Expression *expression = shuntingYard->postfixEvaluate(queue1);
    cout<< expression->calculate() << endl;
    return 0;


}




