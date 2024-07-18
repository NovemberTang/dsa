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
