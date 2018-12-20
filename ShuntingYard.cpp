

#include <cstring>
#include "ShuntingYard.h"

queue<string>ShuntingYard::shuntingYard(string x) {
    string expression = x;
    x = removeSpaces(expression);
    vector<string> vector1;
    queue<string> queue1;
    stack<string> stack1;
    vector1 = explode(x, '+','-','(',')','*','/','-');
    for (auto &token1: vector1) {
        try {
            int num = stoi(token1);
            queue1.push(token1);
            continue;
        } catch (invalid_argument &e) {}
        if ((token1.size() == 1) && (token1.compare("+") == 0 || token1.compare("-") == 0 )) {
            if (stack1.top().compare("*") == 0 || stack1.top().compare("/") == 0) {
                string temp = stack1.top();
                stack1.pop();
                queue1.push(temp);
                continue;
            }
            stack1.push(token1);
            continue;
        }
        if ((token1.size() == 1) && (token1.compare("*") == 0  || token1.compare("/") == 0  || token1.compare("(") == 0 )) {
            stack1.push(token1);
            continue;
        }
        if ((token1.size() == 1) && (token1.compare(")") == 0 )) {
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

const vector<string> ShuntingYard:: explode(const string& s, const char& a,const char& b,const char& c,const char& d,const char& e,
                             const char& f, const char& g) {
    string buff{""};
    vector<string> v;
    for(auto n:s) {
        if(n != a && n != b && n != c &&n != d && n != e &&n != f &&n != g ) {
            buff += n;
        }
        else {
            v.push_back(buff);
            string a ="";
            a = a + n;
            v.push_back(a);
            buff="";
        }
    }
    v.push_back(buff);
    return v;
}
Expression* ShuntingYard::postfixEvaluate(queue<string> que) {
    stack<Expression*> stack1;
    while (!que.empty()) {
        // If the scanned character is an operand (number here),
        // push it to the stack.
        if (que.front() == ""){
            que.pop();
            continue;
        }
        try {
            int num = stoi(que.front());
            Expression *number = new Number(num);
            stack1.push(number);
            que.pop();
            continue;
        } catch (invalid_argument &e) {}
        // If the scanned character is an operator, pop two
        // elements from stack apply the operator


        if (que.front().compare("+") == 0 || que.front().compare("*") == 0 || que.front().compare("-") == 0
            || que.front().compare("/") == 0) {

            Expression *val1 = stack1.top();
            stack1.pop();
            Expression *val2 = stack1.top();
            stack1.pop();
            string a = que.front();
            que.pop();
            Expression *exp;
            switch (a.at(0)) {
                case '+':
                    exp = new Plus(val2, val1);
                    stack1.push(exp);
                    break;
                case '-':
                    exp = new Minus(val2, val1);
                    stack1.push(exp);
                    break;
                case '*':
                    exp = new Mult(val2, val1);
                    stack1.push(exp);
                    break;
                case '/':
                    exp = new Div(val2, val1);
                    stack1.push(exp);
            }
            continue;
        }
        double value;
        try {
            string path = pathTable.at(que.front());
            value = xmlTable.at(path);
            symbolTable.at(que.front()) =  value;
        } catch (out_of_range &e) {
            throw "No matching variable";
        }
        Expression *number = new Number(value);
        stack1.push(number);
        que.pop();



    }
    Expression *final = stack1.top();
    return final;

}


string ShuntingYard::removeSpaces(string x) {

    for (int i = 0; i < x.length(); i ++) {
        if (x[i] == ' ') {
            if (i == 0) {
                x = x.substr(i + 1, x.length() - 1);
            } else {
                x = x.substr(0, i) + x.substr(i + 1, x.length());
            }
        }
        if (x[i] == '-' && (i != 0 && (x[i - 1] == '+'  || x[i - 1] == '/'  || x[i - 1] == '*' || x[i - 1] == '(' || x[i - 1] == ')'))) {
            x = x.substr(0, i) + '0' + x.substr(i, x.length());
        } else if (i == 0 && x[i] == '-') {
            x = '0' + x;
        }
    }


    return x;
}
