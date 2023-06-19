#include "my_hederfile.h"

using namespace std;

int main()
{
    list<int> l;

    l.push_back(1);
    l.push_front(0);
    l.push_back(2);

    cout << distance(l.begin(), next(l.begin(), 0)) << endl;

    return 0;
}