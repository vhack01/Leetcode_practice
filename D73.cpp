#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0))
            return -1;

        int n = gas.size();
        int remaining_fuel = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            remaining_fuel += cost[i] + gas[i];
            if (remaining_fuel < 0)
            {
                ans = i + 1;
                remaining_fuel = 0;
            }
        }
        return ans;
    }
};

int main()
{
    system("cls");
    Solution s;
    // vector<int> gas = {1, 2, 3, 4, 5};
    // vector<int> cost = {3, 4, 5, 1, 2};

    // vector<int> gas = {2, 3, 4};
    // vector<int> cost = {3, 4, 3};

    vector<int> gas = {5, 1, 2, 3, 4};
    vector<int> cost = {4, 4, 1, 5, 1};

    cout << "start index : " << s.canCompleteCircuit(gas, cost);
}