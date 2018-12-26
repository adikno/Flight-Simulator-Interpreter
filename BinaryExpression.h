

#ifndef UNTITLED9_BINARYEXPRESSION_H
#define UNTITLED9_BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : public Expression{
protected:
    Expression* left;
    Expression* right;

public:
    BinaryExpression(Expression* a, Expression* b){
        this->left = a;
        this->right = b;
    }

    ~BinaryExpression() override {
        delete left;
        delete right;
    }

};
#endif //UNTITLED9_BINARYEXPRESSION_H
