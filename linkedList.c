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