#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;
    TreeNode(int k)
    {
        val = k;
        left = right = next = NULL;
    }
};

class Solution
{

public:
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> arr = inOrder(root);
        for (int a : arr)
            cout << a << ", ";
        return arr[k - 1];
    }
    vector<int> inOrder(TreeNode *root)
    {
        if (root == NULL)
            return {};

        vector<int> arr;
        vector<int> left = inOrder(root->left);

        for (int a : left)
            arr.push_back(a);
        arr.push_back(root->val);

        vector<int> right = inOrder(root->right);
        for (int a : right)
            arr.push_back(a);
        return arr;
    }
};

class SolutionOptimize
{
    int small = -1;

public:
    int kthSmallest(TreeNode *root, int k)
    {
        int prev = 0;
        inOrder(root, prev, k);
        return small;
    }
    void inOrder(TreeNode *root, int &prev, int k)
    {
        if (root == NULL)
            return;

        vector<int> arr;
        inOrder(root->left, prev, k);
        // root
        prev += 1;

        if (prev == k)
        {
            small = root->val;
            return;
        }
        inOrder(root->right, prev, k);
    }
};

int main()
{
    system("cls");
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    root->right = new TreeNode(4);

    // Solution s;
    // cout << "Kth Smallest: " << s.kthSmallest(root, 1);
    SolutionOptimize so;
    cout << "Kth Smallest: " << so.kthSmallest(root, 1);
}