// jdh 5-20-26

#include "list.jliotta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFLEN 256

int readcsv(FILE *fp, char delimChar, int numFields, ListNode **theList) {
  char *chp, *chp2;
  char buffer[BUFLEN];
  char currToken[BUFLEN];
  char **stringArray;
  ListNode *newNode;
  int lineNum = 0;
  int i;
  int tokenIdx, lineIdx, currwordIdx;

  *theList = NULL;

  chp = fgets(buffer, BUFLEN, fp);

  // count the number of delimiter chars
  int count = 0;
  if (chp != NULL) {
    buffer[strlen(buffer) - 1] = '\0';
    for (i = 0; i < strlen(buffer); ++i) {
      if (buffer[i] == delimChar)
        count = count + 1;
    }

    if (count != numFields + 1) {
      printf("error: incorrect #fields (%d) in first line: expected %d\n",
             count, numFields);
      return 1;
    }
  }

  while (chp != NULL) {
    stringArray = (char **)malloc(numFields * sizeof(char *));
    tokenIdx = 0;
    currwordIdx = 0;
    lineIdx = 1;
    while (lineIdx < strlen(buffer)) {
      while (buffer[lineIdx] != delimChar) {
        currToken[currwordIdx] = buffer[lineIdx];
        ++currwordIdx;
        ++lineIdx;
      }
      currToken[currwordIdx] = '\0';
      stringArray[tokenIdx] = malloc(1 + strlen(currToken));
      // printf("read |%s|\n", currToken);
      strcpy(stringArray[tokenIdx], currToken);
      currwordIdx = 0;
      ++tokenIdx;
      ++lineIdx;
      if (tokenIdx > numFields && lineIdx != strlen(buffer)) {
        // printf("lineIdx = %d; len = %lu\n", lineIdx, strlen(buffer));
        printf("error: too many fields (%d) in line %d\n", tokenIdx, lineNum);
        return 1;
      }
    }

    if (tokenIdx < numFields) {
      printf("error: too few fields (%d) in line %d\n", tokenIdx, lineNum);
      return 1;
    }

    newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->data = stringArray;
    newNode->next = *theList;
    *theList = newNode;
    chp = fgets(buffer, BUFLEN, fp);
    if (chp != NULL)
      buffer[strlen(buffer) - 1] = '\0';
    ++lineNum;
  }

  return 0;
} // readcsv()
