#include "my_hederfile.h"

using namespace std;

int main()
{
    char str1[] = "abs";
    char *str2 = "abs";
    *(str2+2) = 'a';
    print(str2);

    return 0;
}