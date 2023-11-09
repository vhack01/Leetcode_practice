#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        unordered_map<char, string> map;
        map['2'] = "abc";
        map['3'] = "def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wxyz";
        return helper("", digits, map);
    }
    vector<string> helper(string process, string digits, unordered_map<char, string> &map)
    {
        if (digits.size() == 0)
        {
            if (process.size() > 0)
                return {process};
            return {};
        }

        vector<string> ans;
        for (int i = 0; i < map[digits[0]].size(); i++)
        {
            vector<string> ret = helper(process + map[digits[0]][i], digits.substr(1), map);
            for (string str : ret)
            {
                ans.push_back(str);
            }
        }
        return ans;
    }
};
int main()
{
    system("cls");
    Solution s;
    string num = "";
    vector<string> arr = s.letterCombinations(num);
    for (string ch : arr)
        cout << ch << ", ";
}