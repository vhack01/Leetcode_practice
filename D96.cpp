#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int kadenes(vector<int> &arr)
    {
        int sum = 0;
        int maxi = INT_MIN;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            maxi = max(maxi, sum);
            if (sum < 0)
                sum = 0;
        }
        return maxi;
    }
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int x = kadenes(nums);
        cout << "x: " << x << endl;
        int y = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            y += nums[i];
            nums[i] *= -1;
        }
        int z = kadenes(nums);
        cout << "z: " << z << endl;
        if (z + y == 0)
            return x;
        return max(x, y + z);
    }
};

int main()
{
    system("cls");
    // [1, 2, 3, -4, -1]
    // [-1, -2, -3, 4, 1]  = 1 - (-5)
    vector<int> arr = {-3, -2, -3};
    // {5, -3, 5};
    // {1, 2, 3, -4, -1};
    // {2, 1, -5, 4, -3, 1, -3, 4, 1};
    Solution s;
    cout << "res : " << s.maxSubarraySumCircular(arr);
}

// {
//     -2, -1, 5, -4, 3, -1, 3, -4, -1
// }
// 6

// [1,-2, 3 ,-2] = 3
// [-1, 2, -3, 2] = 2
// 0 - (-2)