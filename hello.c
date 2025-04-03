#include <stdio.h>  //for printf()
#include <stdlib.h> //for malloc() and NULL
#include "arrayUtils.h"
#include "stack.h"
#include "binarySearchTree.h"

int calculate_height(struct tree_node* root){
    if(root == NULL){
        return 0;
    }
    else{
        printf("current node = %d\n", root->value);
        int l_height = calculate_height(root->leftchild);
        int r_height = calculate_height(root->rightchild);
        if(r_height > l_height){
            return r_height + 1;
        }
        else{
            return l_height+1;
        }
    }
}

void in_order_traversal(struct tree_node* root){
    if(root!=NULL){
        in_order_traversal(root->leftchild);
        printf("value: %d\n", root->value);
        in_order_traversal(root->rightchild);
    }
}

typedef struct tree_node_avl{
    int value;
    struct tree_node_avl *leftchild;
    struct tree_node_avl *rightchild;
    struct tree_node_avl *parent;
    int height;
}tree_node_avl;

struct tree_node_avl *tree_insert_avl(struct tree_node_avl* root, int value){
    printf("current node = %d\n", root->value);
    if(root == NULL){
        struct tree_node_avl* new_root = malloc(sizeof(struct tree_node_avl ));
        *new_root = (struct tree_node_avl){value, NULL, NULL, NULL, 0};
        printf("-------\n");
        return new_root;
    }
    else if(root->value==value){
        printf("%d already exists. exiting! \n", root->value);
        printf("-------\n");
        return root;
    }
    else if(value < root->value && root->leftchild != NULL){
        printf("new node %d < %d. moving to right child.\n\n", value, root->value);
        return tree_insert_avl(root->leftchild, value);
    }
    else if(value < root->value){
        struct tree_node_avl* new_node = malloc(sizeof(struct tree_node_avl));
        *new_node = (struct tree_node_avl){value, NULL, NULL, root, 0};
        root->leftchild = new_node;
        printf("attached value %d as a left child of %d\n\n", value, root->value);
        printf("-------\n");
        return root;
    }
    else if(value > root->value && root->rightchild != NULL){
        printf("new node %d > %d. moving to right child\n\n", value, root->value);
        return tree_insert_avl(root->rightchild, value);
    }
    else if(value > root->value){
        struct tree_node_avl* new_node = malloc(sizeof(struct tree_node_avl));
        *new_node = (struct tree_node_avl){value, NULL, NULL, root, 0};
        root->rightchild = new_node;
        printf("attached value %d as a right child of %d\n\n", value, root->value);
        printf("-------\n");
        return root;
    }
    else{
        printf("something weird is going on!");
        printf("-------\n");
        return root; //No valid children left
    }
}

int main()
{

    struct tree_node_avl *root = malloc(sizeof(struct tree_node_avl));
    *root = (struct tree_node_avl){60, NULL, NULL, NULL, 0};


    tree_insert_avl(root, 10);
    tree_insert_avl(root, 20);
    // tree_insert(root, 30);
    // tree_insert(root, 19);
    // tree_insert(root, 120);
    // tree_insert(root, 100);
    // tree_insert(root, 80);
    // tree_insert(root, 19);

    return 0;

}
