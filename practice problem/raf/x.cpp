#include <bits/stdc++.h>
using namespace std;
//                                   \   /
//                                    \ /
//                                     X
//                                    / \
//                                   /   \                */
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == n / 2 && j == n / 2)
            {
                cout << "X";
            }
            if (j == i)
            {
                if (j == n / 2)
                {
                    continue;
                }
                cout << "\\";
            }

            if (j == n - 1 - i)
            {
                if (j == n / 2)
                {
                    continue;
                }
                cout << "/";
            }
            if (j != i && j != n - i - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}