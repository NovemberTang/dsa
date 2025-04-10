#include <stdio.h>  //for printf()
#include <stdlib.h> //for malloc() and NULL
#include "arrayUtils.h"
#include "stack.h"
#include "binarySearchTree.h"
#include <math.h>


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


// function calculateBalanceFactor(node):
//   if node is null:
//     return 0 // Or some other value, as null nodes are balanced
//   else:
//     leftHeight = getHeight(node.left)
//     rightHeight = getHeight(node.right)
//     return leftHeight - rightHeight

// function getHeight(node):
//   if node is null:
//     return -1 // Or 0, depending on your height definition
//   else:
//     return 1 + max(getHeight(node.left), getHeight(node.right))


void addToHeight(struct tree_node_avl* node){
    struct tree_node_avl *current = node;
    while(current->parent !=NULL){
        current->parent->height = current->parent->height+1;
        current = current->parent;
    }
    printf("root height: %d\n", current->height);
}

struct tree_node_avl *tree_insert_avl(struct tree_node_avl* root, int value){
    printf("current node = %d\n", root->value);
    struct tree_node_avl* new_node = malloc(sizeof(struct tree_node_avl ));
    *new_node = (struct tree_node_avl){value, NULL, NULL, root, 0};
    if(root == NULL){
        printf("-------\n");
        return new_node;
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
        root->leftchild = new_node;
        printf("attached value %d as a left child of %d\n\n", value, root->value);
        addToHeight(root->leftchild);
        printf("-------\n");
        return root;
    }
    else if(value > root->value && root->rightchild != NULL){
        printf("new node %d > %d. moving to right child\n\n", value, root->value);
        return tree_insert_avl(root->rightchild, value);
    }
    else if(value > root->value){
        root->rightchild = new_node;
        printf("attached value %d as a right child of %d\n\n", value, root->value);
        addToHeight(root->rightchild);
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
