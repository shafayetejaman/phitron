#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n][n];
    int flag = 0;

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
            if (i == j && arr[i][j] != 1)
            {
                flag = 1;
                break;
            }
            if (i != j && arr[i][j] != 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            break;
        }
    }
    if (flag == 1)
    {
        printf("NO");
    }
    else
    {
        printf("YES");
    }

    return 0;
}
