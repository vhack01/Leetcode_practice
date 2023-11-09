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
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!root)
            return false;
        if (isSameTree(root, subRoot))
            return true;
        else
        {
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
    }
    bool isSameTree(TreeNode *root, TreeNode *subRoot)
    {
        if (!root && !subRoot)
            return true;
        if (!root || !subRoot)
            return false;

        if (root->val == subRoot->val)
        {
            return (isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right));
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
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(1);
    // root1->left->left = new TreeNode(1);
    // root1->left->right = new TreeNode(2);
    // root1->left->right->left = new TreeNode(0);

    // root1->right = new TreeNode(5);

    TreeNode *root2 = new TreeNode(0);
    // root2->left = new TreeNode(1);
    // root2->right = new TreeNode(2);

    Solution s;
    cout << "isSubTree: " << s.isSubtree(root1, root2);
    // s.preOrder(ans);
}