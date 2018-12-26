

#include "Expression.h"
#include "BinaryExpression.h"
#include <iostream>


class Div: public BinaryExpression{

public:
    Div(Expression* a, Expression* b):BinaryExpression(a,b){

    }

    double calculate(){
        return (this->left->calculate() / this->right->calculate());
    }

};