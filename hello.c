#include <stdio.h>  //for printf()
#include <stdlib.h> //for malloc() and NULL
#include "arrayUtils.h"
#include "stack.h"
#include "binarySearchTree.h"
#include <math.h>
#include <string.h> //for strcpy


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

int check_balance_factor(struct tree_node_avl* node){
    int left = (node->leftchild == NULL) ? 0 : node->leftchild->height;
    int right = (node->rightchild == NULL) ? 0 : node->rightchild->height;
    int balance_factor = left-right; //TODO inline
    return balance_factor;
}

void avl_rotation(struct tree_node_avl* node){

    int g_balance_factor = check_balance_factor(node->parent->parent);
    int p_balance_factor = check_balance_factor(node->parent);

    int g_value = node->parent->parent->value;
    int p_value = node->parent->value;
    int c_value = node->value;

    if(g_balance_factor==-2){
        if (p_balance_factor == 1){
        printf("RL rotation. Moving to RR\n");

        struct tree_node_avl *p_node = node->parent;
        struct tree_node_avl *g_node = p_node->parent;
            
        g_node->rightchild=node;
        node->parent=g_node;

        node->rightchild = p_node;
        p_node ->parent = node;

        p_node->leftchild=NULL;

        //node now points to the parent position and needs to be moved down a level
        node = p_node;

    }

    printf("RR rotation\n");
    node->parent->parent->value=p_value;
    node->parent->value = c_value;
    node->parent->rightchild = NULL; //changing a ref, not moving a physical node.
    *node = (struct tree_node_avl){g_value, NULL, NULL, node->parent->parent, 1}; //i think the height should be 1, not 0
    node->parent->leftchild = node;
    printf("finished rotation\n");
}

    if(g_balance_factor==2 ){
        if(p_balance_factor == -1){
            printf("LR rotation. Moving to LL\n");
            struct tree_node_avl *p_node = node->parent;
            struct tree_node_avl *g_node = p_node->parent;

            g_node->leftchild=node;
            node->parent=g_node;

            node->leftchild = p_node;
            p_node ->parent = node;

            p_node->rightchild=NULL;

            //node now points to the parent position and needs to be moved down a level
            node = p_node;
        }

        printf("LL rotation\n");
        node->parent->parent->value=p_value;
        node->parent->value = c_value;
        node->parent->leftchild = NULL; //changing a ref, not moving a physical node.
        *node = (struct tree_node_avl){g_value, NULL, NULL, node->parent->parent, 1}; //i think the height should be 1, not 0
        node->parent->rightchild = node;
        printf("finished rotation\n");
        
    }
        // node->parent->parent->leftchild=NULL;

}

void addToHeight(struct tree_node_avl* node){
    struct tree_node_avl *current = node;
    while(current->parent !=NULL){
        current->parent->height = current->parent->height+1;
        current = current->parent;
    }
    printf("height from %d to %d: %d\n", node->value, current->value, current->height);
}

struct tree_node_avl *tree_insert_avl(struct tree_node_avl* root, int value){
    printf("current node = %d\n", root->value);
    struct tree_node_avl* new_node = malloc(sizeof(struct tree_node_avl ));
    *new_node = (struct tree_node_avl){value, NULL, NULL, root, 1}; //i think the height should be 1, not 0
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
        if(new_node->parent !=NULL && new_node->parent->parent != NULL){
            avl_rotation(new_node);
        }
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
        if(new_node->parent !=NULL && new_node->parent->parent != NULL){
            avl_rotation(new_node);
        }
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
    *root = (struct tree_node_avl){5, NULL, NULL, NULL, 1};

    //RR - done
    //RL - ???
    //LL - done
    // LR - ???

    //TODO test LR and RL rotation
    tree_insert_avl(root, 8);
    tree_insert_avl(root, 7);
    printf("root: %d\n", root->value);
    printf("leftchild: %d\n", root->leftchild->value);
    printf("new rightchild: %d\n", root->rightchild->value);
    // tree_insert_avl(root, 20);
    // tree_insert(root, 30);
    // tree_insert(root, 19);
    // tree_insert(root, 120);
    // tree_insert(root, 100);
    // tree_insert(root, 80);
    // tree_insert(root, 19);

    printf("height: %d\n", root->height);

    return 0;

}
