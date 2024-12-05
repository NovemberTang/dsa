//PRIORITY QUEUE
typedef struct pq_node{
    int priority;
    int value;
    struct pq_node* next;
}pq_node;

typedef struct priority_queue {
    pq_node* first;
}priority_queue;


pq_node* findLastElementWithPriorityX(int priority, priority_queue *queue);
void insertIntoPriorityQueue(int priority, int value, priority_queue *queue);
void traversePriorityQueue(priority_queue *queue);
int popPriorityQueue(priority_queue *queue);
