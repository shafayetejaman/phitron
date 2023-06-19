#include "my_hederfile.h"

using namespace std;

int main()
{
    list<int> l;

    l.push_back(6);
    l.push_front(9);
    l.push_back(2);

    // cout << *next(l.begin(), 0) << endl;
    for (const auto &i : l)
    {
        cout << i << " ";
    }
    cout << endl;
    // l.erase(next(l.begin(), 0));
    l.sort(greater<int>());

    for (const auto &i : l)
    {
        cout << i << " ";
    }

    return 0;
}