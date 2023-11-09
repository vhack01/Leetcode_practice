#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct Node
{
    int val;
    Node *next;
    Node *random;
    Node(int k, Node *r)
    {
        val = k;
        next = NULL;
        random = r;
    }
};
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *curr = head;
        vector<Node *> arr;
        map<Node *, int> m;
        int count = 0;
        while (curr != NULL)
        {
            arr.push_back(curr);
            m[curr] = count++;
            curr = curr->next;
        }
        for (Node *a : arr)
            cout << a << ", " << endl;
        cout << endl;
        for (auto a : m)
            cout << a.first << ":" << a.second << endl;

        vector<Node *> arr2;
        // arr[0]->val, m[arr[0]->random]=0

        curr = new Node(arr[0]->val, NULL);
        arr2.push_back(curr);
        Node *chead = curr;
        for (int i = 1; i < arr.size(); i++)
        {
            curr->next = new Node(arr[i]->val, NULL);
            arr2.push_back(curr->next);
            curr = curr->next;
        }
        for (int i = 0; i < arr2.size(); i++)
        {
            Node *temp = arr[i]->random;
            cout << "temp: " << temp << ", ";
            if (temp != NULL)
            {
                cout << "index: " << arr2[m[temp]] << "\n";
                arr2[i]->random = arr2[m[temp]];
            }
            else
            {
                cout << "index: "
                     << "NULL"
                     << "\n";
                arr2[i]->random = NULL;
            }
        }

        return chead;
    }
    void display(Node *head)
    {
        cout << "\n\nOutput: ";
        while (head != NULL)
        {
            cout << head->val << ", next: " << head->next << ", randome: " << head->random << endl;
            head = head->next;
        }
    }
};

int main()
{
    system("cls");

    Node *node = new Node(7, NULL);
    node->next = new Node(13, NULL);
    node->next->next = new Node(11, NULL);
    node->next->next->next = new Node(10, NULL);
    node->next->next->next->next = new Node(1, NULL);

    node->random = NULL;
    node->next->random = node;
    node->next->next->random = node->next->next->next->next;
    node->next->next->next->random = node->next->next;
    node->next->next->next->next->random = node;

    Solution s;
    Node *ans = s.copyRandomList(node);
    s.display(ans);
}