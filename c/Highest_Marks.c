#include <stdio.h>


int main(void)
{
    int n;
    scanf("%d", &n);
    int arr[n];
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", max-arr[i]);

    }




    return 0;
}