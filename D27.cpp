#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static int minEatingSpeed(vector<int> &piles, int h)
    {

        int m = INT_MIN;
        for (int a : piles)
        {
            m = max(m, a);
        }
        int s = 1, e = m;
        int k = 0;
        cout << "max: " << m << endl;
        while (s <= e)
        {
            cout << "s: " << s << ", e: " << e << endl;
            int mid = (s + e) / 2;
            long long int time = computeTime(piles, mid);
            cout << "mid: " << mid << ", time: " << time << endl;
            if (time <= h)
            {
                k = mid;
                e = mid - 1;
            }
            else
                s = mid + 1;
            cout << "\n\n";
        }
        cout << "k: " << k << endl;
    }
    static long long int computeTime(vector<int> &piles, int k)
    {
        long long int time = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            time += (piles[i] / k) + ((piles[i] % k) != 0);
        }
        return time;
    }
};

int main()
{
    system("cls");
    vector<int> arr =
        // {3, 6, 7, 11};
        {805306368, 805306368, 805306368};
    // 1000000000
    Solution::minEatingSpeed(arr, 1000000000);
}