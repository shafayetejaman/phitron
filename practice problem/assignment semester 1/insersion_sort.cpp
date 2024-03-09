#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &arr)
{
    for (auto i = 0; i < arr.size() - 1; i++)
    {
        for (auto j = i + 1; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
            }
            else
            {
                break;
            }
        }
    }
}

int main()
{
    vector<int> arr = {5, 13, 45, 5, 2, 5, 5};
    print(arr);
    insertion_sort(arr);
    print(arr);

    return 0;
}