#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int main()
{
    int n;
    cin >> n;
    map<char, int> m;

    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        m[c]++;
    }

    for (auto i : m)
    {
        while (i.second > 0)
        {
            cout << i.first;
            i.second--;
        }
    }



    return 0;
}
