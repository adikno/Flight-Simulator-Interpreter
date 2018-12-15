//
// Created by michal on 12/12/18.
//
#include <string.h>
#include <stdlib.h>
#include "Command.h"
#include <thread>
#include "DataReaderServer.cpp"
class OpenServerCommand : public Command{

    int doCommand(string x[]) override {
        int num0;
        int num1;

        try {
             num0 = stoi(x[0]);
            num1 = stoi(x[1]);
        } catch (out_of_range &exception1){
           throw "illegal arguments";
        }
        thread thread1(DataReaderServer(num0,num1));
        thread1.join();
        return 2;


    }

};
