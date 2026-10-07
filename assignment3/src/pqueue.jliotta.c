#include "list.jliotta.h"
#include "pqueue.jliotta.h"
#include <stdlib.h>

int cmp(void *lhs, void *rhs, void *ret) {
  if (lhs == NULL || rhs == NULL || ret == NULL)
    return 1;

  // cast to entry type
  PQueueEntry *lentry = lhs;
  PQueueEntry *rentry = rhs;

  int *rt = (int*)ret;

  if (lentry->priority < rentry->priority)
    *rt = -1;
  else if (lentry->priority > rentry->priority)
    *rt = 1;
  else
    *rt = 0;

  return 0;
}

int enqueue(PQueueNode **pqueue, int priority, void *data) {
  if (pqueue == NULL || data == NULL)
    return 1;

  // Create the entry and check no alloc error
  PQueueEntry *entry = (PQueueEntry*)malloc(sizeof(PQueueEntry));
  if (entry == NULL)
    return 1;

  entry->priority = priority;
  entry->data = data;

  return insertItem(pqueue, entry, cmp);
}

void *dequeue(PQueueNode **pqueue) {
  if (*pqueue == NULL)
    return NULL;

  // extract types and data ptrs
  PQueueNode *head = *pqueue;
  PQueueEntry *entry = head->data;
  void *ret = entry->data;

  // update head
  *pqueue = head->next;

  // free entry first since it's a field of head
  free(entry);
  free(head);

  // return data
  return ret;
}

void *peek(PQueueNode *pqueue) {
  if (pqueue == NULL)
    return NULL;

  return ((PQueueEntry *)pqueue->data)->data;
}

void printQueue(PQueueNode *pqueue, void (*printFunction)(void *)) {
  while (pqueue != NULL) {
    PQueueEntry *entry = pqueue->data;
    printFunction(entry->data);
    pqueue = pqueue->next;
  }
}

int getMinPriority(PQueueNode *pqueue) {
  if (pqueue == NULL)
    return -1;

  return ((PQueueEntry*)pqueue->data)->priority;
}

int queueLength(PQueueNode *pqueue) {
  int len = 0;

  PQueueNode *tmp = pqueue;

  while (tmp != NULL) {
    len++;
    tmp = tmp->next;
  }

  return len;
}
