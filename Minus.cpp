

#include "Expression.h"
#include "BinaryExpression.h"

class Minus: public BinaryExpression{
public:
    Minus(Expression* a, Expression* b):BinaryExpression(a,b){

    }

    double calculate(){
        return (this->left->calculate() - this->right->calculate());

    }
};