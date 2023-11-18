#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            int one = 0;
            int zero = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if (((nums[j] & (1 << i)) == 0))
                    zero++;
                else
                    one++;
            }

            if (one % 3 != 0)
            {
                ans = (1 << i) | ans;
            }
        }
        return ans;
    }
};

int main()
{
    system("cls");
    Solution s;
    vector<int> arr = {4, 3, 9, 4, 3, 4, 3};
    cout << "ans: " << s.singleNumber(arr);
}