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
    int maxPathSum(TreeNode *root)
    {
        int maxi = INT_MIN;
        helper(root, maxi);
        return maxi;
    }
    int helper(TreeNode *root, int &maxi)
    {
        if (root == NULL)
            return 0;

        int lsum = helper(root->left, maxi);
        int rsum = helper(root->right, maxi);

        maxi = max(maxi, lsum + rsum + root->val);
        return max(lsum, rsum) + root->val;
    }
};

int main()
{
    system("cls");
    // TreeNode *root = new TreeNode(-10);
    // root->left = new TreeNode(9);

    // root->right = new TreeNode(20);
    // root->right->left = new TreeNode(15);
    // root->right->right = new TreeNode(7);

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(-2);
    root->left->right = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->left->left = new TreeNode(-1);

    root->right = new TreeNode(-3);
    root->right->left = new TreeNode(-2);

    Solution s;
    cout << "maxPathSum: " << s.maxPathSum(root);
}