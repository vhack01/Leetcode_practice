#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {

        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n * m; i++)
        {
            int row = i / n;
            int col = i % n;

            if (grid[row][col] == '1')
            {
                search(row, col, grid);
                ans += 1;
            }
        }

        return ans;
    }

    void search(int row, int col, vector<vector<char>> &grid)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size())
            return;
        if (grid[row][col] == '0')
            return;
        grid[row][col] = '0';

        search(row, col + 1, grid); // Right
        search(row + 1, col, grid); // Down
        search(row, col - 1, grid); // Left
        search(row - 1, col, grid); /// Up
    }
};
int main()
{
    system("cls");
    Solution s;
    string num = "";
    vector<vector<char>> board =
        // {
        //     {"1", "1", "1", "1", "0"},
        //     {"1", "1", "0", "1", "0"},
        //     {"1", "1", "0", "0", "0"},
        //     {"0", "0", "0", "0", "0"}};
        {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'}};

    cout << "island: " << s.numIslands(board);
}