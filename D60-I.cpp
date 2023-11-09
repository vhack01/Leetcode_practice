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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> arr;
        if (root == NULL)
            return arr;

        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        double res = 0;
        int count = 0;
        while (q.size() > 0)
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr == NULL)
            {
                arr.push_back(res / count);
                if (!q.empty())
                    q.push(NULL);
                res = 0;
                count = 0;
            }
            else
            {
                count++;
                res += curr->val;
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
    root->left = new TreeNode(9);

    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    vector<double> ans = s.averageOfLevels(root);
    for (double arr : ans)
    {
        cout << (double)arr << ", ";
    }
}