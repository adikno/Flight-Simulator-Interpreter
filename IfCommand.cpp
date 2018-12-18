//
// Created by michal on 12/16/18.
//

#include "ConditionParser.h"
#include "BooleanExpression.cpp"

class IfCommand: public ConditionParser {

public:
    int doCommand(string x[]) {
        try {
            Expression *boolean = new BooleanExpression(x);
            if (boolean->calculate()) {
                execute();
            }
        } catch (string &str){
            throw "Illegal condition";
        }
    }



};