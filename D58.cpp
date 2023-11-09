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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return NULL;
        if (root->val == p->val || root->val == q->val)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left == NULL)
            return right;
        else if (right == NULL)
            return left;
        else
            return root;
    }
};

int main()
{
    system("cls");
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(6);

    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    Solution s;
    cout << "LCA: " << s.lowestCommonAncestor(root, new TreeNode(7), new TreeNode(4))->val;
}