#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int count = nums.size();
        vector<int> left(count);
        left[0] = nums[0];

        for (int i = 1; i < count; i++)
            left[i] = left[i - 1] * nums[i-1];
        
        vector<int> right(count);
        right[count - 1] = nums[count - 1];
        for (int i = count - 2; i >=0 ; i--)
            right[i] = right[i + 1] * nums[i + 1];

        vector<int> result(count);
        for (int i = 0; i < count ; i++)
            result[i] = left[i] * right[i];        

        for (int a :result)
        {
            cout << a << " ";
        }
        
        
    }

    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        left[0] = nums[0];
        vector<int> ans(n);
        for (int i = 1; i < n; i++)
        {
            left[i] = left[i - 1] * nums[i];    
        }

        int product = nums[n - 1];
        ans[n - 1] = left[n - 2];
        for (int i = n - 2; i > 0; i--)
        {
            ans[i] = left[i - 1] * product;
            product *= nums[i];
        }
        ans[0] = product;

        return ans;
    }
};

int main() {
    system("cls");
    Solution s;
    vector<int> arr = {1,2,3,4};
    s.productExceptSelf(arr);
}