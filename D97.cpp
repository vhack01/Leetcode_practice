#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        map<char, char> m1, m2;
        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (m1.find(s[i]) != m1.end())
            {
                ans += m1[s[i]];
            }
            else
            {
                if (m2.find(t[i]) == m2.end())
                {
                    m1[s[i]] = t[i];
                    m2[t[i]] = s[i];
                    ans += m1[s[i]];
                }
                else
                {
                    return false;
                }
            }
        }
        // cout << "ans: " << ans << endl;
        return ans == t ? true : false;
    }
};

int main()
{
    system("cls");
    Solution s;
    cout << "res: " << s.isIsomorphic("badc", "baba");
}

// b->b           b
// a->a
// d->b
// c->a