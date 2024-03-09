#include <iostream>

using namespace std;

int main()
{
    double dis, pri;
    scanf("%lf %lf", &dis, &pri);
    printf("%.2lf", (pri * 100) / (100 - dis));

    return 0;
}