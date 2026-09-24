// jdh CS3010 Fall 2026

#include "book.jliotta.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool createAndCheck(char *testname, char *title, char *author, char *author2,
                    int year, BookGenre genre, float rating, Book *book,
                    bool expectFail) {
  int rc;
  int numfails = 0;

  rc = initializeBook(book, title, author, author2, year, genre, rating);
  if (expectFail) {
    if (rc == 0) {
      printf("error: test %s fails; expected nonzero return value; got %d\n",
             testname, rc);
      ++numfails;
    }
  } else {
    if (strcmp(book->title, title)) {
      printf("error: test %s fails; title is not correct\n", testname);
      ++numfails;
    }

    if (strcmp(book->author, author)) {
      printf("error: test %s fails; author is not correct\n", testname);
      ++numfails;
    }

    if (author2 != NULL) {
      if (strcmp(book->author2, author2)) {
        printf("error: test %s fails; author2 is not correct\n", testname);
        ++numfails;
      }
    } else {
      if (strcmp(book->author2, "")) {
        printf("error: test %s fails; author2 is not correct\n", testname);
        ++numfails;
      }
    }

    if (book->year != year) {
      printf("error: test %s fails; year is not correct\n", testname);
      ++numfails;
    }

    if (book->genre != genre) {
      printf("error: test %s fails; genre is not correct\n", testname);
      ++numfails;
    }

    if (book->rating != rating) {
      printf("error: test %s fails; rating is not correct\n", testname);
      ++numfails;
    }
  }

  if (numfails == 0)
    printf("pass test %s\n", testname);

  return numfails;
} // createAndCheck()

//-------------------------------------------------------------------

int compareCheck(char *testname, Book *b1, Book *b2,
                 int(compare)(Book *, Book *, int *result), int expectedResult,
                 int expectedReturnCode) {
  int rc;
  int result;
  bool fail = false;

  rc = compare(b1, b2, &result);
  if (rc != expectedReturnCode) {
    printf("error: test %s fails; expected rc %d from comparison; got %d\n",
           testname, expectedReturnCode, rc);
    fail = true;
  }

  if (expectedReturnCode == 0) {
    if (result != expectedResult) {
      printf(
          "error: test %s fails; expected result %d from comparison; got %d\n",
          testname, expectedResult, result);
      fail = true;
    }
  }

  if (!fail)
    printf("pass test %s\n", testname);

  return fail;
} // compareCheck()

//-------------------------------------------------------------------

int checkNumAuthors(char *testname, Book *book, int expectedResult,
                    int expectedReturnCode) {
  int result;
  int rc;
  bool fail = false;

  rc = numAuthors(book, &result);
  if (rc != expectedReturnCode) {
    printf("error: test %s fails; expected rc %d from numAuthors(); got %d\n",
           testname, expectedReturnCode, rc);
    fail = true;
  }

  if (expectedReturnCode == 0) {
    if (result != expectedResult) {
      printf("error: test %s fails; expected result %d from numAuthors(); got "
             "%d\n",
             testname, expectedResult, result);
      fail = true;
    }
  }

  if (!fail)
    printf("pass test %s\n", testname);

  return fail;
} // checkNumAuthors()

//-------------------------------------------------------------------

