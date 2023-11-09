#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        return helper({}, nums, 0, nums.size());
    }
    vector<vector<int>> helper(vector<int> process, vector<int> unprocess, int s, int e)
    {
        if (s == e)
        {
            return {{process}};
        }
        vector<vector<int>> mergeArr;
        for (int i = 0; i <= process.size(); i++)
        {
            vector<int> p;
            int j;
            for (j = 0; j < i; j++)
            {
                p.push_back(process[j]);
            }
            p.push_back(unprocess[s]);
            for (; j < process.size(); j++)
            {
                p.push_back(process[j]);
            }
            vector<vector<int>> ret = helper(p, unprocess, s + 1, e);
            for (vector<int> v : ret)
                mergeArr.push_back(v);
        }
        return mergeArr;
    }
};

int main()
{
    system("cls");
    vector<int> arr = {1};
    Solution s;
    vector<vector<int>> ans = s.permute(arr);
    cout << endl;
    for (vector<int> arr : ans)
    {
        for (int a : arr)
            cout << a << ", ";
        cout << endl;
    }
}