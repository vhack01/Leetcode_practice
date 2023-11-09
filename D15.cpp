#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> ans(2, -1);
        int count = numbers.size();
        int s = 0;
        int e = count - 1;
        // cout << s << " " << e << endl;
        while (s < e)
        {
            int sum = numbers[s] + numbers[e];
            if (sum == target)
            {
                ans[0] = s + 1;
                ans[1] = e + 1;
                break;
            }
            else if (sum > target)
                e--;
            else
                s++;
        }
        for (int a : ans)
            cout << a << " ";
    }
};

int main()
{
    system("cls");
    Solution s;
    vector<int> arr = {-1, 0};
    s.twoSum(arr, -1);
}