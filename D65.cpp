
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{

public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        int m = words[0].size();
        int n = words.size();
        if (s.size() < (n * m))
            return {};

        unordered_map<string, int> map;
        for (string str : words)
            map[str]++;

        vector<int> index;
        for (int i = 0; i < m; i++)
        {
            unordered_map<string, int> temp;
            int left = i;
            for (int j = i; j <= s.size() - m; j += m)
            {
                string str = s.substr(j, m);
                if (map.find(str) != map.end())
                {
                    temp[str]++;
                    while (temp[str] > map[str])
                    {
                        temp[s.substr(left, m)]--;
                        left += m;
                    }
                    if (j - left + m == n * m)
                    {
                        index.push_back(left);
                        temp[s.substr(left, m)]--;
                        left += m;
                    }
                }
                else
                {
                    temp.clear();
                    left = j + m;
                }
            }
        }
        return index;
    }

    // O(N!)
    // vector<int> findSubstring1(string s, vector<string> &words)
    // {
    //     if (s.size() < (words.size() * words[0].size()))
    //         return {};
    //     unordered_map<int, int> m;
    //     vector<int> index;
    //     vector<string> per = permutation("", words, 0, words.size());
    //     cout << "per size: " << per.size() << endl;
    //     for (string p : per)
    //         cout << p << endl;
    //     cout << endl
    //          << endl;
    //     ;
    //     for (int i = 0; i < per.size(); i++)
    //     {
    //         for (int j = 0; j < s.size(); j++)
    //         {
    //             if (per[i][0] == s[j])
    //             {
    //                 if (s.substr(j, per[0].size()) == per[i])
    //                 {
    //                     cout << "substr: " << s.substr(j, per[0].size()) << endl;
    //                     m[j] = j;
    //                 }
    //             }
    //         }
    //     }
    //     for (auto p : m)
    //         index.push_back(p.first);
    //     return index;
    // }

    // vector<string> permutation(string processed, vector<string> unprocessed, int s, int e)
    // {
    //     if (s == e)
    //     {
    //         return {processed};
    //     }
    //     vector<string> str;
    //     for (int i = 0; i <= processed.size() / unprocessed[0].size(); i++)
    //     {
    //         vector<string> res = permutation(processed.substr(0, i * unprocessed[0].size()) + unprocessed[s] + processed.substr(i * unprocessed[0].size()), unprocessed, s + 1, e);
    //         for (string s : res)
    //         {
    //             str.push_back(s);
    //         }
    //     }
    //     return str;
    // }
};

int main()
{
    system("cls");
    Solution s;

    // string str = "barfoofoobarthefoobarman";
    // vector<string> words{"bar", "foo", "the"};

    // string str = "barfoothefoobarman";
    // vector<string> words{"foo", "bar"};

    // string str = "wordgoodgoodgoodbestword";
    // vector<string> words{"word", "good", "best", "word"};

    string str = "foobarfoobar";
    vector<string> words{"foo", "bar"};

    // string str = "aa";
    // vector<string> words{"a"};

    vector<int> ans = s.findSubstring(str, words);
    for (int a : ans)
    {
        cout << a << ", ";
    }
}