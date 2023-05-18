#include <stdio.h>


int main()
{
    int n , tiger=0, pahatan = 0;
    int row = 2;
    scanf("%d", &n);

    int col = n;
    int arr[row][col];

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[0][i], &arr[1][i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[0][i] > arr[1][i])
        {
            tiger++;
        }
        else if (arr[0][i] < arr[1][i])
        {
            pahatan++;
        }
        else
        {
            tiger++;
            pahatan++;
        }
    }

    if (pahatan < tiger)
    {
        printf("Tiger");
    }
    else if (pahatan > tiger)
    {
        printf("Pathan");
    }
    else
    {
        printf("Draw");
    }

    return 0;
}