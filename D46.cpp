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
    bool isBalanced(TreeNode *root)
    {
        pair<bool, int> ans = helper(root);
        return ans.first;
    }

    pair<bool, int> helper(TreeNode *root)
    {
        if (root == NULL)
            return {true, 0};
        pair<bool, int> left = helper(root->left);
        if (!left.first)
            return {false, 0};
        pair<bool, int> right = helper(root->right);
        if (!right.first)
            return {false, 0};

        int height = abs(left.second - right.second);
        pair<bool, int> arr;
        if (height >= 0 && height <= 1)
        {
            arr.first = true;
            arr.second = max(left.second, right.second) + 1;
            return arr;
        }
        else
        {
            return {false, 0};
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
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    root->right->right->right = new TreeNode(10);

    Solution s;
    cout << "isBalanced: " << s.isBalanced(root);
    // s.preOrder(ans);
}