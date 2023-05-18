#include <stdio.h>


int main(void)
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min= j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    int mid = n / 2;

    if (n % 2 == 0)
    {
        printf("%d %d\n", arr[mid - 1], arr[mid]);
    }
    else
    {
        printf("%d\n", arr[mid]);
    }


    return 0;
}