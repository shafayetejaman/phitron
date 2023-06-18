#include <bits/stdc++.h>

using namespace std;


int main()
{

    int arr_st[4] = {1,2,3,4};

    int *arr_dy = new int[4]{1, 2, 3, 4};

    // making arr_dy larger
    int *temp = new int[5];
    for (auto i = 0; i < 4; i++)
    {
        temp[i] = arr_dy[i];
    }
    // adding the new value
    temp[4] = 5;
    // deleting the old memory
    delete[] arr_dy;

    arr_dy = temp;
    for (auto i = 0; i < 5; i++)
    {
        cout << arr_dy[i]<< ' ';
    }

    delete[] arr_dy;

    return 0;
}