#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int maxSumSubArray(vector<int> &arr)
    {
        int sum = 0;
        int maxi = INT_MIN;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            maxi = max(sum, maxi);
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return maxi;
    }
};

int main()
{
    system("cls");
    vector<int> arr = {-5, 4, 6, -3, 4, -1};
    Solution s;
    cout << "res : " << s.maxSumSubArray(arr);
}