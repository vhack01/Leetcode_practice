#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int profit = 0;
        for (int i = 1; i < n; i++)
        {
            if (prices[i] > prices[i - 1])
                profit += (prices[i] - prices[i - 1]);
        }

        return profit;
    }
};

int main()
{
    system("cls");
    Solution s;
    vector<int> arr = {5, 2, 7, 3, 6, 1, 2, 4};
    cout << s.maxProfit(arr);
}