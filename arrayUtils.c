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


void twoDimArraySum(int arr1[3][3], int arr2[3][3])
{
    int resultArray[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            resultArray[i][j] = arr1[i][j] + arr2[i][j];
        }
        printArray(resultArray[i], 3);
    }
}

void transpose(int arr[3][3])
{
    int resultArray[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            resultArray[i][j] = arr[j][i];
        }
        printArray(resultArray[i], 3);
    }
}

void print3dArray(int arr[2][2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printArray(arr[i][j], 2);
        }
    }
}