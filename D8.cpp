#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<int> stk;
        int count = s.size();
        for (int i = 0; i < count; i++)
        {

            // cout << "element: " << s[i] << endl;
            // cout << "stack size: " << stk.size() << endl;
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                stk.push(s[i]);
            }

            else if ((stk.size() > 0) && (stk.top() == '(' && s[i] == ')' || stk.top() == '[' && s[i] == ']' || stk.top() == '{' && s[i] == '}'))
            {
                stk.pop();
            }
            else
            {
                return false;
            }
        }
        if (stk.size() != 0)
            return false;
        return true;
    }
};

int main()
{
    system("cls");
    Solution s;
    string str = "{)}]";
    cout << "result : " << s.isValid(str);
}

// Submitted code

// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char> stk;
//         int i = 0;
//         for (; i < s.size(); i++)
//         {
//             if (s[i] == '(' || s[i] == '{' || s[i] == '[')
//             {
//                 stk.push(s[i]);
//             }
//             else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
//             {
//                 // extra closing characters
//                 if (stk.empty())
//                     return false;

//                 if (
//                     stk.top() == '(' && s[i] == ')' ||
//                     stk.top() == '[' && s[i] == ']' ||
//                     stk.top() == '{' && s[i] == '}')
//                 {
//                     stk.pop();
//                 }
//                 else
//                     return false;
//             }
//         }

//         if (stk.empty() && i == s.size())
//             return true;
//         else
//             return false;
//     }
// };