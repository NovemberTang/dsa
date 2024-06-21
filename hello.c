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
}
