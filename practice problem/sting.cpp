#include "my_hederfile.h"

using namespace std;

int main()
{
    string s = "my name is cat islam , cat goes to cat";
    string x = "cat";

    int index = s.find(x, 0);
    s.replace(index, x.size(), "$");

    while (index != -1)
    {
        index = s.find(x, 0);
        s.replace(index, x.size(), "$");
    }
    cout << s << endl;


    return 0;
}