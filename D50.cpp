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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (inorder.size() == 0 || preorder.size() == 0)
            return NULL;

        TreeNode *root = new TreeNode(preorder[0]);
        int index = -1;
        vector<int> in;
        for (int i = 0; i < inorder.size(); i++)
        {
            if (preorder[0] == inorder[i])
            {
                index = i;
                break;
            }
            else
            {
                in.push_back(inorder[i]);
            }
        }
        vector<int> pre;
        for (int i = 1; i <= in.size(); i++)
        {
            pre.push_back(preorder[i]);
        }

        root->left = buildTree(pre, in);
        vector<int> rin;
        for (int i = index + 1; i < inorder.size(); i++)
        {
            rin.push_back(inorder[i]);
        }
        vector<int> rpre;
        for (int i = 1 + in.size(); i < preorder.size(); i++)
        {
            rpre.push_back(preorder[i]);
        }

        root->right = buildTree(rpre, rin);

        return root;
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
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    Solution s;
    TreeNode *ans = s.buildTree(preorder, inorder);
    s.preOrder(ans);
}