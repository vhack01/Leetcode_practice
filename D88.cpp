#include <iostream>
#include <math.h>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++)
        {
            if (isSet(n, i))
            {
                ans = (1 << (31 - i)) | ans;
                // cout << "ans: " << bitset<32>(ans) << endl;
            }
        }
        return ans;
    }
    bool isSet(uint32_t n, int shift)
    {
        if ((n & (1 << shift)) != 0)
            return true;
        return false;
    }
};

int main()
{
    system("cls");
    uint32_t n =
        // 0b11111111111111111111111111111101;
        0b00000010100101000001111010011100;
    Solution s;
    cout << "ans: " << s.reverseBits(n);
}