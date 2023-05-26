#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, p = 1;
    scanf("%d", &n);
    int s = n - 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < s; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < p; j++)
        {
            if (i % 2 == 0)
            {
                printf("^");
            }
            else
            {
                printf("*");
            }
        }
        printf("\n");
        p += 2;
        s--;
    }
    return 0;
}


