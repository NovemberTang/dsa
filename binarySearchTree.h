

typedef struct tree_node{
    int value;
    struct tree_node *leftchild;
    struct tree_node *rightchild;
}tree_node;

typedef struct tree_header
{
    struct tree_node *root;
}tree_header;
