#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;
class Solution
{
public:
    static int characterReplacement(string s, int k)
    {

        unordered_map<char, int> unmap;
        int maxlen = 0;
        int maxfreq = 0;
        int start = 0;
        for (int end = 0; end < s.size(); end++)
        {
            unmap[s[end]]++;
            maxfreq = max(maxfreq, unmap[s[end]]);

            while ((end - start + 1) - maxfreq > k)
            {
                // shrink window
                unmap[s[start]]--;
                start++;
            }
            maxlen = max(maxlen, end - start + 1);
        }

        return maxlen;
    }
};
int main()
{
    system("cls");
    string str = "abcabcbb";
    cout << "res: " << Solution::characterReplacement(str, 2);
}