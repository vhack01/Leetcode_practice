#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static int findDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                return nums[i];
            }
        }

        return INT_MIN;
    }
};

int main()
{
    system("cls");

    vector<int> arr = {1, 3, 4, 3, 2};
    cout << "result : " << Solution::findDuplicate(arr);
}