int main() {
  Book b1, b2, b3, b4;
  int numfails = 0;
  int rc, rtnval;

  // should fail: book is NULL
  rc = createAndCheck("T1a", "On Being", "Smith, John", NULL, 1900,
                      GENRE_SELF_HELP, 4.12, NULL, true);
  if (rc != 0)
    ++numfails;

  // should fail: title is NULL
  rc = createAndCheck("T1b", NULL, "Smith, John", NULL, 1900, GENRE_SELF_HELP,
                      4.12, &b1, true);
  if (rc != 0)
    ++numfails;

  // should fail: author is NULL
  rc = createAndCheck("T1c", "On Being", NULL, NULL, 1900, GENRE_SELF_HELP,
                      4.12, &b1, true);
  if (rc != 0)
    ++numfails;

  // should fail: year is < 1600
  rc = createAndCheck("T1d", "On Being", "Smith, John", NULL, 1500,
                      GENRE_SELF_HELP, 4.12, &b1, true);
  if (rc != 0)
    ++numfails;

  // should fail: rating < 0
  rc = createAndCheck("T1e", "On Being", "Smith, John", NULL, 1500,
                      GENRE_SELF_HELP, -4.12, &b1, true);
  if (rc != 0)
    ++numfails;

  // should fail: rating > 0
  rc = createAndCheck("T1f", "On Being", "Smith, John", NULL, 1500,
                      GENRE_SELF_HELP, 6.12, &b1, true);
  if (rc != 0)
    ++numfails;

  // should pass
  rc = createAndCheck("T2a", "On Being", "Smith, John", NULL, 1900,
                      GENRE_SELF_HELP, 4.12, &b1, false);
  if (rc != 0)
    ++numfails;

  // should pass
  rc = createAndCheck("T2b", "The Forbidden Zone", "Thompson, Jennifer",
                      "Harvey, James", 1980, GENRE_FICTION, 3.78, &b2, false);
  if (rc != 0)
    ++numfails;

  // should pass
  rc = createAndCheck("T2c", "Do Androids Dream of Electric Sleep",
                      "Dick, Philip K.", NULL, 1968, GENRE_FICTION, 4.31, &b3,
                      false);
  if (rc != 0)
    ++numfails;

  // should pass
  rc = createAndCheck("T2d", "Being and Nothingness", "Jean-Paul Sartre", NULL,
                      1943, GENRE_NONFICTION, 3.67, &b4, false);
  if (rc != 0)
    ++numfails;

  // b1 is "On Being" "Smith, John", 1900, GENRE_SELF_HELP, 4.12
  // b2 is "The Forbidden Zone", "Thompson, Jennifer" and "Harvey, James", 1980,
  // GENRE_FICTION, 3.78 b3 is "Do Androids Dream of Electric Sleep", "Dick,
  // Philip K.", 1968, GENRE_FICTION, 4.31 b4 is "Being and Nothingness",
  // "Sartre, Jean-Paul", 1943, GENRE_NONFICTION, 3.67

  // compare should produce zero
  rc = compareCheck("T3a", &b1, &b1, compareByTitle, 0, 0);
  if (rc != 0)
    ++numfails;

  // compare should produce one: b1 title > b2 title
  rc = compareCheck("T3b", &b1, &b3, compareByTitle, 1, 0);
  if (rc != 0)
    ++numfails;

  // compare should produce -1: b4 title < b3 title
  rc = compareCheck("T3c", &b4, &b3, compareByTitle, -1, 0);
  if (rc != 0)
    ++numfails;

  // compare should fail for null pointer
  rc = compareCheck("T3d", NULL, &b3, compareByTitle, 0, 1);
  if (rc != 0)
    ++numfails;

  // compare should produce 0: b3 author == b3 author
  rc = compareCheck("T4a", &b3, &b3, compareByAuthor, 0, 0);
  if (rc != 0)
    ++numfails;

  // compare should produce 1: b4 author > b3 author
  rc = compareCheck("T4b", &b4, &b3, compareByAuthor, 1, 0);
  if (rc != 0)
    ++numfails;

  // compare should produce fail for null pointer
  rc = compareCheck("T4c", &b3, NULL, compareByAuthor, 0, 1);
  if (rc != 0)
    ++numfails;

  // compare should produce -1: b1 year < b4 year
  rc = compareCheck("T5a", &b1, &b4, compareByYear, -1, 0);
  if (rc != 0)
    ++numfails;

  // compare should produce 0: b1 year == b1 year
  rc = compareCheck("T5b", &b1, &b1, compareByYear, 0, 0);
  if (rc != 0)
    ++numfails;

  // compare should produce 0: b4 year > b1 year
  rc = compareCheck("T5c", &b4, &b1, compareByYear, 1, 0);
  if (rc != 0)
    ++numfails;

  // compare should produce -1: b2 rating < b1 rating
  rc = compareCheck("T6a", &b2, &b1, compareByRating, -1, 0);
  if (rc != 0)
    ++numfails;

  // compare should produce 0: b2 rating == b2 rating
  rc = compareCheck("T6b", &b2, &b2, compareByRating, 0, 0);
  if (rc != 0)
    ++numfails;

  // compare should produce 0: b3 rating > b4 rating
  rc = compareCheck("T6c", &b3, &b4, compareByRating, 1, 0);
  if (rc != 0)
    ++numfails;

  // one author
  rc = checkNumAuthors("T7a", &b1, 1, 0);
  if (rc != 0)
    ++numfails;

  // two authors
  rc = checkNumAuthors("T7b", &b2, 2, 0);
  if (rc != 0)
    ++numfails;

  // fail in numAuthors()
  rc = checkNumAuthors("T7c", NULL, 0, 1);
  if (rc != 0)
    ++numfails;

  printf("\n");
  printf("Here's a call to printBook()\n");
  printf("It should print this line:\n");
  printf("\"Do Androids Dream of Electric Sleep\" (Dick, Philip K.), 1968, "
         "fiction, 4.31\n");
  printf("---->\n");
  rc = printBook(&b3);
  printf("<----\n");
  if (rc != 0) {
    printf("T19: expect zero from printBook(); got %d\n", rc);
    ++numfails;
  }

  printf("\n");
  printf("this call to printBook() should fail\n");
  printf("---->\n");
  rc = printBook(NULL);
  printf("<----\n");
  if (rc == 0) {
    printf("T20: expect nonzero from printBook(); got %d\n", rc);
    ++numfails;
  }

  if (numfails == 0) {
    printf("all tests pass\n");
    rtnval = 0;
  } else {
    printf("%d test(s) failed\n", numfails);
    rtnval = 8;
  }

  return rtnval;
}
