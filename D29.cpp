#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static int search(vector<int> &nums, int target)
    {
        int s = 0, e = nums.size() - 1;
        while (s <= e)
        {

            int mid = (s + e) / 2;
            if (nums[mid] == target)
                return mid;

            // left sorted
            if (nums[s] <= nums[mid])
            {
                if (target >= nums[s] && target <= nums[mid])
                    e = mid - 1;
                else
                    s = mid + 1;
            }
            // right sorted
            else
            {
                if (target >= nums[mid] && target <= nums[e])
                {
                    s = mid + 1;
                }
                else
                    e = mid - 1;
            }
        }
        return -1;
    }
};
int main()
{
    system("cls");
    vector<int> arr = {3, 1};
    cout << "result : " << Solution::search(arr, 1);
}