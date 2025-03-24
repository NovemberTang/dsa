#include <stdio.h>  //for printf()
#include <stdlib.h> //for malloc() and NULL
#include "arrayUtils.h"
#include "stack.h"
#include "binarySearchTree.h"

void pre_order_traversal(struct tree_node* root){
    if(root != NULL){
        printf("value: %d\n", root->value);
        pre_order_traversal(root->leftchild);
        pre_order_traversal(root->rightchild);
    }
}

void in_order_traversal(struct tree_node* root){
    if(root!=NULL){
        in_order_traversal(root->leftchild);
        printf("value: %d\n", root->value);
        in_order_traversal(root->rightchild);
    }
}

void post_order_traversal(struct tree_node* root){
    if(root!=NULL){
        post_order_traversal(root->leftchild);
        post_order_traversal(root->rightchild);
        printf("value: %d\n", root->value);
    }
}


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

int main()
{

    //      3
    //   1     6
    // 0     5   8
    //X X   4 X X X
    //assmeble the right subtree
    struct tree_node *eight = malloc(sizeof(struct tree_node));
    *eight = (struct tree_node){8, NULL, NULL};

    struct tree_node *four = malloc(sizeof(struct tree_node));
    *four = (struct tree_node){4, NULL, NULL};

    struct tree_node *five = malloc(sizeof(struct tree_node));
    *five = (struct tree_node){5, four, NULL};

    struct tree_node *six = malloc(sizeof(struct tree_node));
    *six = (struct tree_node){ 6, five, eight};

    // assemble the left subtree
    struct tree_node *zero = malloc(sizeof(struct tree_node));
    *zero = (struct tree_node){0, NULL, NULL};

    struct tree_node *one = malloc(sizeof(struct tree_node));
    *one = (struct tree_node){1, zero, NULL};

    //bring together at the root
    struct tree_node *three = malloc(sizeof(struct tree_node));
    *three = (struct tree_node){3, one, six};

    struct tree_header *header = malloc(sizeof(struct tree_header));
    *header = (struct tree_header){three};

    post_order_traversal(header->root);

}
