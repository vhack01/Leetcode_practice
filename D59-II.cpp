#include <iostream>
#include <vector>
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> arr;
        if (root == NULL)
            return arr;

        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        TreeNode *prev = NULL;
        vector<int> sub;
        while (q.size() > 0)
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr == NULL)
            {
                arr.push_back(sub);
                if (!q.empty())
                    q.push(NULL);
                sub.clear();
            }
            else
            {
                sub.push_back(curr->val);
                prev = curr;
                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
            }
        }
        return arr;
    }
};

int main()
{
    system("cls");
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(6);

    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    Solution s;
    vector<vector<int>> ans = s.levelOrder(root);
    for (vector<int> arr : ans)
    {
        for (int a : arr)
            cout << a << ", ";

        cout << endl;
    }
}