#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int front = 0, end = n - 1;
    while (front <= end)
    {
        cout << arr[front++] << " ";
        if (front <= end)
        {
            cout << arr[end--] << " ";
        }
    }

    return 0;
}
