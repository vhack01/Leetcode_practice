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
    vector<ListNode *> convertToArray(ListNode *head)
    {
        vector<ListNode *> arr;
        ListNode *curr = head;
        while (curr != NULL)
        {
            arr.push_back(curr);
            curr = curr->next;
        }

        return arr;
    }
    ListNode *reorderList(ListNode *head)
    {
        if (head->next == NULL || head->next->next == NULL)
            return head;

        vector<ListNode *> arr = convertToArray(head);
        cout << "size : " << arr.size() << endl;
        int s = 0, e = arr.size() - 1;
        ListNode *curr = head;

        ListNode *start = NULL, *end = NULL;
        while (s < e)
        {
            cout << "\n\ns: " << s << ", e:" << e << endl;
            start = arr[s];
            end = arr[e];
            ListNode *temp = start->next;
            cout << "start: " << start->val << ", ";
            start->next = end;
            cout << "start->next->val: " << start->next->val << ", ";
            end->next = temp;
            cout << "start->next->next->val: " << start->next->next->val << ", ";
            ++s;
            --e;
            end = arr[e];
            end->next = NULL;
            if (e - s < 2)
                break;
        }
        return head;
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

    ListNode *node = new ListNode(1);
    node->next = new ListNode(2);

    Solution s;
    ListNode *ans = s.reorderList(node);
    s.display(ans);
}