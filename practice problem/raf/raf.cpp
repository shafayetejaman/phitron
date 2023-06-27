#include "my_hederfile.h"

using namespace std;

int main()
{
    int n = 10;
        //             9 == 0
    // for (auto i = n-1; i > -1; i--)
    // {
    //     cout << i << " ";
    // }
    print();

    while (--n)
    {
        print(n);
    }

    return 0;
}