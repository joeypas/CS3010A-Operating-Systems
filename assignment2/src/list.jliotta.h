typedef struct ListNodeStruct {
  void *data;
  struct ListNodeStruct *next;
} ListNode;

typedef int (*ComparisonFunction)(void *, void *, int *);
typedef void (*PrintFunction)(void *);

int insertItem(ListNode **list, void *data, ComparisonFunction compare);

void *findItem(ListNode *theList, void *item, ComparisonFunction compare);

void *removeItem(ListNode **list, void *item, ComparisonFunction compare);

void *removeNthItem(ListNode **list, int pos);

void *findNthItem(ListNode *list, int pos);

int printList(ListNode *list, PrintFunction print);
