#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int curr = 0;
        int prev = 0;
        int count = 0;
        while (curr < nums.size())
        {
            count++;
            if (curr != 0)
            {
                cout << "curr: " << nums[curr] << endl;
                if (nums[curr] == nums[curr - 1])
                {
                    if (count <= 2)
                        nums[prev++] = nums[curr++];
                    else
                    {
                        curr++;
                    }
                }
                else
                {
                    count = 1;
                    nums[prev++] = nums[curr++];
                }
            }
            else
            {
                curr++;
                prev++;
            }
        }
        return prev;
    }
};

int main()
{
    system("cls");
    Solution s;
    vector<int> arr = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    cout << "num: " << s.removeDuplicates(arr);
}