#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool checkInclusion1(string s1, string s2)
    {
        // O(N!) complexity
        unordered_set<string> per = permutation("", s1);
        cout << "permutation: " << per.size() << endl;
        int s = 0, e = 0;
        string str = "";
        while (e < s2.size())
        {
            str += s2[e];
            if ((e - s + 1) == s1.size())
            {
                cout << "before: " << str << endl;
                if (per.find(str) != per.end())
                    return true;
                s++;
                str = str.substr(1, str.size() - 1);
                cout << "after: " << str << endl;
            }
            e++;
        }

        return false;
    }

    static unordered_set<string> permutation(string accepted, string process)
    {
        if (process.size() <= 0)
        {
            unordered_set<string> str = {accepted};
            return str;
        }
        unordered_set<string> ans;

        for (int i = 0; i < accepted.size() + 1; i++)
        {
            string sub = accepted.substr(0, i) + process[0] + accepted.substr(i, accepted.size() - i);
            unordered_set<string> ret = permutation(sub, process.substr(1, process.size() - 1));
            for (string a : ret)
                ans.insert(a);
        }
        return ans;
    }

    static bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size())
            return false;
        sort(s1.begin(), s1.end());

        int l1 = s1.size();
        int l2 = s2.size();
        for (int i = 0; i < (l2 - l1 + 1); i++)
        {
            string str = s2.substr(i, l1);
            sort(str.begin(), str.end());
            if (str == s1)
                return true;
        }
        return false;
    }
};

int main()
{
    system("cls");
    string s1 = "adc", s2 = "dcda";
    cout << "result : " << Solution::checkInclusion(s1, s2);
}