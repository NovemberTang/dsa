#include <stdio.h>  //for printf()
#include <stdlib.h> //for malloc() and NULL
#include "arrayUtils.h"
#include "queue.h"
#include "linkedList.h"

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

struct ringBuffer
{
    int lastReadAddress;
    int nextWriteAddress;
    int *array;
    int arrayLength;
};

int readRingBuffer(struct ringBuffer *r)
{
    int nextAddress = (r->lastReadAddress + 1) % r->arrayLength;
    printf("Reading value from position %d\n", nextAddress);
    int valueToRead = r->array[nextAddress];
    r->lastReadAddress = nextAddress;
    return valueToRead;
}

void writeRingBuffer(struct ringBuffer *r, int value)
{
    printf("Writing value %d to position %d\n", value, r->nextWriteAddress);
    r->array[r->nextWriteAddress] = value;
    r->nextWriteAddress = (r->nextWriteAddress + 1) % r->arrayLength;
}

int main()
{
    struct queueHeader *header = malloc(sizeof(struct queueHeader));
    *header = (struct queueHeader){NULL, NULL};

    int arr[5] = {10,
                  20,
                  30,
                  40,
                  50};

    struct ringBuffer *myBuffer = malloc(sizeof(struct ringBuffer));
    *myBuffer = (struct ringBuffer){
        -1, 0, arr, 5};

    writeRingBuffer(myBuffer, 1);
    writeRingBuffer(myBuffer, 1);
    writeRingBuffer(myBuffer, 1);
    writeRingBuffer(myBuffer, 1);
    writeRingBuffer(myBuffer, 2);
    writeRingBuffer(myBuffer, 2);

    printf("%d\n", readRingBuffer(myBuffer));
    printf("%d\n", readRingBuffer(myBuffer));
    printf("%d\n", readRingBuffer(myBuffer));

    return 0;
}
