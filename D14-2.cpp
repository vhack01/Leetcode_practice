#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans = helper(n, 0, 0, "");
        for (string a : ans)
            cout << a << " ";
        return ans;
    }
    vector<string> helper(int n, int o, int c, string str)
    {
        if (o >= n && c >= o)
        {
            vector<string> s = {str};
            return s;
        }
        vector<string> para, ret1, ret2;
        if (o < n)
            ret1 = helper(n, o + 1, c, str + "(");
        if (c < o)
            ret2 = helper(n, o, c + 1, str + ")");

        for (string a : ret1)
            para.push_back(a);
        for (string a : ret2)
            para.push_back(a);
        return para;
    }
};

int main()
{
    system("cls");
    Solution s;
    int n = 5;
    s.generateParenthesis(n);
}