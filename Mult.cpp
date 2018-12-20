

#include "Expression.h"
#include "BinaryExpression.h"

class Mult: public BinaryExpression{

public:
    Mult(Expression* a, Expression* b):BinaryExpression(a,b){

    }

    double calculate(){
        return (this->left->calculate()* this->right->calculate());

    }
};