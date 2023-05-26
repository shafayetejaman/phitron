#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char s[1001];
    int capital = 0;
    int small = 0;
    int space = 0;
    fgets(s,1001,stdin);

    for (int i=0;i<strlen(s);i++)
    {
        if (s[i]>='A' && s[i]<='Z')
        {
            capital++;
        }
        else if (s[i]>='a' && s[i]<='z')
        {
            small++;
        }
        else
        {
            space++;
        }
    }

    printf("Capital - %d\nSmall - %d\nSpaces - %d",capital,small,space);



    return 0;
}
