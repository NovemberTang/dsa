#include <stdio.h>  //for printf()
#include <stdlib.h> //for malloc() and NULL
#include "linkedList.h"

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

//evaluate reverse polish notation

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
    return stack->value;
}
