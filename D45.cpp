#include <iostream>
#include <vector>
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
    int diameterOfBinaryTree(TreeNode *root)
    {
        vector<int> ans = helper(root);
        cout << "first : " << ans[0] << ", " << ans[1] << endl;
        return ans[0];
    }

    vector<int> helper(TreeNode *root)
    {
        if (root == NULL)
            return {0, 0};

        vector<int> left = helper(root->left);
        vector<int> right = helper(root->right);

        int dia = max(left[0], right[0]);

        int sum = left[1] + right[1];
        vector<int> arr(2);
        arr[0] = max(sum, dia);
        arr[1] = max(left[1], right[1]) + 1;
        return arr;
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
    cout << "depth: " << s.diameterOfBinaryTree(root);
    // s.preOrder(ans);
}