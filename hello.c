#include <stdio.h>  //for printf()
#include <stdlib.h> //for malloc() and NULL
#include "arrayUtils.h"
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

int interpolation_search_imp(int value, int* arr, int low_pos, int high_pos){

 int low = arr[low_pos];
 int high = arr[high_pos];
 int mid = low_pos + ((high_pos-low_pos) * (value-low)) / (high-low);

 if(arr[mid]==value)
 {
    printf("%d: %d\n", mid, arr[mid]);
    return arr[mid];
 }
 else if(value < arr[mid]){
    return interpolation_search_imp(value, arr, low_pos, mid-1);
 }
 else { // if(value > arr[mid]){
    return interpolation_search_imp(value, arr,mid+1, high_pos);
 };

}

//SO we don't need to remember to decrement the array size to get the last element
int interpolation_search(int value, int* arr, int arr_size){
    return interpolation_search_imp(value, arr, 0, arr_size-1);
}

//stacks

struct node *push_stack(struct node *stack, int value)
{
    printf("pushing %d to stack\n", value);
    return prependToLinkedList(stack, value);
}

struct node *pop_stack(struct node *stack)
{
    return deleteHeadOfLinkedList(stack);
}

int peek_stack(struct node *stack)
{
    if(stack == NULL){
        printf("Stack is empty, babe!\n");
        return -1;
    } else {
        return stack->value;
    }
}

int rpn_evaluate(char * arr, int len){

    struct node *stack = NULL;

    for(int i = 0; i<len; i++){
        if(arr[i]=='+' || arr[i]=='-' || arr[i]=='/' || arr[i]=='*'){
            int a = peek_stack(stack);
            stack = pop_stack(stack);

            int b = peek_stack(stack);
            stack = pop_stack(stack);

            if(arr[i] == '+'){
                printf("popping and adding %d and %d\n", a, b);
                stack = push_stack(stack, b+a);
            }
            else if(arr[i] == '*'){
                printf("popping and multiplying %d and %d\n", a, b);
                stack = push_stack(stack, b*a);
            }
            else if(arr[i] == '-'){
                printf("popping and subtracting %d and %d\n", a, b);
                stack = push_stack(stack, b-a);
            }
            else if(arr[i] == '/'){
                printf("popping and dividing %d and %d\n", a, b);
                stack = push_stack(stack, b/a);
            }
        }
        else{
        stack = push_stack(stack, arr[i]-'0');}
    };
    printf("final stack\n");
    traverse(*stack);
    return 1;
}


int main()
{
    char rpn_string[] = "35+72-*";
    rpn_evaluate(&rpn_string[0], 7);

}
