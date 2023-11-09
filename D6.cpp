#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        set<int> s;
        int count = nums.size();
        if (count == 0)
            return 0;

        for (int i = 0; i < count; i++)
        {
            s.insert(nums[i]);
        }

        for (auto it : s)
            cout << it << " ";
        cout << endl;

        int len = 1;
        int mlen = 1;
        int flag = 0;
        auto it = s.begin(), prev = s.begin();

        ++it;
        while (it != s.end())
        {
            cout << (*prev) << " : " << *it << endl;
            if ((*prev + 1) == *it)
            {
                ++prev;
                ++len;
            }
            else
            {
                prev = it;
                mlen = (mlen > len) ? mlen : len;
                len = 1;
            }
            ++it;
        }
        mlen = mlen > len ? mlen : len;
        cout << "mlen: " << mlen << endl;
    }
};

int main()
{
    system("cls");
    vector<int> arr = {9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6};
    Solution s;
    s.longestConsecutive(arr);
}