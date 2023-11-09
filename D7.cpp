#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<char, int> umap;
        int c = 0;

        // Row validation
        for (int i = 0; i < 81; i++)
        {
            char ch = board[i / 9][i % 9];
            cout << ch << " ";
            if (ch != '.')
            {
                if (umap.find(ch) != umap.end())
                    return false;
                umap[ch] = i;
            }
            if (c == 8)
            {
                cout << endl;
                umap.clear();
                c = 0;
            }
            else
                c++;
        }
        cout << endl
             << endl;
        // Column validation
        for (int i = 0; i < 81; i++)
        {
            char ch = board[i % 9][i / 9];
            if (ch != '.')
            {
                if (umap.find(ch) != umap.end())
                    return false;
                umap[ch] = i;
            }
            if (c == 8)
            {
                umap.clear();
                c = 0;
            }
            else
                c++;
        }

        // 3x3 matrix validation
        int mr = 0, mc = 0;
        for (int i = 0; i < 81; i++)
        {
            char ch = board[(c / 3) + (mr % 3) * 3][(c % 3) + (mc % 3) * 3];
            cout << ch << " ";
            if (ch != '.')
            {
                if (umap.find(ch) != umap.end())
                    return false;
                umap[ch] = i;
            }
            if (c == 8)
            {
                cout << endl;
                c = 0;
                umap.clear();
                mc++;
                if (mc != 0 && mc % 3 == 0)
                    mr++;
            }
            else
                c++;
        }

        // cout << endl;
        return true;
    }
};

int main()
{
    system("cls");
    Solution s;

    // vector<vector<char>> board =
    // {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    //  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    //  {'.', '5', '8', '.', '.', '.', '.', '6', '.'},
    //  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    //  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    //  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    //  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    //  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    //  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    // vector<vector<char>> board = {
    //     {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
    //     {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    //     {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    //     {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    //     {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    //     {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    //     {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    //     {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    //     {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    vector<vector<char>> board =
        {
            {'.', '.', '.', '.', '.', '.', '5', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'9', '3', '.', '.', '2', '.', '4', '.', '.'},
            {'.', '.', '7', '.', '.', '.', '3', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '3', '4', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '3', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '5', '2', '.', '.'}};

    cout << "result : " << s.isValidSudoku(board);
}

// class Solution {
// public:
//     bool isValidSudoku(vector<vector<char>>& board) {
//         unordered_map<char, int> m;
//         int c = 1;

//         // Row verification
//         for (int i = 0; i < 81; i++)
//         {
//             char num = board[i / 9][i % 9];
//             if (num != '.')
//             {
//                 m[num] += 1;
//                 if (m[num] > 1)
//                     return false;
//             }
//             if (c == 9)
//             {
//                 m.clear();
//                 c = 1;
//             }
//             else
//                 c++;
//         }

//         // columns verification
//         for (int i = 0; i < 81; i++)
//         {
//             char num = board[i % 9][i / 9];
//             if (num != '.')
//             {
//                 m[num] += 1;
//                 if (m[num] > 1)
//                     return false;
//             }
//             if (c == 9)
//             {
//                 m.clear();
//                 c = 1;
//             }
//             else
//                 c++;
//         }

//         // matrix verification
//         c = 0;
//         int row = 0, col = 0;
//         int rowCount = 1, colCount = 1;
//         for (int i = 0; i < 81; i++)
//         {
//             char num = board[c / 3 + row][c % 3 + col];
//             if (num != '.')
//             {
//                 m[num] += 1;
//                 if (m[num] > 1)
//                     return false;
//             }
//             if (c == 8)
//             {
//                 m.clear();
//                 c = 0;
//                 if (col == 6)
//                 {
//                     row += 3;
//                     col = 0;
//                 }
//                 else
//                     col += 3;
//             }
//             else
//                 c++;
//         }
//         return true;
//     }
// };