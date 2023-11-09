#include <iostream>
#include <vector>
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *curr = head;
        vector<ListNode *> arr;
        while (curr != NULL)
        {
            arr.push_back(curr);
            curr = curr->next;
        }
        int len = arr.size();
        cout << "size: " << len << endl;
        curr = arr[len - n];
        cout << "val: " << curr->val << endl;
        if (len != n)
        {
            ListNode *prev = arr[(len - n) - 1];
            prev->next = curr->next;
            delete curr;
        }
        else
        {
            head = curr->next;
        }

        return head;
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
    // system("cls");

    ListNode *node = new ListNode(1);
    node->next = new ListNode(2);
    node->next->next = new ListNode(3);
    node->next->next->next = new ListNode(4);
    node->next->next->next->next = new ListNode(5);
    node->next->next->next->next->next = new ListNode(6);

    Solution s;
    ListNode *ans = s.removeNthFromEnd(node, 1);
    s.display(ans);
}