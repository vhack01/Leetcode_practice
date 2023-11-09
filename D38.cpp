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
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
            return false;
        // floyd Algorithm
        ListNode *slow = head;
        ListNode *fast = head;

        while ((slow != NULL) && (fast != NULL) && (fast->next != NULL) && (fast->next->next != NULL))
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
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

    ListNode *list1 = new ListNode(3);
    list1->next = new ListNode(2);

    Solution s;
    cout << "restult: " << s.hasCycle(list1);
}