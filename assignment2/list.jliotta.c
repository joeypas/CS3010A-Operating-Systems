#include "list.jliotta.h"
#include <stdio.h>
#include <stdlib.h>

int initNode(ListNode **node, void *data) {
  if (node == NULL || data == NULL)
    return 1;

  ListNode *newNode = malloc(sizeof(ListNode));
  if (newNode == NULL)
    return 1;

  newNode->data = data;
  newNode->next = NULL;

  *node = newNode;
  return 0;
}

int insertItem(ListNode **list, void *data, ComparisonFunction compare) {
  if (list == NULL || data == NULL || compare == NULL)
    return 1;

  ListNode *curr = *list;
  ListNode *prev = NULL;
  ListNode *newNode = NULL;

  if (initNode(&newNode, data))
    return 1;

  if (curr == NULL) {
    *list = newNode;
    return 0;
  }

  int cmp = 0;
  while (curr != NULL) {
    if (compare(data, curr->data, &cmp) != 0) {
      free(newNode);
      return 1;
    }
    if (cmp < 0)
      break;
    prev = curr;
    curr = curr->next;
  }

  newNode->next = curr;
  if (prev != NULL)
    prev->next = newNode;
  else
    *list = newNode;

  return 0;
}

void *findItem(ListNode *list, void *item, ComparisonFunction compare) {
  if (item == NULL || compare == NULL)
    return NULL;

  ListNode *curr = list;

  while (curr != NULL) {
    int cmp = 0;
    if (compare(item, curr->data, &cmp) != 0)
      return NULL;
    if (cmp == 0)
      return curr->data;
    curr = curr->next;
  }

  return NULL;
}

void *removeItem(ListNode **list, void *item, ComparisonFunction compare) {
  if (list == NULL || item == NULL || compare == NULL)
    return NULL;

  ListNode *curr = *list;
  ListNode *prev = NULL;

  int cmp = 0;
  while (curr != NULL) {
    if (compare(curr->data, item, &cmp) != 0)
      return NULL;
    if (cmp == 0)
      break;
    prev = curr;
    curr = curr->next;
  }

  if (curr == NULL)
    return NULL;

  if (prev != NULL)
    prev->next = curr->next;
  else
    *list = curr->next;

  void *ret = curr->data;
  free(curr);

  return ret;
}

void *removeNthItem(ListNode **list, int pos) {
  if (list == NULL || pos < 0)
    return NULL;

  ListNode *curr = *list;
  ListNode *prev = NULL;
  int i = 0;

  while (curr != NULL && i != pos) {
    prev = curr;
    curr = curr->next;
    i++;
  }

  if (curr == NULL || i != pos)
    return NULL;

  if (prev != NULL)
    prev->next = curr->next;
  else
    *list = curr->next;

  void *ret = curr->data;
  free(curr);
  return ret;
}

void *findNthItem(ListNode *list, int pos) {
  if (pos < 0)
    return NULL;

  ListNode *curr = list;
  int i = 0;

  while (curr != NULL && i < pos) {
    curr = curr->next;
    i++;
  }

  if (curr == NULL || i != pos)
    return NULL;

  return curr->data;
}

int printList(ListNode *list, PrintFunction print) {
  if (print == NULL)
    return 1;

  ListNode *curr = list;

  while (curr != NULL) {
    print(curr->data);
    curr = curr->next;
  }
  return 0;
}
