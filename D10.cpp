#include <bits/stdc++.h>
using namespace std;
class MinStack
{
    vector<int> stack;
    vector<int> minStack;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (stack.size() == 0)
        {
            stack.push_back(val);
            minStack.push_back(val);
        }
        else
        {
            if (val < minStack[minStack.size() - 1])
                minStack.push_back(val);
            stack.push_back(val);
        }
    }

    void pop()
    {
        if (stack.size() > 0)
        {
            if (stack[stack.size() - 1] == minStack[minStack.size() - 1])
            {
                minStack.pop_back();
            }
            stack.pop_back();
        }
    }

    int top()
    {
        if (stack.size() > 0)
            return stack[stack.size() - 1];
    }

    int getMin()
    {
        if (minStack.size() > 0)
            return minStack[minStack.size() - 1];
    }
};

int main()
{
    system("cls");
    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);

    // cout << "top: " << minStack->top() << endl;
    // minStack->pop();
    // cout << "top: " << minStack->top() << endl;
    // minStack->pop();
    // cout << "top: " << minStack->top() << endl;
    // minStack->pop();

    cout << "min: " << minStack->getMin() << endl;
    minStack->pop();
    cout << "top: " << minStack->top() << endl;
    cout << "min: " << minStack->getMin() << endl;
}