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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        ListNode *ans = NULL;

        if (list1->val < list2->val)
        {
            ans = new ListNode(list1->val);
            list1 = list1->next;
        }
        else
        {
            ans = new ListNode(list2->val);
            list2 = list2->next;
        }

        ListNode *ans_head = ans;

        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val < list2->val)
            {
                cout << "l1: " << list1->val << ", ";
                ans->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            else
            {
                cout << "l2: " << list2->val << ", ";
                ans->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            ans = ans->next;
        }
        cout << endl;
        while (list1 != NULL)
        {
            cout << "l1: " << list1->val << ", ";
            ans->next = new ListNode(list1->val);
            ans = ans->next;
            list1 = list1->next;
        }
        while (list2 != NULL)
        {
            cout << "l2: " << list2->val << ", ";
            ans->next = new ListNode(list2->val);
            ans = ans->next;
            list2 = list2->next;
        }

        return ans_head;
    }

    void display(ListNode *head)
    {
        cout << "\nOutput: ";
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
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode *list2 = NULL;

    Solution s;

    ListNode *ans = s.mergeTwoLists(list1, list2);
    s.display(ans);
}

// if (list1 == NULL && list2 == NULL)
//             return NULL;
//         multiset<int> ms;
//         ListNode *curr = list1;
//         while (curr != NULL)
//         {
//             ms.insert(curr->val);
//             curr = curr->next;
//         }
//         curr = list2;
//         while (curr != NULL)
//         {
//             ms.insert(curr->val);
//             curr = curr->next;
//         }

//         ListNode *list = new ListNode(*ms.begin());
//         ListNode *head = list;
//         for (auto it = ms.begin(); ++it != ms.end();)
//         {
//             list->next = new ListNode(*(it));
//             list = list->next;
//         }
//         return head;