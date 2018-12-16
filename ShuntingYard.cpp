//
// Created by michal on 12/16/18.
//

#include "ShuntingYard.h"

queue<string> ShuntingYard::shuntingYard(char* x) {
    string expression = x;
    x = removeSpaces(expression);
    vector<string> vector1;
    queue<string> queue1;
    stack<string> stack1;
    char *token;
    token = strtok(x, "+/()*-");
    while (token != NULL) {
        vector1.emplace_back(token);
        token = strtok(x, "+/()*-");

    }
    for (auto &token1: vector1) {
        try {
            int num = stoi(token1);
            queue1.push(token1);
            continue;
        } catch (out_of_range &e) {}
        if ((token1.size() == 1) && (token1.at(0) == '+' || token1.at(0) == '-')) {
            if (stack1.top().compare("*") == 0 || stack1.top().compare("/") == 0) {
                string temp = stack1.top();
                stack1.pop();
                queue1.push(temp);
                continue;
            }
            stack1.push(token1);
            continue;
        }
        if ((token1.size() == 1) && (token1.at(0) == '*' || token1.at(0) == '/' || token1.at(0) == '(')) {
            stack1.push(token1);
            continue;
        }
        if ((token1.size() == 1) && (token1.at(0) == ')')) {
            while (stack1.top().compare("(") != 0) {
                string temp = stack1.top();
                stack1.pop();
                queue1.push(temp);
            }
            stack1.pop();
            continue;
        }
        queue1.push(token1);
    }
    while (!stack1.empty()) {
        string temp = stack1.top();
        stack1.pop();
        queue1.push(temp);
    }
    return queue1;
}

Expression* ShuntingYard:: postfixEvaluate(queue<string> que) {
    stack<Expression*> stack1;
    while (!que.empty()) {
        // If the scanned character is an operand (number here),
        // push it to the stack.
        try {
            int num = stoi(que.front());
            Expression *number = new Number(num);
            stack1.push(number);
            continue;
        } catch (out_of_range &e) {}
        // If the scanned character is an operator, pop two
        // elements from stack apply the operator


        if (que.front().compare("+") == 0 || que.front().compare("*") == 0 || que.front().compare("-") == 0
            || que.front().compare("/") == 0) {

            Expression *val1 = stack1.top();
            stack1.pop();
            Expression *val2 = stack1.top();
            stack1.pop();
            string a = que.front();
            Expression *exp;
            switch (a.at(0)) {
                case '+':
                    exp = new Plus(val1, val2);
                    stack1.push(exp);
                    break;
                case '-':
                    exp = new Minus(val1, val2);
                    stack1.push(exp);
                case '*':
                    exp = new Mult(val1, val2);
                    stack1.push(exp);
                    break;
                case '/':
                    exp = new Div(val1, val2);
                    stack1.push(exp);
                    break;
            }
        }
        double value;
        std::map<string,double >::iterator it;
        it = symbolTable.find(que.front());
        if (it == symbolTable.end()) {
            //handle the error
        } else {
            value = it->second;

        }
        Expression *number = new Number(value);
        stack1.push(number);
    }
    Expression *final = stack1.top();
    return final;

}

char *ShuntingYard::removeSpaces(string x) {
    for (int i = 0; i < x.length(); i ++) {
        if (x[i] == ' ') {
            if (i == 0) {
                x = x.substr(i + 1, x.length() - 1);
            } else {
                x = x.substr(0, i - 1) + x.substr(i + 1, x.length() - 1);
            }
        }
        if (x[i] == '-' && (i != 0 && (x[i - 1] == '+'  || x[i - 1] == '/'  || x[i - 1] == '*' || x[i - 1] == '(' || x[i - 1] == ')'))) {
            x = x.substr(0, i - 1) + '0' + x.substr(i, x.length() - 1);
        } else if (i == 0 && x[i] == '-') {
            x = '0' + x;
        }
    }

    char char_array[x.length()+1];
    strcpy(char_array, x.c_str());

    return char_array;
}
