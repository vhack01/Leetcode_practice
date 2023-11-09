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
    TreeNode *connect(TreeNode *root)
    {
        if (root == NULL)
            return NULL;
        TreeNode *root_head = root;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        while (q.size() > 1)
        {
            TreeNode *curr = q.front();
            q.pop();
            if (curr == NULL)
            {
                cout << endl;
                q.push(NULL);
            }
            else
            {
                cout << curr->val << ", ";
                curr->next = q.front();
                if (curr->left != NULL)
                {
                    q.push(curr->left);
                }
                if (curr->right != NULL)
                {
                    q.push(curr->right);
                }
            }
        }
        return root_head;
    }
    void BFS(TreeNode *root)
    {
        if (root == NULL)
            return;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        while (q.size() > 1)
        {
            TreeNode *curr = q.front();

            q.pop();
            if (curr == NULL)
            {
                cout << endl;
                q.push(NULL);
            }
            else
            {
                cout << curr->val << ", ";
                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
            }
        }
    }
};

int main()
{
    system("cls");
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right = new TreeNode(3);
    root->right->right = new TreeNode(7);

    Solution s;
    s.connect(root);
}