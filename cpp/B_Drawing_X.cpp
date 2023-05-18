#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n ;
    cin >> n;
    int l = 0, r = n - 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (l==r && l == j)
            {
                cout << "X";
            }
            else if (j == l)
            {
                cout << '\\';
            }
            else if (j == r)
            {
                cout << "/";
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
        r--;
        l++;
    }

        return 0;
}