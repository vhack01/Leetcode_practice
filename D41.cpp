#include <iostream>
#include <vector>
#include <set>
#include <iterator>
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        multiset<int> mset;
        for (int i = 0; i < lists.size(); i++)
        {
            ListNode *curr = lists[i];
            while (curr != NULL)
            {
                mset.insert(curr->val);
                curr = curr->next;
            }
        }
        if (mset.size() <= 0)
            return NULL;
        multiset<int>::iterator it = mset.begin();
        ListNode *curr = new ListNode(*it);
        ListNode *head_curr = curr;
        ++it;

        for (; it != mset.end(); it++)
        {
            curr->next = new ListNode(*it);
            curr = curr->next;
        }
        return head_curr;
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
    vector<ListNode *> arr;
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);
    // arr.push_back(list1);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    // arr.push_back(list2);

    ListNode *list3 = new ListNode(2);
    list3->next = new ListNode(6);
    // arr.push_back(list3);

    // arr.push_back(NULL);
    // arr.push_back(NULL);
    // arr.push_back(new ListNode(1));
    Solution s;
    ListNode *ans = s.mergeKLists(arr);
    s.display(ans);
}