#include <iostream>
using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            if (isSet(n, i))
                ans++;
        }
        cout << "ans: " << ans << endl;
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
    Solution s;
    uint32_t n = 0b00000000000000000000000000001011;
    s.hammingWeight(n);
}