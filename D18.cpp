#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

class Solution
{
public:
    static int trap(vector<int> &height)
    {
        int count = height.size();
        vector<int> lb(count);
        int left_max = INT_MIN;
        for (int i = 0; i < count; i++)
        {
            if (i == 0)
            {
                left_max = height[i];
            }

            left_max = max(height[i], left_max);
            lb[i] = left_max;
        }

        vector<int> rb(count);
        int right_max = height[count - 1];
        rb[count - 1] = height[count - 1];
        for (int i = count - 2; i >= 0; i--)
        {
            right_max = max(height[i], right_max);
            rb[i] = right_max;
        }

        int water = 0;
        for (int i = 0; i < count; i++)
        {
            water += (min(lb[i], rb[i]) - height[i]);
        }

        cout << "Water: " << water << endl;

        // for (int a : rb)
        //     cout << a << " ";
    }
};

int main()
{
    system("cls");
    Solution s;
    vector<int> arr = {3, 1, 2, 4, 0, 1, 3, 2};
    Solution::trap(arr);
}