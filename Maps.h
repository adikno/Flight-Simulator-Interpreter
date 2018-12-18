//
// Created by michal on 12/18/18.
//

#ifndef UNTITLED9_MAPS_H
#define UNTITLED9_MAPS_H

#include <string>
#include "map"
#include "Command.h"
#include "ClientParams.cpp"

using namespace std;

extern map<string, double> symbolTable;
extern map<string, string> pathTable;
extern map<string, double> xmlTable;
extern ClientParams* params;

class Maps{
};
#endif //UNTITLED9_MAPS_H
