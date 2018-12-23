//
// Created by michal on 12/23/18.
//

#include "Command.h"

using namespace std;

class EntercCommand : public Command{
public:
    int doCommand(vector<string> &x){
        cout << "enterC" << endl;
        char c;
        cin >> c;
    }
};
