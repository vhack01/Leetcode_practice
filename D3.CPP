#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result(candies.size(),true);

        int count = candies.size();
        multimap<int, int> m;
        for (int i = 0; i < count; i++)
        {
            m.insert({candies[i], i});
        }
        auto end = m.end();
        --end;
        // cout << it->first << " " << it->second << endl;
       
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            int totalCandies = it->first+extraCandies;
            if(totalCandies >= end->first) result[it->second] = true;
            else result[it->second] = false;
        }
        
        
        for(bool a: result)
            cout << a << ", ";
        
    }
};
int main() {
    Solution s;
    vector<int>candies = {2,3,5,1,3};
    // {4,2,1,1,2};
    int extraCandies = 3;
    s.kidsWithCandies(candies, extraCandies);
}