//
// Created by michal on 12/12/18.
//

#include "Command.h"
#include "Client.cpp"
#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <vector>
#include <cstring>


class ConnectCommand: public Command{

    int doCommand(string x[]) override {

        int num0 , num1;
        vector<string> ve = explode(x[0], '.');
        if(ve.size() !=4){
            throw "illegal arguments";
        }


        try {
            for (int i = 0; i <4 ; ++i) {
                num0 = stoi(ve[i]);
                if(!(num0 <=0 && num0 <= 255)){
                    throw 1;
                }
            }
            num1 = stoi(x[1]);
        } catch (out_of_range &exception1){
            throw "illegal arguments";
        } catch (int x){
            throw "illegal arguments";
        }
        const char *p_data  = x[0].data();
        thread thread1(Client(num1, p_data));
        thread1.join();
        return 2;

    }
    const vector<string> explode(const string& s, const char& c) {
        string buff{""};
        vector<string> v;
        for(auto n:s) {
            if(n != c) {
                buff += n;
            }
            else {
                v.push_back(buff);
                buff="";
            }
        }
        return v;
    }



};