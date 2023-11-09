#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    static int maxProfit(vector<int> &prices)
    {
        int minStock = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > minStock)
            {
                profit = max(profit, prices[i] - minStock);
            }
            else
            {
                minStock = prices[i];
            }
        }
        cout << profit << endl;
    }
};

int main()
{
    system("cls");
    Solution s;
    vector<int> arr = {7, 5, 4, 2, 1};
    Solution::maxProfit(arr);
}


// class Solution {
// public:
//      int maxProfit(vector<int> &prices)
//     {
//         int maxi = 0;
//         int prevMin = prices[0];

//         for (int i = 0; i < prices.size(); i++)
//         {
//             prevMin = min(prevMin, prices[i]);
//             maxi = max(prices[i] - prevMin, maxi);
//         }
//         return maxi;
//     }
// };