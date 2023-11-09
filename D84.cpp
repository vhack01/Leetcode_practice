#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        if (prerequisites.size() == 0)
            return true;
        vector<vector<int>> graph(numCourses);
        for (vector<int> arr : prerequisites)
        {
            graph[arr[1]].push_back(arr[0]);
        }

        // for (vector<int> arr : graph)
        // {
        //     for (int a : arr)
        //         cout << a << ", ";
        //     cout << endl;
        // }

        vector<bool> visisted(numCourses, false);
        vector<bool> connected(numCourses, false);

        for (vector<int> arr : prerequisites)
        {
            if (!visisted[arr[1]])
            {
                if (isLoop(graph, arr[1], visisted, connected))
                    return false;
            }
        }

        return true;
    }

    bool isLoop(vector<vector<int>> &graph, int src, vector<bool> &visited, vector<bool> &connected)
    {
        visited[src] = true;
        connected[src] = true;
        for (int v : graph[src])
        {
            if (!visited[v] && isLoop(graph, v, visited, connected))
                return true;
            else if (connected[v])
                return true;
        }
        connected[src] = false;
        return false;
    }
};

int main()
{
    system("cls");
    Solution s;
    vector<vector<int>> prerequisites =
        // {{1, 0}};

        {{1, 4},
         {2, 4},
         {3, 1},
         {3, 2}};

    // {{1, 0}, {0, 1}};

    // {{0, 10}, {3, 18}, {5, 5}, {6, 11}, {11, 14}, {13, 1}, {15, 1}, {17, 4}};

    int num = 5;
    cout << "canFinish: " << s.canFinish(num, prerequisites) << endl;
}