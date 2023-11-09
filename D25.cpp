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
            else if (nums[mid] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return -1;
    }
};
int main()
{
    system("cls");
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int k = 9;
    cout << "ans:" << Solution::search(nums, k);
}