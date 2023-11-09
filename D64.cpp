#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int s = 0;
        int sum = 0;
        int minLen = INT_MAX;
        int e = 0;
        for (; e < nums.size(); e++)
        {
            sum += nums[e];
            cout << "e: " << sum << endl;
            while (s <= e && sum >= target)
            {
                minLen = min(minLen, (e - s + 1));
                sum -= nums[s++];
                cout << "s: " << sum << endl;
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};

int main()
{
    system("cls");
    vector<int> arr = {1, 4, 4};
    // {2, 3, 1, 2, 4, 3};
    Solution s;
    cout << "minLen: " << s.minSubArrayLen(4, arr);
}
