#include "book.jliotta.h"
#include "list.jliotta.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  ListNode *list = NULL;
  Book theStrangerBook;

  initializeBook(&theStrangerBook, "The Stranger", "Camus, Albert", NULL, 1942,
                 GENRE_FICTION, 4.03);
  int rc =
      insertItem(&list, &theStrangerBook, (ComparisonFunction)compareByRating);
  if (rc != 0) {
    printf("Error from insertItem()\n");
  }

  Book *b =
      findItem(list, &theStrangerBook, (ComparisonFunction)compareByTitle);

  printList(list, (PrintFunction)printBook);

  return (0);
}
