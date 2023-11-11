#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{

public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        reverse(board.begin(), board.end());

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<int> q;
        q.push(1);
        vector<int> pos = getPosition(1, n);
        visited[pos[0]][pos[1]] = true;
        bool found = false;
        int moves = 0;
        while (!q.empty())
        {
            int qSize = q.size();

            for (int i = 0; i < qSize; i++)
            {
                int curr = q.front();
                if (curr == n * n)
                    return moves;
                q.pop();

                for (int i = 1; i <= 6; i++)
                {
                    if (curr + i > n * n)
                        break;
                    vector<int> pos = getPosition(curr + i, n);
                    if (visited[pos[0]][pos[1]])
                        continue;
                    visited[pos[0]][pos[1]] = true;

                    if (board[pos[0]][pos[1]] != -1)
                        q.push(board[pos[0]][pos[1]]);
                    else
                        q.push(curr + i);
                }
            }
            moves++;
        }

        return -1;
    }
    vector<int> getPosition(int sq, int len)
    {
        vector<int> pos;
        int row = (sq - 1) / len;
        int col = (sq - 1) % len;

        if (row % 2 != 0)
            col = (len - 1) - col;

        pos.push_back(row);
        pos.push_back(col);
        return pos;
    }
};

int main()
{
    system("cls");
    vector<vector<int>> board = {{-1, -1, -1, -1, -1, -1},
                                 {-1, -1, -1, -1, -1, -1},
                                 {-1, -1, -1, -1, -1, -1},
                                 {-1, 35, -1, -1, 13, -1},
                                 {-1, -1, -1, -1, -1, -1},
                                 {-1, 15, -1, -1, -1, -1}};

    Solution s;
    cout << "MinMove : " << s.snakesAndLadders(board);
}
