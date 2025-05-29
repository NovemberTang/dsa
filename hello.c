#include <stdio.h>  //for printf()
#include <stdlib.h> //for malloc() and NULL
#include "arrayUtils.h"
#include "stack.h"
#include "binarySearchTree.h"
#include <math.h>
#include <string.h> //for strcpy
#include "linkedList.h"


void in_order_traversal(struct tree_node* root){
    if(root!=NULL){
        in_order_traversal(root->leftchild);
        printf("value: %d\n", root->value);
        in_order_traversal(root->rightchild);
    }
}

int hash(int x){
    return x % 5;
}

void add_to_hashmap(int x, struct node **arr ){
    int idx = hash(x);
    struct node* node_at_index = arr[idx];

    struct node *newNode = malloc(sizeof(struct node));
    *newNode = (struct node){x, NULL};

    if(node_at_index==NULL){//nothing exists with that hash currently
        node_at_index=newNode;
        printf("put %d in index %d\n", x, idx);
    }else{ //if there is a hash collision
        while(node_at_index->next != NULL){
            node_at_index=node_at_index->next;
        }
        node_at_index->next = newNode;
        printf("put %d in index %d, after %d\n", x, idx, node_at_index->value);
    }
}


int main()
{

    //4,14


    struct node* arr[5];

    for(int i=0;i<5;i++){
        arr[i]=NULL;
    }

    printf("created array.\n");

    add_to_hashmap(4, arr);
    add_to_hashmap(14, arr);

    

    return 0;

}
