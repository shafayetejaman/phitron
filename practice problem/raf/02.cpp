// #include <iostream>
// #include <cmath>

// int main()
// {
//     double x = 12;
//     double base = 4;
//     double result = log(x) / log(base);
//     std::cout << result << std::endl;
//     return 0;
// }
#include "my_hederfile.h"

using namespace std;

int strlen(char s[])
{
    static int i = 0;
    if (s[i] == '\0')
    {
        return 0;
    }
    else
    {
        i++;
        return 1 + strlen(s);
    }
}

int main()
{
    char s[10] = "Hello";
    // print(strlen(s));
   
    return 0;
}
