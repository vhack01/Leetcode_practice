#include <iostream>
#include <stack>
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
};

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;
        int count = 1;
        ListNode *curr = head;
        stack<ListNode *> st;
        ListNode *prev = NULL;
        while (curr != NULL)
        {
            if (count >= left && count <= right)
            {
                st.push(curr);
            }
            if (count < left)
                prev = curr;
            count++;
            curr = curr->next;
        }

        ListNode *temp = st.top()->next;
        if (prev == NULL)
        {
            head = st.top();
            prev = st.top();
            st.pop();
        }
        while (!st.empty())
        {
            ListNode *c = st.top();
            st.pop();

            prev->next = c;
            prev = prev->next;
        }
        prev->next = temp;

        return head;
    }
};

int main()
{
    system("cls");

    Solution s;
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    root->next->next->next->next = new ListNode(5);
    ListNode *curr = s.reverseBetween(root, 1, 5);
    while (curr != NULL)
    {
        cout << curr->val << ", ";
        curr = curr->next;
    }
}