#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <string>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> stk;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                cout << a << " " << tokens[i][0] << " " << b << " = ";

                switch (tokens[i][0])
                {
                case '+':
                    stk.push(b + a);
                    break;
                case '-':
                    stk.push(b - a);
                    break;
                case '*':
                    stk.push(b * a);
                    break;
                case '/':
                    stk.push(trunc(b / a));
                    break;
                default:
                    break;
                }

                cout << stk.top() << endl;
            }
            else
            {
                stk.push(stoi(tokens[i]));
            }
        }

        cout << endl
             << stk.top() << endl;
    }
};

int main()
{
    system("cls");
    Solution s;
    vector<string> str = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    s.evalRPN(str);
}