#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string convertOptimized(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        int index = 0;
        string ans = "";
        for (int i = 0; i < numRows; i++)
        {
            int row = i;
            int deltaSouth = 2 * (numRows - 1 - i);
            int deltaNorth = 2 * i;
            bool flag = true;
            while (row < s.size())
            {
                ans += s[row];
                if (i == 0)
                {
                    row += deltaSouth;
                }
                else if (i == numRows - 1)
                    row += deltaNorth;
                else
                {
                    if (flag)
                    {
                        row += deltaSouth;
                    }
                    else
                    {
                        row += deltaNorth;
                    }
                    flag = !flag;
                }
            }
        }
        return ans;
    }
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;

        vector<string> arr(numRows, "");
        string ans = "";
        int row = 0;
        bool flag = true;
        for (int i = 0; i < s.size(); i++)
        {
            arr[row] += s[i];
            cout << "row:" << row << ", string: " << arr[row] << endl;
            if (flag)
                row++;
            else
                row--;

            if (row == numRows)
            {
                row = numRows - 2;
                flag = false;
            }
            if (row == -1)
            {
                row = 1;
                flag = true;
            }
        }

        for (string a : arr)
            ans += a;
        return ans;
    }
};

int main()
{
    system("cls");
    Solution s;
    cout << "result: " << s.convertOptimized("P", 1);
}