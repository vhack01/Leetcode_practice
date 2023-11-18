#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int x = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            x ^= nums[i];
            cout << x << ", ";
        }
        return x;
    }
};

int main()
{
    system("cls");
    Solution s;
    vector<int> arr = {1, 2, 2, 1, 3};
    cout << "ans: " << s.singleNumber(arr);
}