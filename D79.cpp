#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int r = board.size();
        int c = board[0].size();
        vector<vector<bool>> track(r, vector<bool>(c, false));
        for (int i = 0; i < r * c; i++)
        {
            int row = i / c;
            int col = i % c;

            if (board[row][col] == word[0])
            {
                if (search(row, col, board, word))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool search(int row, int col, vector<vector<char>> &board, string word)
    {
        if (word.size() == 0)
            return true;
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[0])
            return false;

        board[row][col] = '#';
        bool opt1 = search(row, col + 1, board, word.substr(1));
        bool opt2 = search(row + 1, col, board, word.substr(1));
        bool opt3 = search(row, col - 1, board, word.substr(1));
        bool opt4 = search(row - 1, col, board, word.substr(1));
        board[row][col] = word[0];
        return opt1 || opt2 || opt3 || opt4;
    }
};
int main()
{
    system("cls");
    Solution s;
    vector<vector<char>> matrix = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    cout << "isFound: " << s.exist(matrix, "ABCCED");
}