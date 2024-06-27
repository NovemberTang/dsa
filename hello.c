#include <stdio.h> //for printf()
#include "insertAndDelete.h"

int findIndex(int *arr, int value, int arr_len)
{
    int i;
    for (i = 0; i < arr_len; i++)
    {
        if (arr[i] == value)
        {
            printf("Found value %d at position %d\n", value, i);
            return i;
        }
    }
    printf("Couldn't find value %d in array\n", value);
}

int main()
{

    int myLongArray[10] = {2,
                           4,
                           8,
                           10};

    int arr_size = 4;

    findIndex(myLongArray, 8, arr_size);
}
