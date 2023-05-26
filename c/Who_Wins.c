#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, tiger = 0, pathan = 0;
    scanf("%d", &n);
    while (n>0)
    {
        int temp1, temp2;
        scanf("%d %d", &temp1, &temp2);
        if (temp1 > temp2)
        {
            tiger ++;
        }
        else if (temp2 > temp1)
        {
            pathan ++;
        }
        n--;
    }

    if (tiger > pathan)
    {
        printf("Tiger\n");
    }
    else if (pathan > tiger)
    {
        printf("Pathan\n");
    }
    else
    {
        printf("Draw\n");
    }

    return 0;
}
