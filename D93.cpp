#include <iostream>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int n1 = 0, s2 = 0;
        for (int i = 0; i < t.size(); i++)
        {
            if (t[i] == s[n1])
            {
                n1++;
            }
        }
        if (n1 == s.size())
            return true;
        return false;
    }
};

int main()
{
    system("cls");

    Solution s;
    string st = "acb", t = "ahbgdc";
    cout << "result: " << s.isSubsequence(st, t);
}