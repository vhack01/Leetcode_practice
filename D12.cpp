#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <iomanip>

using namespace std;

class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        map<int, double> m;
        int count = position.size();
        int fleet = 0;
        double prevTime = -1;
        for (int i = 0; i < count; i++)
            m[position[i]] = (target - position[i]) / (double)speed[i];

        cout << endl;
        for (auto it = m.rbegin(); it != m.rend(); it++)
            cout << it->first << " : " << it->second << endl;

        cout << endl;

        for (auto it = m.rbegin(); it != m.rend(); it++)
        {
            cout << "compare: " << ((double)it->second > (double)prevTime) << endl;
            if (it->second > prevTime)
            {
                fleet++;
                prevTime = it->second;
            }
        }

        cout << "fleet: " << fleet << endl;
    }
};

int main()
{
    system("cls");

    Solution s;
    int target = 17;
    vector<int> position = {8, 12, 16, 11, 7};
    vector<int> speed = {6, 9, 10, 9, 7};
    s.carFleet(target, position, speed);
}