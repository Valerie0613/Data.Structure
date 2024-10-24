#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void interleaveQueue(queue<int>& q)
{
    int n = q.size();
    vector<int> firstHalf;

    for (int i = 0; i < n / 2; ++i)
    {
        firstHalf.push_back(q.front());
        q.pop();
    }

    for (int i = 0; i < n / 2; ++i)
    {
        q.push(firstHalf[i]);
        q.push(q.front());
        q.pop();
    }
}

void printQueue(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << "Input Queue: ";
    printQueue(q);

    interleaveQueue(q);

    cout << "Rearranged Queue: ";
    printQueue(q);
    return 0;
}
