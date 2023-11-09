#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    // Node(int _val, vector<Node*> _neighbors) {
    //     val = _val;
    //     neighbors = _neighbors;
    // }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        unordered_map<Node *, Node *> map;
        if (node == NULL)
            return node;
        if (node->neighbors.size() == 0)
        {
            Node *clone = new Node(node->val);
            return clone;
        }

        return dfs(node, map);
    }

    Node *dfs(Node *node, unordered_map<Node *, Node *> &map)
    {
        vector<Node *> neighbor;
        Node *clone = new Node(node->val);
        map[node] = clone;

        for (Node *curr : node->neighbors)
        {
            if (map.find(curr) == map.end())
            {
                neighbor.push_back(dfs(curr, map));
            }
            else
            {
                neighbor.push_back(map[curr]);
            }
        }
        clone->neighbors = neighbor;
        return clone;
    }
};
int main()
{

    system("cls");
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);

    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);

    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);

    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);

    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);

    Solution s;
    s.cloneGraph(node1);
}
