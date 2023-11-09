#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> ans;
        vector<vector<int>> graph(numCourses);
        for (vector<int> arr : prerequisites)
        {
            graph[arr[1]].push_back(arr[0]);
        }

        vector<bool> visited(numCourses, false);
        stack<int> stk;
        vector<bool> connected(numCourses, false);

        for (vector<int> arr : prerequisites)
        {
            if (!visited[arr[1]])
            {
                if (isCycle(graph, arr[1], visited, connected))
                {
                    cout << "CYCLE" << endl;
                    return {};
                }
                // topoSort(graph, arr[1], visited, stk);
            }
        }

        cout << "NO CYCLE" << endl;

        vector<bool> topo_visited(numCourses, false);
        for (vector<int> arr : prerequisites)
        {
            if (!topo_visited[arr[1]])
            {
                topoSort(graph, arr[1], topo_visited, stk);
            }
        }

        cout << "curr : ";
        while (!stk.empty())
        {
            int curr = stk.top();
            cout << curr << " , ";
            stk.pop();
            ans.push_back(curr);
        }

        if (ans.size() != numCourses)
        {
            for (int i = 0; i < topo_visited.size(); i++)
            {
                if (!topo_visited[i])
                {
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }

    bool isCycle(vector<vector<int>> &graph, int src, vector<bool> &visited, vector<bool> &connected)
    {
        visited[src] = true;
        connected[src] = true;

        for (int v : graph[src])
        {
            if (!visited[v] && isCycle(graph, v, visited, connected))
            {
                return true;
            }
            else if (connected[v])
                return true;
        }
        connected[src] = false;
        return false;
    }

    void topoSort(vector<vector<int>> &graph, int src, vector<bool> &visited, stack<int> &stk)
    {
        visited[src] = true;
        for (int v : graph[src])
        {
            if (!visited[v])
            {
                topoSort(graph, v, visited, stk);
            }
        }
        stk.push(src);
    }
};

int main()
{
    system("cls");
    Solution s;
    vector<vector<int>> arr =
        // {};
        // {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
        // {{0, 1}, {1, 0}};
        // {{1, 0}};
        {{2, 1}, {1, 0}};

    vector<int>
        ret = s.findOrder(3, arr);
    for (int a : ret)
        cout << a << ", ";
}