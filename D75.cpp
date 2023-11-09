#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> roman;
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;

        int sum = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if ((i + 1) <= n)
            {
                if (roman[s[i]] < roman[s[i + 1]])
                {
                    sum = sum + (roman[s[i + 1]] - roman[s[i]]);
                    i++;
                }
                else
                {
                    sum += roman[s[i]];
                }
            }
            else
            {
                sum += roman[s[i]];
            }
        }
        return sum;
    }
};

int main()
{
    system("cls");
    Solution s;
    string str = "XIV";
    cout << "number: " << s.romanToInt(str);
}