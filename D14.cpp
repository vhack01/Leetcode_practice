#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int count = s.size();
        string str = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                str += (char)s[i] + 32;
            }
            else if (s[i] >= 'a' && s[i] <= 'z')
                str += s[i];
            else if (s[i] >= '0' && s[i] <= '9')
            {
                str += s[i];
            }
        }

        cout << "string: " << str << endl;
        for (int i = 0; i < str.size() / 2; i++)
        {
            if (!(str[i] == str[str.size() - 1 - i]))
                return false;
        }

        return true;
    }
};

int main()
{
    system("cls");
    Solution s;
    string str = "0P";
    cout << s.isPalindrome(str);
}