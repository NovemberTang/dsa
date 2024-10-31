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

void deleteFirstNodeHeaderLinkedList(struct header *header)
{
    if (header->next == NULL)
    {
        printf("No elements in list\n");
    }
    else
    {
        struct node *firstNode = deleteHeadOfLinkedList(header->next);
        header->next = firstNode;
        header->length--;
    }
}

struct queueHeader
{
    struct node *firstNode;
    struct node *lastNode;
};

void pushQueue(struct queueHeader *header, int value)
{
    struct node *newNode = malloc(sizeof(struct node));
    *newNode = (struct node){value, NULL};
    if (header->firstNode == NULL)
    {
        header->firstNode = newNode;
    }
    else
    {
        header->lastNode->next = newNode;
    }
    header->lastNode = newNode;
}

void traverseQueue(struct queueHeader *header)
{
    if (header->firstNode == NULL)
    {
        printf("No elements in queue\n");
    }
    else
    {
        traverse(*header->firstNode);
    }
}

int popQueue(struct queueHeader *header)
{
    if (header->firstNode == NULL)
    {
        printf("No elements in queue\n");
        return -1;
    }
    else
    {
        struct node *firstNode = header->firstNode;
        int returnValue = firstNode->value;
        struct node *secondNode = firstNode->next;
        header->firstNode = secondNode;
        free(firstNode);

        if (header->firstNode == NULL)
        {
            header->lastNode = NULL;
        }

        return returnValue;
    }
}

int main()
{
    struct queueHeader *header = malloc(sizeof(struct queueHeader));
    *header = (struct queueHeader){NULL, NULL};

    pushQueue(header, 2);
    // pushQueue(header, 3);
    int x = popQueue(header);
    printf("Popped %d\n", x);
    traverseQueue(header);
    printf("%d\n", header->lastNode);

    return 0;
}
