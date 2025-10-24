#include <iostream>
#include <stack>
using namespace std;


class evaluate {
    public:
        int postFix(string expression) {
            stack<int> stack;
            
            for (char c : expression) {
                if (c >= '0' && c <= '9') {
                    stack.push(c - '0');
                }
                else if (c == '+' || c == '-' || c == '*' || c == '/') {
                    if (stack.size() < 2) {
                        cerr << "Error: Not enough operands." << endl;
                        return 0;
                    }
                    int number2 = stack.top(); stack.pop();
                    int number1 = stack.top(); stack.pop();
                    int result = 0;
                    switch (c) {
                        case '+': result = number1 + number2; break;
                        case '-': result = number1 - number2; break;
                        case '*': result = number1 * number2; break;
                        case '/': 
                            if (number2 == 0) {
                                cerr << "Error: Division by zero." << endl;
                                return 0;
                            }
                            result = number1 / number2; 
                            break;
                    }
                    stack.push(result);
                } else {
                    cerr << "Error: Invalid character '" << c << "'." << endl;
                    return 0;
                }
            }
            if (stack.size() == 1) {
                return stack.top();
            } else {
                cerr << "Error: Invalid postfix expression." << endl;
                return 0;
            }
        }
    };

int main() {
    evaluate eval;

    int value = eval.postFix("23-4+567*+*");
    cout << "Your postFix expression is this: " << value << endl; 
    
    return 0;
};