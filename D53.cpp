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
    void flatten(TreeNode *root)
    {
        if (root == NULL)
            return;
        helper(root);
    }
    TreeNode *helper(TreeNode *root)
    {
        if (root == NULL)
            return NULL;

        TreeNode *ltree = helper(root->left);
        TreeNode *rtree = helper(root->right);

        if (ltree != NULL && rtree != NULL)
        {
            TreeNode *temp = root->right;
            root->right = root->left;
            root->left = NULL;
            ltree->right = temp;
            return rtree ? rtree : ltree;
        }
        else if (ltree == NULL && rtree == NULL)
        {
            return root;
        }
        else if (ltree == NULL)
        {
            return rtree;
        }
        else
        {
            root->right = root->left;
            root->left = NULL;
            return ltree;
        }
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
    // system("cls");
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    // root->left->left = new TreeNode(3);
    // root->left->right = new TreeNode(4);

    // root->right = new TreeNode(5);
    // root->right->right = new TreeNode(6);

    Solution s;
    s.flatten(root);
    s.preorder(root);
}