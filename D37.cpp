#include <iostream>
#include <vector>
#include <map>
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *c1 = l1;
        ListNode *c2 = l2;

        int s = c1->val + c2->val;
        int rem = 0;
        ListNode *sum = new ListNode(s % 10);
        rem = s / 10;
        ListNode *shead = sum;
        c1 = c1->next;
        c2 = c2->next;
        while (c1 != NULL && c2 != NULL)
        {
            int s = c1->val + c2->val + rem;
            sum->next = new ListNode(s % 10);
            rem = s / 10;
            sum = sum->next;
            c1 = c1->next;
            c2 = c2->next;
        }

        while (c1 != NULL)
        {
            int s = c1->val + rem;
            sum->next = new ListNode(s % 10);
            rem = s / 10;
            sum = sum->next;
            c1 = c1->next;
        }

        while (c2 != NULL)
        {
            int s = c2->val + rem;
            sum->next = new ListNode(s % 10);
            rem = s / 10;
            sum = sum->next;
            c2 = c2->next;
        }

        if (rem != 0)
        {
            sum->next = new ListNode(rem);
        }

        return shead;
    }

    void display(ListNode *head)
    {
        cout << "\n\nOutput: ";
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

    ListNode *list1 = new ListNode(9);
    list1->next = new ListNode(9);
    list1->next->next = new ListNode(9);
    list1->next->next->next = new ListNode(9);
    list1->next->next->next->next = new ListNode(9);
    list1->next->next->next->next->next = new ListNode(9);
    list1->next->next->next->next->next->next = new ListNode(9);

    ListNode *list2 = new ListNode(9);
    list2->next = new ListNode(9);
    list2->next->next = new ListNode(9);
    list2->next->next->next = new ListNode(9);

    // ListNode *list1 = new ListNode(0);

    // ListNode *list2 = new ListNode(0);

    Solution s;
    ListNode *ans = s.addTwoNumbers(list1, list2);
    s.display(ans);
}