#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int far = 0;
        int jump = 0;
        int curr = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            far = max((i + nums[i]), far);

            if (i == curr)
            {
                jump++;
                curr = far;
            }
        }
        return jump;
    }
};
int main()
{
    system("cls");
    Solution s;
    vector<int> arr = {2, 3, 1, 2, 1, 5};
    // {2, 3, 0, 1, 4};
    ;
    cout << "minJump: " << s.jump(arr);
}