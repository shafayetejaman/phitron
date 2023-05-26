#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d", &t);

    while (t > 0)
    {
        unsigned int s, a, b, c;
        scanf("%u %u %u %u", &s, &a, &b, &c);
        printf("%u\n", s - (a + b + c));
        t--;
    }

    return 0;
}
