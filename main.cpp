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
ClientParams clientParams;
pthread_mutex_t mutex;

using namespace std;
int main() {

    pthread_mutex_init(&mutex, nullptr);
    string file_name = "FILE.txt";

     map<string, double> symbolTable;

     map<string, double> xmlTable;
     clientParams;
     Interpreter *interpreter = new Interpreter();
     interpreter->lexer(file_name);

     pthread_mutex_destroy(&mutex);
     pthread_exit(nullptr);
    /*while (true){}*/
    return 0;

}





