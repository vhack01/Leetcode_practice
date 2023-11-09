#include <iostream>
#include <stack>
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head->next == NULL)
            return head;
        ListNode *curr = head;
        stack<int> stk;
        int count = 0;
        ListNode *ans = NULL;
        ListNode *ans_head = NULL;
        while (curr != NULL)
        {
            stk.push(curr->val);
            cout << "\ncurr: " << curr->val << "->";
            count++;

            while (count == k && stk.size() != 0)
            {
                if (ans_head == NULL)
                {
                    ans = new ListNode(stk.top());
                    stk.pop();
                    ans_head = ans;
                    cout << ans->val << "->";
                }
                if (stk.size() == 0)
                {
                    count = 0;
                    break;
                }
                ans->next = new ListNode(stk.top());
                stk.pop();
                ans = ans->next;
                cout << ans->val << "->";
                if (stk.size() == 0)
                {
                    count = 0;
                    break;
                }
            }
            curr = curr->next;
        }
        // cout << "size: " << stk.size() << endl;
        while (stk.size() != 0)
        {
            int val = stk.top();
            stk.pop();
            ListNode *temp = ans->next;
            ans->next = new ListNode(val);
            ans->next->next = temp;
        }

        return ans_head;
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
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    // list1->next->next = new ListNode(3);
    // list1->next->next->next = new ListNode(4);
    // list1->next->next->next->next = new ListNode(5);

    Solution s;
    ListNode *ans = s.reverseKGroup(list1, 2);
    s.display(ans);
}