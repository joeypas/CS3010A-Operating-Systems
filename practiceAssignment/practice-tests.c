
// jdh CS 3010 Fall 2026
//
// change the name of the include file and then compile this
// with your own practice.netid.c

#include "practice.jliotta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(int val1, int val2);
int compare_p(int *val1, int *val2);
int countChar(char ch, char *str);
char *buildString(char *str1, char *str2);
int allocInt(int value, int **newValue);
int initializeBook(char *title, char *author, int numPages, Book **newBook);

int test_compare() {
  int fail = 0;
  int rtnval;
  int v1 = 56;
  int v2 = 34;

  // test T1_1
  rtnval = compare(v1, v2);
  if (rtnval != 1) {
    printf("T1_1 error: expected 1; got %d\n", rtnval);
    fail = 1;
  }

  // test T1_2
  rtnval = compare(v2, v1);
  if (rtnval != -1) {
    printf("T1_2 error: expected -1; got %d\n", rtnval);
    fail = 1;
  }

  // test T1_3
  rtnval = compare(v1, v1);
  if (rtnval != 0) {
    printf("T1_3 error: expected 0; got %d\n", rtnval);
    fail = 1;
  }

  return fail;
} // test_compare()

//-------------------------------------------------------

int test_compare_p() {
  int fail = 0;
  int rtnval;
  int v1 = 56;
  int v2 = 34;

  // test T2_1
  rtnval = compare_p(&v1, &v2);
  if (rtnval != 1) {
    printf("T2_1 error: expected 1; got %d\n", rtnval);
    fail = 1;
  }

  // test T2_2
  rtnval = compare_p(&v2, &v1);
  if (rtnval != -1) {
    printf("T2_2 error: expected -1; got %d\n", rtnval);
    fail = 1;
  }

  // test T2_3
  rtnval = compare_p(&v1, &v1);
  if (rtnval != 0) {
    printf("T2_3 error: expected 0; got %d\n", rtnval);
    fail = 1;
  }

  return fail;
} // test_compare_p()

//-------------------------------------------------------

int test_countChar() {
  int fail = 0;
  int rtnval;
  char ch;
  char name[1 + MAX_NAME_LEN];

  // test T3_1
  strcpy(name, "new hampshire");
  ch = 'e';
  rtnval = countChar(ch, name);
  if (rtnval != 2) {
    printf("T3_1 error: expected 2; got %d\n", rtnval);
    fail = 1;
  }

  // test T3_2
  ch = 'j';
  rtnval = countChar(ch, name);
  if (rtnval != 0) {
    printf("T3_2 error: expected 0; got %d\n", rtnval);
    fail = 1;
  }

  // test T3_3
  strcpy(name, "");
  ch = 'e';
  rtnval = countChar(ch, name);
  if (rtnval != 0) {
    printf("T3_3 error: expected 0; got %d\n", rtnval);
    fail = 1;
  }

  return fail;
} // test_countChar()

//-------------------------------------------------------

int test_buildString() {
  int fail = 0;
  int rtnval;
  char s1[1 + MAX_NAME_LEN];
  char s2[1 + MAX_NAME_LEN];
  char *combinedString = NULL;

  // test T4_1
  strcpy(s1, "red");
  strcpy(s2, "blue");
  combinedString = buildString(s1, s2);
  if (strcmp(combinedString, "redblue")) {
    printf("T4_1 error: expected 'redblue'; got '%s'\n", combinedString);
    fail = 1;
  }

  // test T4_2
  strcpy(s2, "");
  combinedString = buildString(s1, s2);
  if (strcmp(combinedString, "red")) {
    printf("T4_2 error: expected 'red'; got '%s'\n", combinedString);
    fail = 1;
  }

  // test T4_3
  strcpy(s1, "");
  combinedString = buildString(s1, s2);
  if (strcmp(combinedString, "")) {
    printf("T4_3 error: expected ''; got '%s'\n", combinedString);
    fail = 1;
  }

  // test T4_4
  strcpy(s2, "green");
  combinedString = buildString(s1, s2);
  if (strcmp(combinedString, "green")) {
    printf("T4_4 error: expected 'green'; got '%s'\n", combinedString);
    fail = 1;
  }

  return fail;
} // test_buildString()

//-------------------------------------------------------

int test_allocInt() {
  int fail = 0;
  int rtnval;
  int val = 56;
  int *newVal = NULL;

  // test T5_1
  rtnval = allocInt(val, &newVal);
  if (rtnval != 0) {
    printf("T5_1 error: expected return value zero; got %d\n", rtnval);
    fail = 1;
  }

  if (*newVal != val) {
    printf("T5_1 error: expected allocated integer value to have value %d; got "
           "%d\n",
           val, *newVal);
    fail = 1;
  }

  return fail;
} // test_allocInt()

//-------------------------------------------------------

int test_initializeBook() {
  int fail = 0;
  int rtnval;
  char author[1 + MAX_NAME_LEN];
  char title[1 + MAX_NAME_LEN];
  int numPages;
  Book *b1 = NULL;

  // test T6_1
  strcpy(title, "My Life in the Bush of Ghosts");
  strcpy(author, "Amos Tutuola");
  numPages = 174;
  rtnval = initializeBook(title, author, numPages, &b1);
  if (rtnval != 0) {
    printf("T6_1 error: expected return value zero; got %d\n", rtnval);
    fail = 1;
  }

  if (strcmp(b1->title, title)) {
    printf("T6_1 error: expected title field to be '%s'; got '%s'\n", title,
           b1->title);
    fail = 1;
  }

  if (strcmp(b1->author, author)) {
    printf("T6_1 error: expected author field to be '%s'; got '%s'\n", author,
           b1->author);
    fail = 1;
  }

  if (b1->numPages != numPages) {
    printf("T6_1 error: expected numPages field to be %d; got %d\n", numPages,
           b1->numPages);
    fail = 1;
  }

  return fail;
} // test_initializeBook()

//-------------------------------------------------------

int main() {
  int numFails = 0;
  int rc;

  rc = test_compare();
  numFails = numFails + rc;

  rc = test_compare_p();
  numFails = numFails + rc;

  rc = test_countChar();
  numFails = numFails + rc;

  rc = test_buildString();
  numFails = numFails + rc;

  rc = test_allocInt();
  numFails = numFails + rc;

  rc = test_initializeBook();
  numFails = numFails + rc;

  if (numFails == 0)
    printf("all tests pass\n");
  else
    printf("%d test(s) failed\n", numFails);

  return numFails;
} // main()
