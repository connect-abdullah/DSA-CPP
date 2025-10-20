#include <iostream>
#include <stack>
#include <string>
using namespace std;

class PostFix {
public:
    int postFix(const string& expression) {
        stack<int> s;
        
        for (char c : expression) {
            if (c == ' ')
                continue;
            if (c >= '0' && c <= '9') {
                s.push(c - '0');
            }
            else if (c == '+' || c == '-' || c == '*' || c == '/') {
                if (s.size() < 2) {
                    cerr << "Error: Not enough operands." << endl;
                    return 0;
                }
                int n2 = s.top(); s.pop();
                int n1 = s.top(); s.pop();
                int result = 0;
                switch (c) {
                    case '+': result = n1 + n2; break;
                    case '-': result = n1 - n2; break;
                    case '*': result = n1 * n2; break;
                    case '/': 
                        if (n2 == 0) {
                            cerr << "Error: Division by zero." << endl;
                            return 0;
                        }
                        result = n1 / n2; 
                        break;
                }
                s.push(result);
            } else {
                cerr << "Error: Invalid character '" << c << "'." << endl;
                return 0;
            }
        }
        if (s.size() == 1)
            return s.top();
        else {
            cerr << "Error: Invalid postfix expression." << endl;
            return 0;
        }
    }
};

int main() {
    PostFix pf;
    int result = pf.postFix("23-4+567*+*");
    cout << "Result: " << result << endl;
    return 0;
}