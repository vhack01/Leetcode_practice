#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {

        int rem = 0;
        int sum = 0;
        string ans = "";
        int i = 0, j = 0;
        while (i < a.size() && j < b.size())
        {
            int sum = (a[a.size() - 1 - i++] - '0') + (b[b.size() - 1 - j++] - '0') + rem;
            cout << "sum: " << sum << endl;
            if (sum == 2)
            {
                ans = "0" + ans;
                rem = 1;
            }
            else if (sum == 3)
            {
                ans = "1" + ans;
                rem = 1;
            }
            else
            {
                ans = to_string(sum) + ans;
                rem = 0;
            }
            cout << "ans: " << ans << endl;
        }

        while (i < a.size())
        {
            int sum = (a[a.size() - 1 - i++] - '0') + rem;
            if (sum == 2)
            {
                ans = "0" + ans;
                rem = 1;
            }
            else if (sum == 3)
            {
                ans = "1" + ans;
                rem = 1;
            }
            else
            {
                ans = to_string(sum) + ans;
                rem = 0;
            }
        }
        while (j < b.size())
        {
            int sum = (b[b.size() - 1 - j++] - '0') + rem;
            if (sum == 2)
            {
                ans = "0" + ans;
                rem = 1;
            }
            else if (sum == 3)
            {
                ans = "1" + ans;
                rem = 1;
            }
            else
            {
                ans = to_string(sum) + ans;
                rem = 0;
            }
        }

        if (rem == 1)
            ans = to_string(rem) + ans;
        cout << "\nfinal ans: " << ans << endl;
        return "";
    }
};

int main()
{
    system("cls");

    Solution s;
    string s1 = "1";
    string s2 = "10";

    cout << "Sum: " << s.addBinary(s1, s2);
}