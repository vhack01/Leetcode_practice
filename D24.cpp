#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        if (k > nums.size())
        {
            return nums;
        }
        int s = 0, e = 0;
        vector<int> ans;
        multiset<int> mset;
        while (e < nums.size())
        {
            mset.insert(nums[e]);
            if ((e - s + 1) == k)
            {
                auto it = mset.rbegin();
                ans.push_back(*it);
                mset.erase(mset.find(nums[s]));
                s++;
            }
            e++;
        }

        return ans;
    }
};

int main()
{
    system("cls");
    vector<int> nums = {1, -1};
    int k = 3;
    vector<int> ans = Solution::maxSlidingWindow(nums, k);
    for (int a : ans)
        cout << a << ", ";
}