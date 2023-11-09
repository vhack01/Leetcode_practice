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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
            return false;
        if (p == NULL && q == NULL)
            return true;

        if (p->val == q->val)
        {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        else
        {
            return false;
        }
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
    TreeNode *root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);

    root1->right = new TreeNode(7);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(9);
    root1->right->right->right = new TreeNode(10);

    TreeNode *root2 = new TreeNode(4);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(1);
    root2->left->right = new TreeNode(3);

    root2->right = new TreeNode(7);
    root2->right->left = new TreeNode(6);
    root2->right->right = new TreeNode(91);
    root2->right->right->right = new TreeNode(10);

    Solution s;
    cout << "isSameTree: " << s.isSameTree(root1, root2);
    // s.preOrder(ans);
}