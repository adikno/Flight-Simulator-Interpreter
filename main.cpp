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
unordered_map<string, double> xmlTable;
ClientParams clientParams;
ServerParams serverParams;
pthread_mutex_t mutexXml;
pthread_mutex_t mutexIns;

using namespace std;
int main() {

    pthread_mutex_init(&mutexXml, nullptr);
    pthread_mutex_init(&mutexIns, nullptr);
    
    string file_name = "FILE.txt";

     map<string, double> symbolTable;

     map<string, double> xmlTable;
     Interpreter *interpreter = new Interpreter();
    try {
        interpreter->lexer(file_name);
        delete interpreter;
    } catch (exception &e) {
        delete interpreter;
        throw e;
    }
     
     pthread_exit(nullptr);
    /*while (true){}*/
    return 0;

}





