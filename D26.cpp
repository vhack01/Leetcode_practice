#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        cout << "m=r: " << m << ", n=c: " << n << endl;
        int s = 0, e = m * n - 1;
        cout << "s: " << s << ", e: " << e << endl;
        while (s <= e)
        {
            int mid = (s + e) / 2;
            int r = mid / n;
            int c = mid % n;
            cout << "mid: " << mid << ", r: " << r << ", c: " << c << endl;
            if (matrix[r][c] == target)
                return true;
            else if (matrix[r][c] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return false;
    }
};
int main()
{
    system("cls");
    vector<vector<int>> nums = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int k = 7;
    cout << "ans:" << Solution::searchMatrix(nums, k);
}

// int l = 0, u = matrix.size() * matrix[0].size() - 1;
// while (l <= u)
// {
//     int mid = (l + u) / 2;
//     int r = mid / matrix[0].size();
//     int c = mid % matrix[0].size();
//     if (matrix[r][c] == target)
//         return true;
//     else if (matrix[r][c] < target)
//         l = mid + 1;
//     else
//         u = mid - 1;
// }
// return false;