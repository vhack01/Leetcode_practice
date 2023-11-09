// 347. Top K Frequent Elements

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> umap;
        int count = nums.size();
        for (int i = 0; i < count; i++)
        {
            if(!umap[nums[i]]){
                umap[nums[i]] = 1;
            }else{
                umap[nums[i]] += 1;
            }
        }

        multimap<int , int> mmap;
        for (auto it=umap.begin(); it != umap.end(); ++it)
        {
            mmap.insert({it->second, it->first});
        }
        
        vector<int> result(k);
        int i = 0;
        for (auto it = mmap.end(); it != mmap.begin() && i < k ; i++)
        {
            --it;
            result[i] = it->second;
        }
        
        for (int it : result)
        {
            cout << it << " ";
        }
        
    }
};
 
 int main() {
    system("cls");
    vector<int> nums = {1};
    int k=1;
    Solution s;
    s.topKFrequent(nums, k);

}