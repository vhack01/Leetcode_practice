#include <iostream>
#include <vector>
#include <climits>
#include <stack>

using namespace std;

class Solution
{
public:
    int largestRectangleArea2(vector<int> &heights)
    {
        // O(N^2)
        int count = heights.size();
        if (count == 1)
            return heights[0];
        int rmax = INT_MIN;
        for (int i = 0; i < count; i++)
        {
            int sum = 0;
            int prevSum = INT_MIN;
            for (int j = 0; j < count; j++)
            {
                if (heights[j] >= heights[i])
                {
                    sum += heights[i];
                }
                else
                {
                    if (sum != 0)
                    {
                        prevSum = max(prevSum, sum);
                        sum = 0;
                    }
                }
            }
            sum = max(prevSum, sum);
            cout << heights[i] << " : " << sum << endl;
            rmax = max(rmax, sum);
        }

        cout << "\nsum: " << rmax << endl;
    }

    int largestRectangleArea(vector<int> &heights)
    {
        int count = heights.size();

        vector<int> rb(count);
        stack<int> st;
        st.push(count - 1);
        rb[count - 1] = count;

        // next smallest element in right
        for (int i = count - 2; i >= 0; i--)
        {
            while (st.size() > 0 && heights[i] <= heights[st.top()])
            {
                st.pop();
            }

            if (st.size() == 0)
                rb[i] = count;
            else
                rb[i] = st.top();
            st.push(i);
        }

        vector<int> lb(count);
        stack<int> st2;
        st2.push(0);
        lb[0] = -1;

        for (int i = 1; i < count; i++)
        {
            while (st2.size() > 0 && heights[i] <= heights[st2.top()])
            {
                st2.pop();
            }

            if (st2.size() == 0)
                lb[i] = -1;
            else
                lb[i] = st2.top();
            st2.push(i);
        }

        int max_area = INT_MIN;
        int area;
        for (int i = 0; i < count; i++)
        {
            area = ((rb[i] - lb[i]) - 1) * heights[i];
            max_area = max(max_area, area);
        }
        cout << "max_area: " << max_area << endl;
    }
};

int main()
{
    system("cls");
    Solution s;
    vector<int> arr = {1, 1};
    s.largestRectangleArea(arr);
}