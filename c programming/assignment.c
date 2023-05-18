#include <stdio.h>

int main(void)
{
    int n;
    printf("number : ");
    scanf("%d", &n);
    printf("\n");

    int line = 1;
    int space = n - 1;
    int num = 1;

    while (line <= n * 2)
    {
        for (int i = 1; i <= space; i++)
        {
            printf(" ");
        }
        for (int i = 1; i <= num; i++)
        {
            printf("%d", i);
        }

        if (line < n)
        {
            space--;
            num += 2;
        }
        else
        {
            space++;
            num -= 2;
        }

        printf("*\n");
        line++;
    }
    return 0;
}
