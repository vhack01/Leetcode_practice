#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int v)
    {
        val = v;
        next = NULL;
    }
    ListNode()
    {
        val = 0;
        next = NULL;
    }
};

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        set<int> st;
        ListNode *curr = head;
        while (curr != NULL)
        {
            st.insert(curr->val);
            curr = curr->next;
        }

        ListNode *root = new ListNode();
        ListNode *nhead = root;
        for (auto i = st.begin(); i != st.end();)
        {
            root->val = *i;
            if (++i != st.end())
            {
                root->next = new ListNode();
                root = root->next;
            }
        }
        cout << endl;
        return nhead;
    }
};

int main()
{
    system("cls");
    Solution s;
    ListNode *root = new ListNode(4);
    root->next = new ListNode(2);
    root->next->next = new ListNode(1);
    root->next->next->next = new ListNode(3);

    ListNode *curr = s.sortList(root);

    while (curr != NULL)
    {
        cout << curr->val << ", ";
        curr = curr->next;
    }
}