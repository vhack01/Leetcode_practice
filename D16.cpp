#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        int count = nums.size();
        for (int i = 0; i < count - 2; i++)
        {
            if (i != 0 && (nums[i] == nums[i - 1]))
            {
                // cout << "in: " << nums[i] << "\n";
                continue;
            }
            cout << "out: " << nums[i] << "\n";
            int target = 0 - nums[i];
            int s = i + 1;
            int e = count - 1;

            while (s < e)
            {

                if (s > i + 1 && nums[s] == nums[s - 1])
                {
                    s++;
                    continue;
                }

                vector<int> arr(3);
                int sum = nums[s] + nums[e];
                if (sum == target)
                {
                    arr[0] = nums[i];
                    arr[1] = nums[s];
                    arr[2] = nums[e];
                    ans.push_back(arr);
                    s++;
                    e--;
                }
                else if (sum < target)
                    s++;
                else
                    e--;
            }
        }
        cout << endl;
        for (vector<int> a : ans)
        {
            for (int b : a)
                cout << b << " ";
            cout << endl;
        }
        cout << endl;
        return ans;
    }
};
int main()
{
    system("cls");
    Solution s;
    vector<int> arr = {-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};
    vector<vector<int>> result = s.threeSum(arr);
    cout << endl;
    for (vector<int> a : result)
    {
        for (int b : a)
            cout << b << " ";
        cout << endl;
    }
}

// Already solved solution
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int count = nums.size();
//         int left = 0;
//         int right = count - 1;
//         vector<vector<int>> result;
//         for (int i = 0; i < count - 2; i++)
//         {
//             if (i > 0 && nums[i] == nums[i - 1])
//             {
//                 continue;
//             }
//             int ntarget = 0 - nums[i];
//             left = i + 1;
//             right = count - 1;
//             while (left < right)
//             {
//                 if (left > i + 1 && nums[left] == nums[left - 1])
//                 {
//                     left++;
//                     continue;
//                 }
//                 int sum = nums[left] + nums[right];
//                 if (sum == ntarget)
//                 {
//                     vector<int> arr1;
//                     arr1.push_back(nums[i]);
//                     arr1.push_back(nums[left]);
//                     arr1.push_back(nums[right]);
//                     result.push_back(arr1);
//                     left++;
//                     right--;
//                 }
//                 else if (sum > ntarget)
//                     right--;
//                 else
//                     left++;
//             }
//         }
//         return result;
//     }
// };
