#include <iostream>
#include <queue>
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
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
            return false;

        int rem = targetSum - root->val;

        if (rem == 0 && root->left == NULL && root->right == NULL)
            return true;
        else
            return hasPathSum(root->left, rem) || hasPathSum(root->right, rem);
    }

    void preorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        cout << root->val << ", ";
        preorder(root->left);
        preorder(root->right);
    }
};

int main()
{
    system("cls");
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right = new TreeNode(8);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    Solution s;
    cout << "hasSumPath: " << s.hasPathSum(root, 22);
    // s.preorder(root);
}