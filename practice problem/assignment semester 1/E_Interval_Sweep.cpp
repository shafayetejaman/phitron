#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    if (a == 0 || b == 0)
    {
        cout << "YES" << endl;
    }
    else if ((a + b) % 2 == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
