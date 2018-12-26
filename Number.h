

#ifndef UNTITLED9_NUMBET_H
#define UNTITLED9_NUMBET_H
#include "Expression.h"

class Number: public Expression{
    double num;
public:
    Number(double x){
        this->num = x;
    }
    double calculate(){
        return this->num;
    }
    ~Number() override {

    }



};
#endif //UNTITLED9_NUMBET_H
