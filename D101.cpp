#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        // (n^2)
        vector<vector<int>> zerosIndex;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    vector<int> arr = {i, j};
                    zerosIndex.push_back(arr);
                }
            }
        }

        // (N^3)
        for (int i = 0; i < zerosIndex.size(); i++)
        {
            // making row zeros
            for (int row = 0; row < matrix.size(); row++)
            {
                matrix[row][zerosIndex[i][1]] = 0;
            }
            // making col zeros
            for (int col = 0; col < matrix[0].size(); col++)
            {
                matrix[zerosIndex[i][0]][col] = 0;
            }
        }
    }

    void setZeroes2(vector<vector<int>> &matrix)
    {
        // TC : O(N^2)
        // SC : O(M + N)
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> row(m, false);
        vector<bool> col(n, false);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        for (int a : row)
        {
            cout << a << ", ";
        }
        cout << endl;

        for (int a : col)
        {
            cout << a << ", ";
        }
        cout << endl;
        cout << endl;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (row[i] || col[j])
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    void setZeroesOptimal(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int col0 = 1;
        // O(N^2)
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    if (j == 0)
                    {
                        col0 = 0;
                        matrix[i][0] = 0;
                    }
                    else
                    {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }
        }

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (matrix[i][j] != 0)
                {
                    if (j == 0)
                    {
                        if ((col0 == 0 || matrix[i][0] == 0))
                            matrix[i][j] = 0;
                    }
                    else if (matrix[i][0] == 0 || matrix[0][j] == 0)
                        matrix[i][j] = 0;
                }
            }
        }
    }
};

int main()
{
    system("cls");
    vector<vector<int>> matrix =
        // {{0, 1}};
        // {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
        // {{1, 2, 3, 4}, {5, 0, 7, 8}, {0, 10, 11, 12}, {13, 14, 15, 0}};
        {{-4, -2147483648, 6, -7, 0}, {-8, 6, -8, -6, 0}, {2147483647, 2, -9, -6, -10}};
    Solution s;
    s.setZeroesOptimal(matrix);
    for (vector<int> arr : matrix)
    {
        for (int a : arr)
            cout << a << " ";
        cout << endl;
    }
}