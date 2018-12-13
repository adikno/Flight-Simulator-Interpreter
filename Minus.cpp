//
// Created by michal on 12/13/18.
//

#include "Expression.h"
#include "BinaryExpression.h"

class Minus: public BinaryExpression{
    Expression left;
    Expression right;
public:
    Minus(Expression* a, Expression* b):BinaryExpression(a,b){

    }

    double calculate(){
        return (this->left.clculate() - this->right.clculate());

    }
};