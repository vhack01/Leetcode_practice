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
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
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
    root->right->right->right = new TreeNode(10);

    Solution s;
    cout << "depth: " << s.maxDepth(root);
    // s.preOrder(ans);
}