#include <iostream>
#include <stack>
using namespace std;


void insertAtBottom(stack<int>& s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }

    int top = s.top();
    s.pop();

    insertAtBottom(s, x);

    s.push(top);
}

void reverseStack(stack<int>& s)
{
    if (s.empty())
    {
        return;
    }

    int top = s.top();
    s.pop();

    reverseStack(s);

    insertAtBottom(s, top);
}

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

int main()
{
    stack<int> s;

    s.push(28);
    s.push(29);
    s.push(30);
    s.push(31);

    cout << "Original Stack: ";
    printStack(s);

    reverseStack(s);

    cout << "\nReversed Stack: ";
    printStack(s);

    return 0;
}
