#include <stdio.h>  //for printf()
#include <stdlib.h> //for malloc() and NULL
#include "doublyLinkedList.h"

struct doubleNode;

void traverseDouble(struct doubleNode *first)
{
    if(first == NULL){
        printf("List is empty\n");
    }
    struct doubleNode *current = first;
    printf("%d ", current->value);
    while (current->next != NULL)
    {
        current = current->next;
        printf("%d ", current->value);
    }
    printf("\n");
}

void reverseTraverseDouble(struct doubleNode last) //TODO use pointer
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

struct doubleNode *deleteFromStartDouble(struct doubleNode *first)
{
    if (first == NULL) // no elements
    {
        return NULL;
    }
    else if (first->next == NULL) // one element
    {
        free(first);
        return NULL;
    }
    else
    {
        printf("multiple elements\n");
        struct doubleNode *newFirst = first->next;
        newFirst->prev = NULL;
        free(first);
        return newFirst;
    }
}

struct doubleNode *deleteFromEndDouble(struct doubleNode *first)
{
    if (first == NULL) // no elements
    {
        return NULL;
    }
    else if (first->next == NULL) // one element
    {
        free(first);
        return NULL;
    }
    else
    {
        struct doubleNode *current = first;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->prev->next = NULL;
        free(current);
        return first;
    }
}

struct doubleNode *deleteAfterIndexDouble(struct doubleNode *first, int pos)
{
    if (first == NULL) // no elements
    {
        return NULL;
    }
    else
    {
        struct doubleNode *current = first;
        for (int i = 0; i < pos; i++)
        {
            current = current->next;
            if (current->next == NULL)
            {
                printf("No next element\n");
                return first;
            }
        }

        printf("Arrived at position %d, value %d\n", pos, current->value);
        struct doubleNode *newNextNode = current->next->next; // do null check

        free(current->next); // TODO make sure this isn't null
        current->next = newNextNode;
        printf("%d\n", newNextNode);
        if (newNextNode != NULL)
        {
            newNextNode->prev = current;
        }
        return first;
    }
}
