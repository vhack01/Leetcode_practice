#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static string minWindow(string s, string t)
    {
        int m = s.size();
        int n = t.size();

        if (n > m)
            return "";
        if (s == t)
            return s;

        unordered_map<char, int> swmap;
        unordered_map<char, int> tmap;

        for (char ch : t)
            tmap[ch]++;

        int mct = 0;

        int start = 0;
        // string substr = "";
        int minlen = INT_MAX;
        int r = 0;
        for (int i = 0; i < m; i++)
        {
            char ch = s[i];
            if (tmap[ch])
            {
                swmap[ch]++;
                if (swmap[ch] <= tmap[ch])
                    mct++;
            }

            while (start <= i && mct == n)
            {
                if (s.substr(start, i - start + 1).size() < minlen)
                {
                    r = start;
                    minlen = s.substr(start, i - start + 1).size();
                }
                // release
                char chs = s[start];
                if (swmap[chs])
                    swmap[chs]--;
                if (swmap[chs] < tmap[chs])
                    mct--;
                start++;
            }
        }
        return minlen == INT_MAX ? "" : s.substr(r, minlen);
    }
};
int main()
{
    system("cls");
    string s1 = "dbaecbbabdcaafbddccabgba";
    string s2 = "abbcdc";
    cout << "output : " << Solution::minWindow(s1, s2);
}