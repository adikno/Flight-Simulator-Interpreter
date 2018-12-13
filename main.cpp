
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <queue>
#include <stack>
#include <string.h>
#include "Expression.h"
#include "Number.h"
#include <map>
#include "Plus.cpp"
#include "Minus.cpp"
#include "Div.cpp"
#include "Mult.cpp"


using namespace std;
const vector<string> explode(const string& s, const char& c);
int main() {


}
void lexer() {

    string line;
    ifstream myfile("bob.txt");
    if (myfile.is_open()) {
        getline(myfile, line);
        while (getline(myfile, line)) {
            vector<string> ve = explode(line, ' ');
        }

    }
}
const vector<string> explode(const string& s, const char& c) {
    string buff{""};
    vector<string> v;
    for(auto n:s) {
        if(n != c) {
            buff += n;
        }
        else {
            v.push_back(buff);
            buff="";
        }
    }
    return v;
}
queue<string> shuntingYard(char* x) {
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
Expression* postfixEvaluate(queue<string> que) {
    map<string, double > vars;
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
        it = vars.find(que.front());
        if (it == vars.end()) {
            //handle the error
        } else {
            value = it->second;

        }
        Expression *number = new Number(value);
        stack1.push(number);
    }

}






