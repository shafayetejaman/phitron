#include <bits/stdc++.h>
using namespace std;

void push(vector<int> &arr, int val)
{
    arr.push_back(val);
    int currIdx = arr.size() - 1;

    while (currIdx > 0)
    {
        int parentIdx = (currIdx - 1) / 2;
        if (arr[currIdx] < arr[parentIdx])
        {
            swap(arr[currIdx], arr[parentIdx]);
            currIdx = parentIdx;
        }
        else
        {
            break;
        }
    }
}
void pop(vector<int> &arr) // min heap pop
{
    int curr = 0;
    arr[0] = arr.back();
    arr.pop_back();

    while (true)
    {
        int left = curr * 2 + 1;
        int right = curr * 2 + 2;
        int last = arr.size() - 1;
        if (left <= last && right <= last)
        {
            if (arr[left] > arr[right] && arr[curr] > arr[right])
            {
                swap(arr[curr], arr[right]);
                curr = right;
            }
            else if (arr[left] < arr[right] && arr[curr] > arr[left])
            {
                swap(arr[curr], arr[left]);
                curr = left;
            }
            else
            {
                break;
            }
        }
        else if (left <= last && arr[curr] > arr[left])
        {
            swap(arr[curr], arr[left]);
            curr = left;
        }
        else if (right <= last && arr[curr] > arr[right])
        {
            swap(arr[curr], arr[right]);
            curr = right;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    vector<int> arr = {13, 24, 33, 43, 52, 55};

    push(arr, 1);

    print(arr);
    pop(arr);
    print(arr);
    pop(arr);
    print(arr);

    return 0;
}

