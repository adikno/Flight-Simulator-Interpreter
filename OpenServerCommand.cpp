//
// Created by michal on 12/12/18.
//
#include <string.h>
#include <stdlib.h>
#include "Command.h"
#include <thread>
#include "DataReaderServer.cpp"

class OpenServerCommand : public Command{

    int doCommand(vector<string> x) override {
        int num0;
        int num1;

        try {
            num0 = stoi(x.at(0));
            num1 = stoi(x.at(1));
        } catch (invalid_argument &exception1){
           throw "illegal arguments";
        }
        thread thread1(DataReaderServer(num0,num1));
        return 2;


    }

};
