//new
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
ClientParams* clientParams;
ServerParams* serverParams;
pthread_mutex_t mutex;

using namespace std;
int main() {
    /*
    queue<string> queue1;
    ShuntingYard x = ShuntingYard();
    list < Expression * > list1;
    queue1 = x.shuntingYard("10 + 2 * 6");
    Expression* a = x.postfixEvaluate(queue1);
    list1.push_back(a);
    queue1 = x.shuntingYard("100 * 2 + 12");
    Expression* b = x.postfixEvaluate(queue1);
    list1.push_back(b);
    queue1  = x.shuntingYard("100 * ( 2 + 12 )");
    Expression* c = x.postfixEvaluate(queue1);
    list1.push_back(c);
    queue1  = x.shuntingYard("100 * ( 2 + 12 ) / 14");
    Expression* d = x.postfixEvaluate(queue1);
    list1.push_back(d);
    queue1  = x.shuntingYard(" + -  40");
    Expression* d1 = x.postfixEvaluate(queue1);
    list1.push_back(d1);
  //  queue1  = x.shuntingYard("5 - + - 3");
    //Expression* e = x.postfixEvaluate(queue1);
    //list1.push_back(e);
    //queue1  = x.shuntingYard("5 + - + 3");
    //Expression* e0 = x.postfixEvaluate(queue1);
    //list1.push_back(e0);
    queue1  = x.shuntingYard("5 - - 3");
    Expression* e1 = x.postfixEvaluate(queue1);
    double numm = e1->calculate();
    list1.push_back(e1);
    queue1  = x.shuntingYard("3 - + 10");
    Expression* e2 = x.postfixEvaluate(queue1);
    numm = e2->calculate();
    list1.push_back(e2);
    queue1  = x.shuntingYard("3 + - 10");
    Expression* e22 = x.postfixEvaluate(queue1);
    list1.push_back(e22);
    queue1  = x.shuntingYard("3 * - 10");
    Expression* e3 = x.postfixEvaluate(queue1);
    list1.push_back(e3);
    queue1  = x.shuntingYard("3 * + 10");
    Expression* e31 = x.postfixEvaluate(queue1);
    list1.push_back(e31);
    queue1  = x.shuntingYard("81 / - 9");
    Expression* e32 = x.postfixEvaluate(queue1);
    list1.push_back(e32);
    queue1  = x.shuntingYard("81 / + 9");
    Expression* e33 = x.postfixEvaluate(queue1);
    list1.push_back(e33);
    queue1  = x.shuntingYard(" - ( - 2 + 4)");
    Expression* f = x.postfixEvaluate(queue1);
    list1.push_back(f);
    queue1  = x.shuntingYard(" - ( - 6 / - 2)");
    Expression* g = x.postfixEvaluate(queue1);
    numm = g->calculate();
    list1.push_back(g);
    queue1  = x.shuntingYard(" - ( - 6 * - 2)");
    Expression* h = x.postfixEvaluate(queue1);
    numm = h->calculate();
    list1.push_back(h);
    queue1  = x.shuntingYard(" 0.2 * 0.5 ");
    Expression* i = x.postfixEvaluate(queue1);
    list1.push_back(i);
    queue1  = x.shuntingYard(" (0.8 -(0.2 * 0.5) + 0.8 ) / 0.5 ");
    Expression* i1 = x.postfixEvaluate(queue1);
    list1.push_back(i1);
    queue1  = x.shuntingYard(" 1/3 ");
    Expression* i2 = x.postfixEvaluate(queue1);
    list1.push_back(i2);
    queue1  = x.shuntingYard(" 1 / 3 / 1 / 4 / 1 / 5");
    Expression* i3 = x.postfixEvaluate(queue1);
    list1.push_back(i3);
    queue1  = x.shuntingYard(" (1 / 3)* (1 / 4) * (1 / 5) ");
    Expression* i4 = x.postfixEvaluate(queue1);
    list1.push_back(i4);


    for (Expression* e : list1){
        cout<< e->calculate()<<endl;
    }
*/
    //pthread_mutex_init(&mutex, nullptr);
    string file_name = "FILE.txt";
    cout<< "kuku"<<endl;

  //  map<string, double> symbolTable;
    //map<string, string> pathTable;
    map<string, double> xmlTable;
     clientParams = new ClientParams();
     serverParams = new ServerParams();

     Interpreter *interpreter = new Interpreter();
     interpreter->lexer(file_name);
  //  pthread_mutex_destroy(&mutex);
     return 0;


}





