#include <iostream>
#include <utility>
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
        if (right == NULL)
            return left;

        return root;
    }
};

int main()
{
    system("cls");
    TreeNode *root1 = new TreeNode(6);
    root1->left = new TreeNode(2);
    root1->left->left = new TreeNode(0);
    root1->left->right = new TreeNode(4);
    root1->left->right->left = new TreeNode(3);
    root1->left->right->right = new TreeNode(5);

    root1->right = new TreeNode(8);
    root1->right->left = new TreeNode(7);
    root1->right->right = new TreeNode(9);

    Solution s;
    TreeNode *ans = s.lowestCommonAncestor(root1, new TreeNode(0), new TreeNode(7));
    cout << "LCA: " << ans->val << endl;
}