#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int count = height.size();
        int max_water = INT_MIN;
        int s = 0, e = count - 1;
        while (s < e)
        {
            max_water = max(max_water, ((e - s) * min(height[s], height[e])));
            if (height[s] < height[e])
                s++;
            else
                e--;
        }

        cout << "max: " << max_water << endl;
    }
};

int main()
{
    system("cls");
    Solution s;
    vector<int> arr = {2, 3, 4, 5, 18, 17, 6};
    s.maxArea(arr);
}