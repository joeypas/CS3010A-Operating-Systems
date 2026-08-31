#include "practice.jliotta.h"
#include <stdlib.h>
#include <string.h>

int compare(int val1, int val2) {
  if (val1 > val2)
    return 1;
  else if (val2 > val1)
    return -1;
  else
    return 0;
}

int compare_p(int *val1, int *val2) {
  if (*val1 > *val2)
    return 1;
  else if (*val2 > *val1)
    return -1;
  else
    return 0;
}

int countChar(char ch, char *str) {
  int count = 0;

  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == ch)
      count++;
  }

  return count;
}

int allocInt(int value, int **newValue) {
  (*newValue) = malloc(sizeof(int));

  if (*newValue == NULL)
    return 1;

  **newValue = value;

  return 0;
}

char *buildString(char *str1, char *str2) {
  char *ret;
  size_t size;

  size = strlen(str1) + strlen(str2) + 1;
  ret = malloc(sizeof(*ret) * size);

  // Allocation can fail
  if (ret == NULL)
    return NULL;

  strcpy(ret, str1);
  strcat(ret, str2);

  return ret;
}

int initializeBook(char *title, char *author, int numPages, Book **newBook) {
  // Make sure no buff overflow
  if (strlen(title) > MAX_NAME_LEN || strlen(author) > MAX_NAME_LEN)
    return 1;

  *newBook = malloc(sizeof(Book));

  // Allocation can fail
  if (*newBook == NULL)
    return 1;

  strcpy((*newBook)->title, title);
  strcpy((*newBook)->author, author);
  (*newBook)->numPages = numPages;

  return 0;
}
