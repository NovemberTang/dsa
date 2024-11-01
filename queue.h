struct queueHeader
{
    struct node *firstNode;
    struct node *lastNode;
};

void pushQueue(struct queueHeader *header, int value);
void traverseQueue(struct queueHeader *header);
int popQueue(struct queueHeader *header);
