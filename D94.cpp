#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node(bool v = false, bool leaf = false)
    {
        val = v;
        isLeaf = leaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
};

class Solution
{
public:
    Node *construct(vector<vector<int>> &grid)
    {
        if (grid.size() == 1)
        {
            cout << "1" << endl;
            Node *root = new Node(1, false);
            return root;
        }
        int n = grid.size();
        Node *root = new Node(grid[0][0], true);

        if (!isSame(grid, 0, 0, n))
        {
            root->val = 1;
            root->isLeaf = false;
            helper(grid, 0, 0, n / 2, root);
        }
        return root;
    }
    void helper(vector<vector<int>> &grid, int row, int col, int len, Node *parent)
    {
        // topleft
        if (isSame(grid, row, col, len))
        {
            cout << "TopLeft : r=" << row << ", c=" << col << endl;
            Node *node = new Node(grid[row][col], true);
            parent->topLeft = node;
        }
        else
        {
            cout << "false" << endl;
            Node *node = new Node(1, false);
            parent->topLeft = node;
            helper(grid, row, col, len / 2, node);
        }

        // topRight
        if (isSame(grid, row, (col + len), len))
        {
            cout << "topRight : r=" << row << ", c=" << (col + len) << endl;
            Node *node = new Node(grid[row][col + len], true);
            parent->topRight = node;
        }
        else
        {
            cout << "false" << endl;
            Node *node = new Node(1, false);
            parent->topRight = node;
            helper(grid, row, (col + len), len / 2, node);
        }

        // bottomLeft
        if (isSame(grid, (row + len), col, len))
        {
            cout << "bottomLeft : r=" << (row + len) << ", c=" << (col) << endl;
            Node *node = new Node(grid[row + len][col], true);
            parent->bottomLeft = node;
        }
        else
        {
            cout << "false" << endl;
            Node *node = new Node(1, false);
            parent->bottomLeft = node;
            helper(grid, (row + len), (col), len / 2, node);
        }

        // bottomRight
        if (isSame(grid, (row + len), (col + len), len))
        {
            cout << "bottomRight : r=" << (row + len) << ", c=" << (col + len) << endl;
            Node *node = new Node(grid[row + len][col + len], true);
            parent->bottomRight = node;
        }
        else
        {
            cout << "false" << endl;
            Node *node = new Node(1, false);
            parent->bottomRight = node;
            helper(grid, (row + len), (col + len), len / 2, node);
        }
    }

    bool isSame(vector<vector<int>> &grid, int row, int col, int len)
    {
        for (int i = row; i < (row + len); i++)
        {
            for (int j = col; j < (col + len); j++)
            {
                if (grid[row][col] != grid[i][j])
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    system("cls");

    Solution s;
    vector<vector<int>> arr = {{0}};
    // {{1, 1},
    // {1, 1}};
    // {{1, 1, 1, 1, 0, 0, 0, 0},
    //  {1, 1, 1, 1, 0, 0, 0, 0},
    //  {1, 1, 1, 1, 1, 1, 1, 1},
    //  {1, 1, 1, 1, 1, 1, 1, 1},
    //  {1, 1, 1, 1, 0, 0, 0, 0},
    //  {1, 1, 1, 1, 0, 0, 0, 0},
    //  {1, 1, 1, 1, 0, 0, 0, 0},
    //  {1, 1, 1, 1, 0, 0, 0, 0}};
    Node *root = s.construct(arr);
    cout << "val: " << root->val << ", isLeaf : " << root->isLeaf << endl;
}