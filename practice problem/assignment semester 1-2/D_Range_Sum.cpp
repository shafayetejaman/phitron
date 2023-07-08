#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long l, r;
        cin >> l >> r;
        if (l>r)
        {

            long long sum = ((l * (l + 1)) / 2) - ((r * (r - 1)) / 2);
            cout << sum << endl;
        }
        else
        {

            long long sum = ((r * (r + 1)) / 2) - ((l * (l - 1)) / 2);
            cout << sum << endl;
        }

    }

    return 0;
}
