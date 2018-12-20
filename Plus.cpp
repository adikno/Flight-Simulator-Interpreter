
#include "Expression.h"
#include "BinaryExpression.h"

class Plus: public BinaryExpression{
public:
    Plus(Expression* a, Expression* b):BinaryExpression(a,b){

    }

    double calculate(){
        return (this->left->calculate() + this->right->calculate());

    }
};