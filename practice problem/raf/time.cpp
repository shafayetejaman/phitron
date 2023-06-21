#include "my_hederfile.h"

using namespace std;

int main()
{
    int time = std::time(nullptr);


    int n;
    cin >> n;

    for (auto i = 0; i < n; i++)
    {
        cout << "the loop is running" << endl;
    }

    time = std::time(nullptr) - time;
    cout << "Time : " << time << endl;

    return 0;
}