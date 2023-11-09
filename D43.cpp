#include <iostream>
#include <stack>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int k)
    {
        val = k;
        left = right = NULL;
    }
};

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL)
            return root;

        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
    void preOrder(TreeNode *root)
    {
        if (root == NULL)
            return;
        cout << root->val << ", ";
        preOrder(root->left);
        preOrder(root->right);
    }
};

int main()
{
    system("cls");
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    Solution s;
    TreeNode *ans = s.invertTree(root);
    s.preOrder(ans);
}