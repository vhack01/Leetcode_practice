#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    static double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> merged = mergeArray(nums1, nums2);

        int size = merged.size();
        if (size % 2 == 0)
        {
            return (double)(merged[size / 2] + merged[((size) / 2) - 1]) / 2;
        }
        else
            return (double)(merged[size / 2]);
    }
    static vector<int> mergeArray(vector<int> &nums1, vector<int> &nums2)
    {
        // O(M+N)
        int a = 0, b = 0;
        vector<int> ans;
        while (a < nums1.size() && b < nums2.size())
        {
            if (nums1[a] <= nums2[b])
                ans.push_back(nums1[a++]);
            else
                ans.push_back(nums2[b++]);
        }

        while (a < nums1.size())
            ans.push_back(nums1[a++]);
        while (b < nums2.size())
            ans.push_back(nums2[b++]);

        for (int a : ans)
            cout << a << ", ";

        return ans;
    }
};

int main()
{
    system("cls");
    vector<int> arr1 = {1, 2};
    vector<int> arr2 = {3, 4};
    cout << "\nResult : " << Solution::findMedianSortedArrays(arr1, arr2);
}