#include <stdio.h>  //for printf()
#include <stdlib.h> //for malloc() and NULL
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

struct doubleNode
{
    int value;
    struct doubleNode *next;
    struct doubleNode *prev;
};

void traverseDouble(struct doubleNode first)
{
    struct doubleNode current = first;
    printf("%d ", current.value);
    while (current.next != NULL)
    {
        current = *current.next;
        printf("%d ", current.value);
    };
    printf("\n");
}

void reverseTraverseDouble(struct doubleNode last)
{
    struct doubleNode current = last;
    printf("%d ", current.value);
    while (current.prev != NULL)
    {
        current = *current.prev;
        printf("%d ", current.value);
    };
    printf("\n");
}

struct doubleNode *insertIntoPositionDouble(struct doubleNode *first, int value, int pos)
{
    if (pos == 0)
    {
        struct doubleNode *newNode = malloc(sizeof(struct doubleNode));
        *newNode = (struct doubleNode){value, first, NULL};
        first->prev = newNode;
        return newNode;
    }
    else
    {
        struct doubleNode *current = first;
        int i = 0;
        while (current->next != NULL && i < pos - 1)
        {
            current = current->next;
            i++;
        }
        printf("Arrived at position %d, value %d\n", i, current->value);

        struct doubleNode *newNode = malloc(sizeof(struct doubleNode));
        *newNode = (struct doubleNode){value, current->next, current};
        if (current->next != NULL)
        {
            struct doubleNode *next = current->next;
            next->prev = newNode;
        }
        current->next = newNode;
        return first;
    }
}

void main()
{

    struct doubleNode *elem1 = malloc(sizeof(struct doubleNode));
    *elem1 = (struct doubleNode){100, NULL, NULL};

    struct doubleNode *elem2 = malloc(sizeof(struct doubleNode));
    *elem2 = (struct doubleNode){101, NULL, elem1};

    elem1->next = elem2;

    struct doubleNode *newList = insertIntoPositionDouble(elem1, 102, 2);

    traverseDouble(*newList);
}
