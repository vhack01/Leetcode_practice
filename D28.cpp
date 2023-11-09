#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static int findMin(vector<int> &nums)
    {
        int s = 0, e = nums.size() - 1;
        int ans = -1;
        while (s <= e)
        {
            // array is not rotated
            if (nums[s] <= nums[e])
                return nums[s];

            // array is rotated
            int mid = (s + e) / 2;
            if (nums[mid + 1] < nums[mid] || nums[mid - 1] > nums[mid])
            {
                ans = nums[mid] > nums[mid + 1] ? nums[mid + 1] : nums[mid];
                break;
            }
            else if (nums[s] < nums[mid])
                s = mid + 1;
            else
                e = mid - 1;
        }
        return ans;
    }
};
int main()
{
    system("cls");
    vector<int> arr = {11, 12, 13, 14, 15, 16, 17, 0, 1, 2, 3, 4, 5, 6};
    cout << "result : " << Solution::findMin(arr);
}