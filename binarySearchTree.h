

typedef struct tree_node{
    int value;
    struct tree_node *leftchild;
    struct tree_node *rightchild;
}tree_node;

typedef struct tree_header
{
    struct tree_node *root;
}tree_header;

struct tree_node *tree_insert(struct tree_node* root, int value);
struct tree_node *find_node(struct tree_node *root, int value);
