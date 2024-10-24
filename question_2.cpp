#include <iostream>
#include <vector>
#include <stack>
using namespace std;


void printNextGreaterElement(const vector<int>& arr)
{
    int n = arr.size();
    stack<int> s;
    vector<int> nge(n, -1);


    for (int i = n - 1; i >= 0; --i)
    {
        while (!s.empty() && s.top() <= arr[i])
        {
            s.pop();
        }

        if (!s.empty())
        {
            nge[i] = s.top();
        }

        s.push(arr[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " -> " << nge[i] << endl;
    }
}

int main()
{
    vector<int> arr = {4, 5, 2, 25};

    cout << "Input Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Next Greater Element (NGE):" << endl;
    printNextGreaterElement(arr);

    return 0;
}
