#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);

        // left
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                left[i] = left[i - 1] + 1;
            }
        }

        // right
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                right[i] = right[i + 1] + 1;
            }
        }

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += max(left[i], right[i]);
        }

        return sum;
    }
};

int main()
{
    system("cls");
    vector<int> arr = {1, 2, 6, 5, 4, 3, 1};
    Solution s;
    cout << "minCandy: " << s.candy(arr);
}