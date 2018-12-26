
#include <iostream>
#include <string>
#include <vector>
#include <thread>

#ifndef UNTITLED9_COMMAND_H
#define UNTITLED9_COMMAND_H

using namespace std;

class Command {

public:
    virtual int doCommand(vector<string> &x) = 0;
    virtual ~Command() {};
};


#endif //UNTITLED9_COMMAND_H
