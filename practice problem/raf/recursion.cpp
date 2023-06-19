#include <iostream>
#include <vector>

using namespace std;

void print(const int &a)
{
    cout << a << " ";
}

void pd(vector<int> &arr, int n, int i)
{
    if (i < 0) // changed from -2 to -1
        return;
    if (i == arr.size())
    {
        pd(arr, arr[arr.size() - 1], i - 1);
        return;
    }
    if (n == 0)
    {
        cout << endl;
        pd(arr, arr[i], i - 1);
        return;
    }
    print(n % 10);
    pd(arr, n / 10, i);
}

int main()
{
    vector<int> arr = {12, 432, 45, 5};
    pd(arr, 0, arr.size());

    return 0;
}
