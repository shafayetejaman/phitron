#include <iostream>
#include <string>
#include <limits.h>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;


            int ev_count = 0, od_count = 0;
            int *arr = new int[n]; // Use dynamic memory allocation
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
                if (arr[i] % 2 == 0)
                {
                    ev_count++;
                }
                else
                {
                    od_count++;
                }
            }
            if (n % 2 == 1)
            {
                cout << -1 << "\n";
            }
            else if (od_count != ev_count)
            {
                const int mid = n / 2;
                cout << min(std::abs(mid - od_count), std::abs(mid - ev_count)) << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
            delete[] arr; // Deallocate the dynamically allocated array

    }

    return 0;
}
