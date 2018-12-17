//
// Created by michal on 12/16/18.
//

#include "ConditionParser.h"
#include "ShuntingYard.h"
#include "BooleanExpression.cpp"

class LoopCommand: public ConditionParser {

public:
    int doCommand(string x[]) {
        try {
            Expression *boolean = new BooleanExpression(x);
            while (boolean->calculate()) {
                execute();
            }
        } catch (string &str){
            throw "Illegal condition";
        }
    }



};