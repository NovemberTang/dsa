typedef struct doubleNode
{
    int value;
    struct doubleNode *next;
    struct doubleNode *prev;
}doubleNode;

void traverseDouble(struct doubleNode* first); //TODO remove struct from here and the actual function definition

void reverseTraverseDouble(struct doubleNode last);

struct doubleNode *insertIntoPositionDouble(struct doubleNode *first, int value, int pos);

struct doubleNode *deleteFromStartDouble(struct doubleNode *first);

struct doubleNode *deleteFromEndDouble(struct doubleNode *first);

struct doubleNode *deleteAfterIndexDouble(struct doubleNode *first, int pos);