#include <iostream>
#include <stack>

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

class BSTIterator
{
    stack<TreeNode *> myStack;

public:
    BSTIterator(TreeNode *root)
    {
        TreeNode *curr = root;
        // INORDER (LEFT, ROOT, RIGHT)
        // LEFT
        pushAllLeft(curr);
    }

    void pushAllLeft(TreeNode *head)
    {
        while (head != NULL)
        {
            myStack.push(head);
            head = head->left;
        }
    }

    int next()
    {
        // ROOT
        TreeNode *curr = myStack.top();
        myStack.pop();

        // RIGHT
        pushAllLeft(curr->right);
        return curr->val;
    }

    bool hasNext()
    {
        return !myStack.empty();
    }
};

int main()
{
    system("cls");
    TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(3);

    // root->right = new TreeNode(15);
    // root->right->left = new TreeNode(9);
    // root->right->right = new TreeNode(20);

    BSTIterator *bst = new BSTIterator(root);

    // cout << "next: " << bst->next() << endl;
    // cout << "hasNext: " << bst->hasNext() << endl;
    // cout << "next: " << bst->next() << endl;
    // cout << "hasNext: " << bst->hasNext() << endl;
    // cout << "next: " << bst->next() << endl;
    // cout << "hasNext: " << bst->hasNext() << endl;
    // cout << "next: " << bst->next() << endl;
    // cout << "hasNext: " << bst->hasNext() << endl;
    // cout << "next: " << bst->next() << endl;
    // cout << "hasNext: " << bst->hasNext() << endl;

    cout << "hasNext: " << bst->hasNext() << endl;
    cout << "next: " << bst->next() << endl;
    cout << "next: " << bst->next() << endl;
}

// ----------- T: O(1) && S: O(H), H->height of tree -----------
/*class BSTIterator
{
    TreeNode *curr;
    vector<TreeNode *> arr;
    int pointer = -1;

public:
    BSTIterator(TreeNode *root)
    {
        curr = root;
        inOrder(root);
        cout << "size: " << arr.size() << endl;
    }

    void inOrder(TreeNode *head)
    {
        if (head == NULL)
            return;
        inOrder(head->left);
        arr.push_back(head);
        inOrder(head->right);
    }

    int next()
    {
        return arr[++pointer]->val;
    }

    bool hasNext()
    {
        if (pointer == (arr.size() - 1))
            return false;
        return true;
    }
};

*/