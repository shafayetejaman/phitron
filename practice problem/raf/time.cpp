#include "my_hederfile.h"

using namespace std;

int main()
{
    int time = std::time(nullptr);


    int n = 10;
    
    for (auto i = 0; i < n; i++)
    {
        cout << "the loop is running" << endl;
    }

    time = std::time(nullptr) - time;
    print(time);

    return 0;
}