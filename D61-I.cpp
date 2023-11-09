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
    int mD = INT_MAX;

public:
    int getMinimumDifference(TreeNode *root)
    {
        TreeNode *prev = NULL;
        helper(root, prev);
        return mD;
    }

    // inorder helper
    void helper(TreeNode *root, TreeNode *&prev)
    {
        if (root == NULL)
            return;
        // LEFT, ROOT, RIGHT
        helper(root->left, prev);
        if (prev != NULL)
        {
            mD = min(mD, abs(prev->val - root->val));
        }
        prev = root;
        helper(root->right, prev);
    }

    // int getMinimumDifference1(TreeNode *root)
    // {
    //     vector<int> in = inOrder(root);
    //     int mini = INT_MAX;
    //     for (int i = 1; i < in.size(); i++)
    //     {
    //         int n = abs(in[i - 1] - in[i]);
    //         mini = min(mini, n);
    //     }
    //     return mini;
    // }
    // vector<int> inOrder(TreeNode *root)
    // {
    //     if (root == NULL)
    //         return {};

    //     vector<int> arr;
    //     vector<int> left = inOrder(root->left);

    //     for (int a : left)
    //         arr.push_back(a);
    //     arr.push_back(root->val);

    //     vector<int> right = inOrder(root->right);
    //     for (int a : right)
    //         arr.push_back(a);
    //     return arr;
    // }
};

int main()
{
    system("cls");
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right = new TreeNode(6);

    Solution s;
    cout << "min: " << s.getMinimumDifference(root);
}