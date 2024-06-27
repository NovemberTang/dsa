#include <stdio.h>  //for printf()
#include <stdlib.h> //for exit()

void arrayIsFullBro(int arr_size, int mem_size)
{
    if (arr_size >= mem_size)
    {
        printf("Array is full bro\n");
        exit(1);
    }
}

void printArray(int *arr, int arraySize)
{
    int i;
    for (i = 0; i < arraySize; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertAtBeginning(int *arr, int size, int elem, int elemCount)
{
    printf("Inserting %d at the beginning of the array\n", elem);
    int i;
    arrayIsFullBro(elemCount, size);

    for (i = elemCount - 1; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = elem;
    printArray(arr, elemCount + 1);
}

void insertIntoPosition(int *arr, int ins_idx, int mem_size, int arr_size, int value)
{
    printf("Inserting %d at into index %d of the array\n", value, ins_idx);
    arrayIsFullBro(arr_size, mem_size);

    int i;

    for (i = arr_size - 1; i >= ins_idx; i--)
    {
        printf("%d\n", arr[i]);
        arr[i + 1] = arr[i];
    }
    arr[ins_idx] = value;

    printArray(arr, arr_size);
}

void insertAtEnd(int *arr, int mem_size, int arr_size, int value)
{
    arrayIsFullBro(arr_size, mem_size);

    arr[arr_size] = value;

    printArray(arr, arr_size + 1);
}

void deleteFromBeginning(int *arr, int arr_size)
{
    printf("Deleting from beginning of array\n");
    int i;
    printArray(arr, arr_size);
    for (i = 0; i < arr_size; i++)
    {
        printf("Old value %d, ", arr[i]);
        arr[i] = arr[i + 1];
        printf("New value %d\n", arr[i]);
    }
    printArray(arr, arr_size);
    printf("\n");
}

void deleteFromEnd(int *arr, int arr_size)
{
    printf("Deleting from end of array\n");
    printArray(arr, arr_size);
    arr[arr_size - 1] = 0;
    printArray(arr, arr_size);
    printf("\n");
}

void deleteFromPosition(int *arr, int arr_size, int idx_to_delete)
{
    int i;
    printf("Deleting element %d from array\n", idx_to_delete);
    printf("Before: ");
    printArray(arr, arr_size);
    for (i = idx_to_delete; i < arr_size; i++)
    {
        arr[i] = arr[i + 1];
    }
    printf("After:  ");
    printArray(arr, arr_size);
}

int main()
{

    int myLongArray[10] = {2,
                           4,
                           8,
                           10};

    insertAtBeginning(myLongArray, 10, 6, 4);
    // insertAtBeginning mutated myLongArray, its length is now 5,
    // which is reflected in insertAtEnd

    insertAtEnd(myLongArray, 10, 5, 12);

    deleteFromBeginning(myLongArray, 6);

    deleteFromEnd(myLongArray, 5);

    deleteFromPosition(myLongArray, 4, 1);
}
