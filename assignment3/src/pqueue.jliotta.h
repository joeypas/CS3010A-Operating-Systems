typedef ListNode PQueueNode;

typedef struct {
  int priority;
  void *data;
} PQueueEntry;

/// Allocate an entry and insert it into the queue (sorted by priority in ascending order)
int enqueue(PQueueNode **pqueue, int priority, void *data);
/// Free entry and node at head of the queue and return the datq
void *dequeue(PQueueNode **pqueue);
/// Returns data at head of queue
void *peek(PQueueNode *pqueue);
/// Print data in each entry
void printQueue(PQueueNode *pqueue, void (printFunction)(void*));
/// Returns priority of entry at head of the queue
int getMinPriority(PQueueNode *pqueue);
/// Returns length of the queue
int queueLength(PQueueNode *pqueue);

