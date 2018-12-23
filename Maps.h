

#ifndef UNTITLED9_MAPS_H
#define UNTITLED9_MAPS_H

#include <string>
#include <map>
#include "Command.h"
#include "ClientParams.cpp"
#include "SereverParams.h"

using namespace std;

extern map<string, double> symbolTable;
extern map<string, double> xmlTable;
extern ClientParams clientParams;
extern pthread_mutex_t mutex;

class Maps{
    map<string, double> symbolTable;
    map<string, string> pathTable;
    map<string, double> xmlTable;
    ClientParams* clientParams;

public:
    Maps(){
        this->clientParams = new  ClientParams();

    }
    map<string, double> getSymbolTable(){
        return this->symbolTable;
    }
    map<string, string> getPathTable(){
        return this->pathTable;
    }
    map<string, double> getXmlTable(){
        return this->xmlTable;
    }
    ClientParams* getclientParams(){
        return this->clientParams;
    }

};
#endif //UNTITLED9_MAPS_H
