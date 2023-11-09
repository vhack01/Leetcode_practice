#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        helper({}, candidates, 0, target, ans);
        return ans;
    }
    void helper(vector<int> process, vector<int> &candidates, int s, int target, vector<vector<int>> &ans)
    {
        if (s == candidates.size())
        {
            if (target == 0)
            {
                ans.push_back(process);
            }
            return;
        }

        if (candidates[s] <= target)
        {
            process.push_back(candidates[s]);
            helper(process, candidates, s, target - candidates[s], ans);
            process.pop_back();
        }

        helper(process, candidates, s + 1, target, ans);
    }
};
int main()
{
    system("cls");
    Solution s;
    vector<int> num = {8, 7, 4, 3};
    vector<vector<int>> arr = s.combinationSum(num, 11);
    for (vector<int> a : arr)
    {
        for (int b : a)
            cout << b << ",  ";
        cout << endl;
    }
}