struct node
{
    int value;
    struct node *next;
};

void traverse(struct node first);
int *search(struct node first, int value);
struct node *prependToLinkedList(struct node *list, int value);
void appendToLinkedList(struct node *first, int value);
void insertIntoPositionInLinkedList(struct node *first, int value, int pos);
struct node *deleteHeadOfLinkedList(struct node *first);
void deleteLastInLinkedList(struct node *first);
void deleteAfterIndexInLinkedList(struct node *first, int idx);
void concatenate(struct node *list1, struct node *list2);
void sortLinkedList(struct node *first);
struct node *reverseLinkedList(struct node *first);
