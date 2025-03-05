#include <stdio.h>  //for printf()
#include <stdlib.h> //for malloc() and NULL
#include "arrayUtils.h"
#include "stack.h"

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

//So we don't need to remember to decrement the array size to get the last element
int interpolation_search(int value, int* arr, int arr_size){
    return interpolation_search_imp(value, arr, 0, arr_size-1);
}

struct tree_node{
    int value;
    struct tree_node *leftchild;
    struct tree_node *rightchild;

};


struct tree_node *find_node(struct tree_node *root, int value){

    //takes the root node of a binary search tree.
    if(root == NULL){
        //tree is empty
        printf("value not found. Tree is empty.\n");
        return NULL;
    }
    else if(root->value==value){
        printf("Found %d! \n", root->value);
        return root;
    }
    else if(value < root->value && root->leftchild != NULL){
        printf("search value %d is less than root value %d\n", value, root->value);
        return find_node(root->leftchild, value);
    }
    else if(root->value < value && root->rightchild != NULL){
        printf("search value %d is greater than root value %d\n", value, root->value);
        return find_node(root->rightchild, value);
    }
    else{
        printf("value not found. Ran out of children.\n");
        return NULL; //No valid children left
    }
}

struct tree_header
{
    struct tree_node *root;
};

struct tree_node* delete_leaf_imp(struct tree_node* current_node, int value){
    if(current_node == NULL){
        //tree is empty
        printf("Value not found. Tree is empty.\n");
        return current_node;
    }
    else if(value > current_node->value){
        printf("Value not found. Turning right.\n");
        current_node->rightchild =  delete_leaf_imp(current_node->rightchild, value);
        return current_node;
    }
    else if(value < current_node->value){
        printf("Value not found. Turning left.\n");
        current_node->leftchild = delete_leaf_imp(current_node->leftchild, value);
        return current_node;
    }
    else if(current_node->value == value){
        printf("Value found. Deleting it.\n");
        return NULL;
    }
}

 void delete_leaf(struct tree_header* header, int value){
    header->root = delete_leaf_imp(header->root, value);
}

//handle an illegal insertion
struct tree_node *tree_insert(struct tree_node* root, int value){
    printf("current node = %d\n", root->value);
    if(root == NULL){
        struct tree_node* new_root = malloc(sizeof(struct tree_node ));
        new_root->value = value;
        return new_root;
    }
    else if(root->value==value){
        printf("%d already exists. exiting! \n", root->value);
        return root;
    }
    else if(value < root->value && root->leftchild != NULL){
        printf("new node %d < %d. moving to right child.\n\n", value, root->value);
        return tree_insert(root->leftchild, value);
    }
    else if(value < root->value){
        struct tree_node* new_node = malloc(sizeof(struct tree_node));
        new_node->value = value;
        root->leftchild = new_node;
        printf("attached value %d as a left child of %d\n\n", value, root->value);
    }
    else if(value > root->value && root->rightchild != NULL){
        printf("new node %d > %d. moving to right child\n\n", value, root->value);
        return tree_insert(root->rightchild, value);
    }
    else if(value > root->value){
        struct tree_node* new_node = malloc(sizeof(struct tree_node));
        new_node->value = value;
        root->rightchild = new_node;
        printf("attached value %d as a right child of %d\n\n", value, root->value);
    }
    else{
        printf("something weird is going on!");
        return root; //No valid children left
    }
}

int main()
{

    //      3
    //   1     5
    // 0         8


    struct tree_node *leftLeaf = malloc(sizeof(struct tree_node));
    *leftLeaf = (struct tree_node){0, NULL, NULL};


    struct tree_node *left = malloc(sizeof(struct tree_node));
    *left = (struct tree_node){1, leftLeaf, NULL};

    struct tree_node *rightLeaf = malloc(sizeof(struct tree_node));
    *rightLeaf = (struct tree_node){8, NULL, NULL};

    struct tree_node *right = malloc(sizeof(struct tree_node));
    *right = (struct tree_node){ 5, NULL, rightLeaf};

    struct tree_node *root = malloc(sizeof(struct tree_node));
    *root = (struct tree_node){3, left, right};

    struct tree_header *header = malloc(sizeof(struct tree_header));
    *header = (struct tree_header){root};

    delete_leaf(header, 0);

}
