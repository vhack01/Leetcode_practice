#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < m; i++)
        {
            if (board[0][i] == 'O')
            {
                dfs(0, i, board);
            }
        }
        cout << "1" << endl;
        for (int i = 0; i < n; i++)
        {
            if (board[i][m - 1] == 'O')
            {
                dfs(i, m - 1, board);
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (board[n - 1][i] == 'O')
            {
                dfs(n - 1, i, board);
            }
        }
        for (int i = 1; i < n; i++)
        {
            if (board[i][0] == 'O')
            {
                dfs(i, 0, board);
            }
        }

        cout << "Before: " << endl;
        for (vector<char> arr : board)
        {
            for (char ch : arr)
                cout << ch << ", ";
            cout << endl;
        }

        for (int i = 0; i < n * m; i++)
        {
            int row = i / m;
            int col = i % m;
            if (board[row][col] == '#')
                board[row][col] = 'O';
            else if (board[row][col] == 'O')
                board[row][col] = 'X';
        }

        cout << "After: " << endl;
        for (vector<char> arr : board)
        {
            for (char ch : arr)
                cout << ch << ", ";
            cout << endl;
        }
    }

    void dfs(int row, int col, vector<vector<char>> &board)
    {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
            return;

        if (board[row][col] == 'X')
            return;
        if (board[row][col] == '#')
            return;

        board[row][col] = '#';
        dfs(row, col + 1, board);
        dfs(row + 1, col, board);
        dfs(row, col - 1, board);
        dfs(row - 1, col, board);
    }
};
int main()
{
    system("cls");
    Solution s;
    string num = "";
    vector<vector<char>> board =
        // {{'X'}};

        // {{'X', 'X', 'X', 'X'},
        //  {'X', 'O', 'O', 'X'},
        //  {'X', 'X', 'O', 'X'},
        //  {'X', 'O', 'X', 'X'}};

        // {{'X', 'X', 'X'}, {'X', 'X', 'X'}, {'X', 'X', 'X'}};

        // {{'X', 'O', 'X'}, {'X', 'O', 'X'}, {'X', 'O', 'X'}};

        // {{'X', 'O', 'X'}, {'O', 'X', 'O'}, {'X', 'O', 'X'}};

        // {{'O', 'O', 'O', 'O', 'X', 'X'},
        //  {'O', 'O', 'O', 'O', 'O', 'O'},
        //  {'O', 'X', 'O', 'X', 'O', 'O'},
        //  {'O', 'X', 'O', 'O', 'X', 'O'},
        //  {'O', 'X', 'O', 'X', 'O', 'O'},
        //  {'O', 'X', 'O', 'O', 'O', 'O'}};

        {{'X', 'O', 'X', 'O', 'X', 'O'}, {'O', 'X', 'O', 'X', 'O', 'X'}, {'X', 'O', 'X', 'O', 'X', 'O'}, {'O', 'X', 'O', 'X', 'O', 'X'}};
    s.solve(board);
}