#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i]==0)
        {
            reverse(arr.begin(), arr.begin() + i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<< " ";

    }



    return 0;
}
