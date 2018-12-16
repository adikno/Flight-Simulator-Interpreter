//
// Created by michal on 12/12/18.
//
#include <iostream>
#include <string>
#include <vector>
#include <thread>

#ifndef UNTITLED9_COMMAND_H
#define UNTITLED9_COMMAND_H

using namespace std;

extern thread client;

class Command {

public:
    virtual int doCommand(string x[]);
};


#endif //UNTITLED9_COMMAND_H
