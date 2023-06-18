#include "my_hederfile.h"

using namespace std;

int main()
{
    string s = "my name is cat islam , cat goes to cat";
    string x = "cat";

    int index = s.find(x, 0);
    s.replace(index, x.size(), "$");

    print(s);

    return 0;
}