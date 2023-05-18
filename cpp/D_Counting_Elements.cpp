#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int main()
{
    int n;
    cin >> n;
    unordered_map<int, int> m;
    int count = 0;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        m[arr[i]]++;
    }
    for (auto i : m)
    {
        if (m.find(i.first+1) != m.end())
        {
            count +=   i.second;
        }
    }
    cout << count;

    return 0;
}
