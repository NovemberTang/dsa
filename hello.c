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

void insertAtBeginning(int *arr, int size, int elem, int *elemCount)
{
    printf("Inserting %d at the beginning of the array\n", elem);
    int i;
    arrayIsFullBro(*elemCount, size);

    for (i = (*elemCount) - 1; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = elem;

    (*elemCount)++;

    printArray(arr, *elemCount);
}

void insertIntoPosition(int *arr, int ins_idx, int mem_size, int *arr_size, int value)
{
    printf("Inserting %d at into index %d of the array\n", value, ins_idx);
    arrayIsFullBro(*arr_size, mem_size);

    int i;

    for (i = *arr_size - 1; i >= ins_idx; i--)
    {
        printf("%d\n", arr[i]);
        arr[i + 1] = arr[i];
    }
    arr[ins_idx] = value;

    printArray(arr, *arr_size);

    (*arr_size)++;
}

void insertAtEnd(int *arr, int mem_size, int *arr_size, int value)
{
    arrayIsFullBro(*arr_size, mem_size);

    printf("Inserting %d to the end of the array.\n", value);

    arr[*arr_size] = value;

    printArray(arr, *arr_size + 1);

    (*arr_size)++;
}

void deleteFromBeginning(int *arr, int *arr_size)
{
    printf("Deleting first element of array\n");
    int i;
    printArray(arr, *arr_size);
    for (i = 0; i < *arr_size; i++)
    {
        printf("Old value %d, ", arr[i]);
        arr[i] = arr[i + 1];
        printf("New value %d\n", arr[i]);
    }
    printArray(arr, *arr_size);
    printf("\n");
    (*arr_size)--;
}

void deleteFromEnd(int *arr, int *arr_size)
{
    printf("Deleting last element of array\n");
    printArray(arr, *arr_size);
    arr[*arr_size - 1] = 0;
    printArray(arr, *arr_size);
    printf("\n");

    (*arr_size)--;
}

void deleteFromPosition(int *arr, int *arr_size, int idx_to_delete)
{
    int i;
    printf("Deleting element %d from array\n", idx_to_delete);
    printf("Before: ");
    printArray(arr, *arr_size);
    for (i = idx_to_delete; i < *arr_size; i++)
    {
        arr[i] = arr[i + 1];
    }
    printf("After:  ");
    printArray(arr, *arr_size);

    (*arr_size)--;
}

int main()
{

    int myLongArray[10] = {2,
                           4,
                           8,
                           10};

    int arr_size = 4;

    insertAtBeginning(myLongArray, 10, 6, &arr_size);
    // insertAtBeginning mutated myLongArray, its length is now 5,
    // which is reflected in insertAtEnd

    insertAtEnd(myLongArray, 10, &arr_size, 12);

    deleteFromBeginning(myLongArray, &arr_size);

    deleteFromEnd(myLongArray, &arr_size);

    deleteFromPosition(myLongArray, &arr_size, 1);
}
