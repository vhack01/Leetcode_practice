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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> arr;
        if (root == NULL)
            return arr;

        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        vector<int> sub;
        int flag = 0;
        while (q.size() > 0)
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr == NULL)
            {
                if (flag)
                {
                    vector<int> temp;
                    for (int i = sub.size() - 1; i >= 0; i--)
                        temp.push_back(sub[i]);
                    arr.push_back(temp);
                    flag = 0;
                }
                else
                {
                    arr.push_back(sub);
                    flag = 1;
                }
                if (!q.empty())
                    q.push(NULL);
                sub.clear();
            }
            else
            {
                sub.push_back(curr->val);
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
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);

    root->right = new TreeNode(20);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(10);
    root->right->right->right = new TreeNode(11);

    Solution s;
    vector<vector<int>> ans = s.zigzagLevelOrder(root);
    for (vector<int> arr : ans)
    {
        for (int a : arr)
            cout << a << ", ";
        cout << endl;
    }
}