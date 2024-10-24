#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void printFirstNegativeInWindow(const vector<int>& arr, int k)
{
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < arr.size(); ++i)
    {

        if (!dq.empty() && dq.front() == i - k)
        {
            dq.pop_front();
        }

        if (arr[i] < 0)
        {
            dq.push_back(i);
        }


        if (i >= k - 1)
        {
            if (!dq.empty())
            {
                result.push_back(arr[dq.front()]);
            }
            else
            {
                result.push_back(0);
            }
        }
    }

    for (int neg : result)
    {
        cout << neg << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {-8, 2, 3, -6, 10};
    int k = 2;

    cout << "Input Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << "\nFirst Negative Integer for each window of size " << k << ":" << endl;

    printFirstNegativeInWindow(arr, k);

    return 0;
}
