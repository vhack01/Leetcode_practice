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
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        return helper(root->left, root->right);
    }
    bool helper(TreeNode *left, TreeNode *right)
    {
        if (left == NULL && right == NULL)
            return true;
        else if (left == NULL && right != NULL)
            return false;
        else if (left != NULL && right == NULL)
            return false;
        else if (left->val != right->val)
            return false;
        return helper(left->left, right->right) && helper(left->right, right->left);
    }
};

int main()
{
    system("cls");
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right = new TreeNode(2);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution s;
    cout << "isSymmetric: " << s.isSymmetric(root);
}