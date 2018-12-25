

#ifndef UNTITLED9_MAPS_H
#define UNTITLED9_MAPS_H

#include <string>
#include <unordered_map>
#include <map>
#include "Command.h"
#include "ClientParams.cpp"
#include "ServerParams.h"

using namespace std;
/**
 * lass that hold all the global variables
 */
extern map<string, double> symbolTable;
extern unordered_map<string, double> xmlTable;
extern ClientParams clientParams;
extern ServerParams serverParams;
extern pthread_mutex_t mutexXml;
extern pthread_mutex_t mutexIns;

class Maps{

public:

};
#endif //UNTITLED9_MAPS_H
