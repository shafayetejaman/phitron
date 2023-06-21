#include "my_hederfile.h"
#include <windows.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int time = std::time(nullptr);

    for (auto i = 3; i <= n; i += 2)
    {
        cout << "the loop is running" << endl;
        Sleep(1);
        for (auto i = 1; i <= n; i++)
        {
            cout << "the loop is running" << endl;
            Sleep(1);
        }
    }

    time = std::time(nullptr) - time;
    cout << "Time : " << time << endl;

    return 0;
}