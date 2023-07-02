#include <bits/stdc++.h>
#include <time.h>
#include <limits.h>
#include <windows.h>

using namespace std;

int main()
{
    int n = 1000;

    int time = std::time(nullptr);

    for (auto i = 1; i <= n; i++)
    {
        cout << "the loop is running" << endl;
    }

    time = std::time(nullptr) - time;
    cout << "Time : " << time << endl;

    return 0;
}