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
    bool isValid = true;

public:
    bool isValidBST(TreeNode *root)
    {
        TreeNode *prev = NULL;
        inOrder(root, prev);
        return isValid;
    }
    bool inOrder(TreeNode *root, TreeNode *&prev)
    {
        if (root == NULL)
            return true;

        bool left = inOrder(root->left, prev);
        if (left && prev != NULL)
        {
            isValid = prev->val < root->val ? true : false;
        }
        if (!isValid || !left)
        {
            return false;
        }
        prev = root;
        inOrder(root->right, prev);
    }
};

int main()
{
    system("cls");
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(4);

    Solution s;
    cout << "IsValidBST: " << s.isValidBST(root);
}