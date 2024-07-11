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

    int myLongArray[10] = {0,
                           4,
                           8,
                           10};

    int myShortArray[3] = {5};

    // mergeSortedArrays(myLongArray, 4, myShortArray, 1);

    int anotherShortArray[4] = {5, 4, 7, 3};
    selectionSort(anotherShortArray, 4);
}
