

#ifndef UNTITLED9_MAPS_H
#define UNTITLED9_MAPS_H

#include <string>
#include <map>
#include "Command.h"
#include "ClientParams.cpp"
#include "SereverParams.h"

using namespace std;
/**
 * lass that hold all the global variables
 */
extern map<string, double> symbolTable;
extern map<string, double> xmlTable;
extern ClientParams clientParams;
extern ServerParams serverParams;
extern pthread_mutex_t mutex;

class Maps{

public:

};
#endif //UNTITLED9_MAPS_H
