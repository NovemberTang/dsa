#include <stdio.h>  //for printf()
#include <stdlib.h> //for malloc()
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
};

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

struct node
{
    int value;
    struct node *next;
};

void traverse(struct node first)
{
    struct node current = first;
    printf("%d ", current.value);
    while (current.next != NULL)
    {
        current = *current.next;
        printf("%d ", current.value);
    };
};

int *search(struct node first, int value)
{
    struct node *current = &first;
    while (current->next != NULL && current->value != value)
    {
        current = current->next;
    }
    if (current->next == NULL)
    {
        printf("\nNo more elements in list\n");
        return NULL;
    }
    else if (current->value == value)
    {
        printf("\nFound value %d!!\n", current->value);
        return &current->value;
    }
}

struct node *prependToLinkedList(struct node *list, int value)
{
    struct node *firstElem = malloc(sizeof(struct node));
    *firstElem = (struct node){value, list};
    return firstElem;
}

void main()
{

    struct node elem1 = {3, NULL};

    struct node *prev = &elem1;

    // create a linked list
    for (int i = 15; i < 32; i++)
    {
        struct node *this = malloc(sizeof(struct node));
        this->value = i;
        prev->next = this;

        prev = this;
    }

    struct node *myNewList = prependToLinkedList(&elem1, 6);
    traverse(*myNewList);
}
