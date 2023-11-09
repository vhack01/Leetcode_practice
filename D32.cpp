#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int k)
    {
        val = k;
        next = NULL;
    }
};
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL)
            return head;

        ListNode *prev = NULL;
        while (head != NULL)
        {
            ListNode *ptr = new ListNode(head->val);
            ptr->next = prev;
            prev = ptr;
            head = head->next;
        }
        return prev;
    }

    void display(ListNode *head)
    {
        while (head != NULL)
        {
            cout << head->val << ", ";
            head = head->next;
        }
    }
};

int main()
{
    system("cls");
    ListNode *start = new ListNode(1);
    start->next = new ListNode(2);
    start->next->next = new ListNode(3);
    start->next->next->next = new ListNode(4);
    start->next->next->next->next = new ListNode(5);
    Solution s;

    ListNode *ans = s.reverseList(NULL);
    s.display(ans);
}
