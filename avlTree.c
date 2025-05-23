#include <stdlib.h> //for malloc() and NULL
#include <stdio.h>  //for printf()

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


    if(g_balance_factor==-2){
        if (p_balance_factor == 1){
        printf("RL rotation. Moving to RR\n");
        //5     g_node    5         g_node
        //  60  p_node      10      node
        //10    node           60   p_node

        struct tree_node_avl *p_node = node->parent;
        struct tree_node_avl *g_node = p_node->parent;

        g_node->rightchild=node;
        node->parent=g_node;

        node->rightchild = p_node;
        p_node->parent = node;

        p_node->leftchild=NULL;

        g_node->leftchild=NULL;
        node->leftchild=NULL;

        //node now points to the parent position and needs to be moved down a level
        node = p_node;

        p_node->height = 1;
        node->height = 2;

        printf("n: %d, height: %d - p: %d, height: %d -  g: %d, height: %d\n",
            node->value, node->height,
            node->parent->value, node->parent->height,
            node->parent->parent->value, node->parent->parent->height);

    }

    int g_value = node->parent->parent->value;
    int p_value = node->parent->value;
    int c_value = node->value;
    printf("RR rotation\n");
    node->parent->parent->value=p_value;

    node->parent->value = c_value;
    
    node->parent->rightchild = NULL; //changing a ref, not moving a physical node.
    *node = (struct tree_node_avl){g_value, NULL, NULL, node->parent->parent, 1}; //i think the height should be 1, not 0
    node->parent->leftchild = node;
    node->parent->leftchild->height=1;
    node->parent->rightchild->height=1;
    node->parent->height=2;

    printf("finished rotation\n");
    printf("parent: %d, height: %d\nleft: %d, height: %d\nright: %d, height: %d\n",
        node->parent->value, node->parent->height,
        node->parent->leftchild->value, node->parent->leftchild->height,
        node->parent->rightchild->value, node->parent->rightchild->height);
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

        p_node->height = 1;
        node->height = 2;
        }

        int g_value = node->parent->parent->value;
        int p_value = node->parent->value;
        int c_value = node->value;

        printf("LL rotation\n");
        node->parent->parent->value=p_value;
        node->parent->value = c_value;
        node->parent->leftchild = NULL; //changing a ref, not moving a physical node.
        *node = (struct tree_node_avl){g_value, NULL, NULL, node->parent->parent, 1}; //i think the height should be 1, not 0
        node->parent->rightchild = node;

        node->parent->leftchild = node;
        node->parent->leftchild->height=1;
        node->parent->rightchild->height=1;
        node->parent->height=2;

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
