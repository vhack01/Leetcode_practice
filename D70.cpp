#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int index = nums.size() - 1;
        for (int i = index; i < nums.size(); i--)
        {
            if (i + nums[i] >= index)
                index = i;
        }

        return index == 0 ? true : false;
    }
};

int main()
{
    system("cls");
    vector<int> arr = {2, 3, 1, 1, 4};
    Solution s;
    cout << "canJump: " << s.canJump(arr);
}