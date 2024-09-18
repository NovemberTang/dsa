#include <stdio.h>  //for printf()
#include <stdlib.h> //for malloc() and NULL
#include "insertAndDelete.h"
#include "arrayUtils.h"
#include "mergeAndSort.h"
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

void insertIntoPositionInLinkedList(struct node *first, int value, int pos)
{
    struct node *current = first;
    int i = 0;
    while (current->next != NULL && i < pos - 1)
    {
        current = current->next;
        i++;
    }
    printf("Arrived at position %d, value %d\n", i, current->value);

    struct node *newNode = malloc(sizeof(struct node));
    *newNode = (struct node){value, current->next};
    current->next = newNode;

    traverse(*first);
}

struct node *deleteHeadOfLinkedList(struct node *first)
{

    if (first == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }
    else
    {
        struct node *newFirst = first->next;
        free(first);
        return newFirst;
    }
}

void deleteLastInLinkedList(struct node *first)
{
    struct node *current = first;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    printf("%d\n", current->value);
    free(current->next);
    current->next = NULL;
}

void deleteAfterIndexInLinkedList(struct node *first, int idx)
{
    int current_idx = 0;
    struct node *current = first;
    while (current_idx < idx)
    {
        current = current->next;
        current_idx++;
    }

    struct node *toDelete = current->next;
    current->next = current->next->next;

    free(toDelete);

    traverse(*first);
}

// Concatenation of Two Linked Lists
void concatenate(struct node *list1, struct node *list2)
{
    struct node *current = list1;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = list2;
}

void sortLinkedList(struct node *first)
{
    struct node *current = first;
    while (current->next != NULL)
    {
        struct node *tmp = current->next;
        while (tmp != NULL)
        {
            if (current->value > tmp->value)
            {
                int smaller = tmp->value;
                int bigger = current->value;

                current->value = smaller;
                tmp->value = bigger;
            }
            tmp = tmp->next;
        }
        traverse(*first);
        current = current->next;
    }
}

struct node *reverseLinkedList(struct node *first)
{
    struct node *prev = NULL;
    struct node *current = first;
    struct node *next = current->next;

    while (next != NULL)
    {
        next = current->next; // reassignment of placeholder

        current->next = prev; // moving the pointer

        prev = current; // reassignment of placeholder
        current = next; // reassignment of placeholder

        if (current != NULL)
        {
            printf("%d\n", current->value);
        }
    }
    return prev;
}

void main()
{

    struct node *elem1 = malloc(sizeof(struct node));
    *elem1 = (struct node){100, NULL};

    struct node *prev = elem1;

    // create a linked list
    for (int i = 15; i < 32; i++)
    {
        struct node *this = malloc(sizeof(struct node));
        this->value = i;
        prev->next = this;

        prev = this;
    }
    printf("hello C!\n");

    traverse(*elem1);

    printf("hello Natasha!\n");

    struct node *newHead = reverseLinkedList(elem1);

    printf("hello Andrew!\n");

    traverse(*newHead);
}
