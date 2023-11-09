#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {

        vector<int> arr;
        int n = nums.size();
        if (k > n)
            k %= n;
        for (int i = n - k; i < n; i++)
        {
            arr.push_back(nums[i]);
        }
        for (int i = 0; i < n - k; i++)
        {
            arr.push_back(nums[i]);
        }

        for (int i = 0; i < arr.size(); i++)
        {
            nums[i] = arr[i];
        }
    }
    void rotate2(vector<int> &nums, int k)
    {
        // OPTIMIZED CODE
        // Example:-1234567 ,k=3
        // 1.first reverse the numbers form index 0 to n-k;
        // ->4321 567
        // 2.reverse the k elements from the last
        // ->4321 765
        // 3.now reverse the whole nums;
        // ->5671234 Done Answer is here !!!!
        vector<int> arr;
        int n = nums.size();
        if (k > n)
            k %= n;

        nums.reverse(0, n - k);
    }
};
int main()
{
    system("cls");
    vector<int> arr =
        {1, 2, 3, 4, 5, 6, 7};
    // {-1};
    Solution s;
    // s.rotate(arr, 2);
    s.rotate2(arr, 3);
    for (int a : arr)
        cout << a << ", ";
}