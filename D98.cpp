#include <iostream>
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL)
            return NULL;
        int len = 0;
        ListNode *curr = head;
        ListNode *end = NULL;
        while (curr->next != NULL)
        {
            len++;
            curr = curr->next;
        }
        len++;

        k = k % len;
        cout << "len: " << len << ", k:" << k << endl;

        end = curr;

        curr = head;
        ListNode *prev = NULL;

        cout << "cond: " << ((len - k) % len) << endl;

        for (int i = 0; i < ((len - k) % len); i++)
        {
            prev = curr;
            curr = curr->next;
            cout << "prev : " << prev->val << ", curr: " << curr->val << endl;
        }

        if (k != 0)
        {
            end->next = head;
            prev->next = NULL;
        }
        cout << "curr: " << curr->val << endl;
        return curr;
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
    ListNode *curr = s.rotateRight(root, 1);
    while (curr != NULL)
    {
        cout << curr->val << ", ";
        curr = curr->next;
    }
}