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
    int sumNumbers(TreeNode *root)
    {
        return helper(root, 0);
    }
    int helper(TreeNode *root, int num)
    {
        if (root == NULL)
            return 0;

        int left = helper(root->left, num * 10 + root->val);
        int right = helper(root->right, num * 10 + root->val);

        return (left + right) == 0 ? num * 10 + root->val : left + right;
    }
};

int main()
{
    system("cls");
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);
    root->right = new TreeNode(0);

    Solution s;
    cout << "Total Sum: " << s.sumNumbers(root);
}