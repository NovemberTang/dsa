#include <stdio.h>  //for printf()
#include <stdlib.h> //for malloc() and NULL
#include "insertAndDelete.h"
#include "arrayUtils.h"
#include "mergeAndSort.h"
#include "doublyLinkedList.h"
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

struct header
{
    int length;
    struct node *next;
};

void appendToHeaderLinkedList(struct header *header, int value)
{
    struct node *lastNode = malloc(sizeof(struct node));
    *lastNode = (struct node){value, NULL};
    if (header->next == NULL)
    {
        header->next = lastNode;
        header->length = 1;
    }
    else
    {
        struct node *current = header->next;
        appendToLinkedList(current, value);
        header->length++;
    }
}

void traverseHeaderLinkedList(struct header *header)
{
    if (header->next == NULL)
    {
        printf("No elements in list\n");
    }
    else
    {
        traverse(*header->next);
    }
}
int main()
{
    struct header *header = malloc(sizeof(struct header));
    *header = (struct header){0, NULL};

    appendToHeaderLinkedList(header, 2);
    appendToHeaderLinkedList(header, 3);
    traverseHeaderLinkedList(header);
    printf("%d\n", header->length);

    return 0;
}
