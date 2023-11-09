#include <iostream>
#include <string>
#include <unordered_set>
#include <climits>
using namespace std;

class Solution
{
public:
    static int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> unset;
        int max_len = 0;
        int p = 0;
        for (int i = 0; i < s.size(); i++)
        {
            auto it = unset.find(s[i]);
            if (it == unset.end())
            {
                cout << s[i] << ", ";
                unset.insert(s[i]);
            }
            else
            {
                cout << "\n\n";
                cout << "P: " << p << ", before: " << unset.size() << endl;
                max_len = max_len > unset.size() ? max_len : unset.size();
                for (auto k = unset.find(s[p]); k != it;)
                {
                    unset.erase(k);
                    p++;
                    k = unset.find(s[p]);
                }
                if (it != unset.end())
                {
                    unset.erase(it);
                    ++p;
                }
                cout << "P: " << p << ", after: " << unset.size() << endl;
                unset.insert(s[i]);
            }
        }
        max_len = max_len > unset.size() ? max_len : unset.size();
        cout << "max_len: " << max_len << endl;
        return max_len;
    }
};

int main()
{
    system("cls");
    string str = "abcabcbb";
    // Solution::check();
    cout << "res: " << Solution::lengthOfLongestSubstring(str);
}