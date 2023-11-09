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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() == 0 || postorder.size() == 0)
            return NULL;
        int n = postorder.size();
        TreeNode *root = new TreeNode(postorder[n - 1]);
        cout << "root: " << postorder[n - 1] << endl;
        int index = -1;
        vector<int> left_inorder;
        for (int i = 0; i < inorder.size(); i++)
        {
            cout << "left_inorder: " << i << endl;
            if (postorder[n - 1] == inorder[i])
            {
                index = i;
                break;
            }
            else
            {
                left_inorder.push_back(inorder[i]);
            }
        }

        // left poster
        vector<int> left_postorder;
        for (int j = 0; j < left_inorder.size(); j++)
        {
            cout << "left_postorder : " << j << endl;
            left_postorder.push_back(postorder[j]);
        }

        root->left = buildTree(left_inorder, left_postorder);

        vector<int> right_inorder;
        for (int i = index + 1; i < inorder.size(); i++)
        {
            cout << "right_inorder: " << i << endl;
            right_inorder.push_back(inorder[i]);
        }
        // right postorder
        vector<int> right_postorder;

        for (int i = left_inorder.size(); i < n - 1; i++)
        {
            cout << "right_postorder: " << i << endl;
            right_postorder.push_back(postorder[i]);
        }
        root->right = buildTree(right_inorder, right_postorder);

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
    vector<int> inorder = {3, 2, 1};
    vector<int> postorder = {3, 2, 1};
    Solution s;
    TreeNode *ans = s.buildTree(inorder, postorder);
    s.preOrder(ans);
}