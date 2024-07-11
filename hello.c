#include <stdio.h> //for printf()
#include "insertAndDelete.h"
#include "arrayUtils.h"
#include "mergeAndSort.h"

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
    return -1; // couldn't find the value.
}

int main()
{
    int twoDimArray[2][2] = {{1, 2}, {3, 4}};

    for (int i = 0; i < 2; i++)
    {
        printArray(twoDimArray[i], 2);
    }
}
