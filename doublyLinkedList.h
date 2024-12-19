typedef struct doubleNode
{
    int value;
    struct doubleNode *next;
    struct doubleNode *prev;
}doubleNode;

void traverseDouble(doubleNode* first);

void reverseTraverseDouble(doubleNode* last);

struct doubleNode *insertIntoPositionDouble(struct doubleNode *first, int value, int pos);

struct doubleNode *deleteFromStartDouble(struct doubleNode *first);

struct doubleNode *deleteFromEndDouble(struct doubleNode *first);

struct doubleNode *deleteAfterIndexDouble(struct doubleNode *first, int pos);
