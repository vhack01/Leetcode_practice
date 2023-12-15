#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int ans = left;
        int count = 0;
        while (left != right)
        {
            left = left >> 1;
            right = right >> 1;
            count++;
        }

        for (int i = 1; i <= count; i++)
        {
            left = (left << 1);
        }

        return left;
    }
};

int main()
{
    system("cls");
    Solution s;
    int left = 9;
    int right = 15;
    cout << "ans: " << s.rangeBitwiseAnd(left, right);
}