struct node
{
    int value;
    struct node *next;
};

void traverse(struct node first);
int *search(struct node first, int value);
struct node *prependToLinkedList(struct node *list, int value);
void appendToLinkedList(struct node *first, int value);
