#include <stdio.h>  //for printf()
#include <stdlib.h> //for malloc() and NULL
#include "binarySearchTree.h"

struct tree_node;

struct tree_header;

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

struct tree_node* find_in_order_predecessor(struct tree_node* first){
    printf("Finding in-order predecessor of %d\n", first->value);
    struct tree_node* left_subtree_root = first->leftchild;
    printf("first left is %d\n", left_subtree_root->value);
    struct tree_node* current_node = left_subtree_root;
    while(current_node->rightchild!=NULL){
        current_node = current_node->rightchild;
    }
    printf("In order predecessor: %d\n", current_node->value);
    return current_node;

}

struct tree_node* delete_node_imp(struct tree_node* current_node, int value){
    if(current_node == NULL){
        //tree is empty
        printf("Value not found. Tree is empty.\n");
        return current_node;
    }
    else if(value > current_node->value){
        printf("Value not found. Turning right.\n");
        current_node->rightchild =  delete_node_imp(current_node->rightchild, value);
        return current_node;
    }
    else if(value < current_node->value){
        printf("Value not found. Turning left.\n");
        current_node->leftchild = delete_node_imp(current_node->leftchild, value);
        return current_node;
    }
    else if(current_node->value == value){
        printf("Value %d found. Deleting it.\n", value);
        int has_left_child = current_node->leftchild!=NULL;
        printf("has left child: %d\n", has_left_child);

        int has_right_child = current_node->rightchild!=NULL;
        printf("has right child: %d\n", has_right_child);

        int has_no_children = !has_left_child && !has_right_child;
        int has_two_children = has_left_child && has_right_child;
        if(has_no_children){
        free(current_node);
        return NULL;
        }
        else if(has_two_children){
            printf("Node %d has two children.\n", current_node->value);
            struct tree_node *in_order_predecessor = find_in_order_predecessor(current_node);
            current_node->value = in_order_predecessor->value;
            // The in-order predecessor node will be removed and replaced by its left child.
            // It has no right children.
            struct tree_node *to_delete = in_order_predecessor;
            current_node->leftchild = in_order_predecessor ->leftchild;
            free(to_delete);
            return current_node;
        }
        else{//has exactly one child
            printf("Value found with one child. Deleting it.\n");
            struct tree_node *child = !has_left_child ? current_node->rightchild : current_node->leftchild;
            free(current_node);
            return child;
        }
    }
}

 void delete_node(struct tree_header* header, int value){
    header->root = delete_node_imp(header->root, value);
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
        return root;
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
        return root;
    }
    else{
        printf("something weird is going on!");
        return root; //No valid children left
    }
}

void delete_bst(struct tree_node* root){ //will this fill up a stack?
    if(root != NULL){
        delete_bst(root->leftchild);
        delete_bst(root->rightchild);
        printf("Deleting %d\n", root->value);
        free(root);
    }
}

void mirror(struct tree_node* root){
    if(root!= NULL){
        mirror(root->leftchild);
        mirror(root->rightchild);
        struct tree_node *tmp = root->leftchild;
        root->leftchild = root->rightchild;
        root->rightchild = tmp;
    }
}

struct tree_node *find_min(struct tree_node* root){
    if(root == NULL || root->leftchild == NULL){
        return root;
    }else{
        return find_min(root->leftchild);
    }
}

struct tree_node *find_max(struct tree_node* root){
    if(root == NULL || root->rightchild == NULL){
        return root;
    }else{
        return find_max(root->rightchild);
    }
}

void pre_order_traversal(struct tree_node* root){
    if(root != NULL){
        printf("value: %d\n", root->value);
        pre_order_traversal(root->leftchild);
        pre_order_traversal(root->rightchild);
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
