// #include "my_hederfile.h"

// using namespace std;
#include <stdio.h>

int swaps(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* array(int *arr)
{
    arr[1] = 1;
    return arr;
}


int main()
{
    int arr[2] = {12, 34, 23 ,4};
    int p = array(arr);


    // int a = 10; // a = 20
    // int b = 20; // b = 10

    // swaps(&a, &b);

    // print(a);
    // print(b);




    // char arr1[] = "my name is";
    // char *arr2 = "my name is" ;
    // // print(arr1[3]);
    // arr1[3] = 'm';
    // *(arr2) = 'm';
    // printf("%c\n", arr1[3]);
    // printf("%c", *(arr2+3));



    // const int a = 10;
    // int *ptr = &a;

    // *ptr = 20;
    // printf("%d", a);

    return 0;
}