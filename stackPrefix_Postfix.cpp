#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// Function to evaluate postfix expressions
int evaluatePostfix(string expression) {
    stack<int> s;
    for (char ch : expression) {
        if (isdigit(ch)) {
            s.push(ch - '0');
        } else {
            int val2 = s.top();
            s.pop();
            int val1 = s.top();
            s.pop();
            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.top();
}

int main() {
    string postfix = "53+82-*";
    cout << "Postfix expression result: " << evaluatePostfix(postfix) << endl;
    return 0;
}
