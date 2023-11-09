#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        helper({}, 1, n, k, ans);
        return ans;
    }
    void helper(vector<int> process, int s, int n, int k, vector<vector<int>> &ans)
    {
        if (process.size() == k)
        {
            ans.push_back(process);
            return;
        }
        if (s > n)
            return;

        if ((k - process.size()) > (n - s + 1))
            return;

        vector<vector<int>> arr;
        process.push_back(s);
        helper(process, s + 1, n, k, ans);
        process.pop_back();
        helper(process, s + 1, n, k, ans);
    }
};
int main()
{
    system("cls");
    Solution s;
    vector<vector<int>> arr = s.combine(20, 10);
    for (vector<int> a : arr)
    {
        for (int b : a)
            cout << b << ",  ";
        cout << endl;
    }
}