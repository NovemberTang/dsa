#include <stdlib.h> //for malloc() and NULL
#include <stdio.h>  //for printf()
#include "linkedList.h"

struct node node;

void traverse(struct node first)
{
    struct node current = first;
    printf("%d ", current.value);
    while (current.next != NULL)
    {
        current = *current.next;
        printf("%d ", current.value);
    };
    printf("\n");
}

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

void appendToLinkedList(struct node *first, int value)
{
    struct node *current = first;
    while (current->next != NULL)
    {
        current = current->next;
    }
    struct node *lastNode = malloc(sizeof(struct node));
    *lastNode = (struct node){value, NULL};
    current->next = lastNode;
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

// Header linked list

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
