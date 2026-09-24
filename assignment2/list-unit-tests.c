#include "book.jliotta.h"
#include "list.jliotta.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csvreader.h"

#define BOOKS_CSV_FILENAME "books.csv"
#define BOOKS_CSV_NUMFIELDS 6

//--------------------------------------------------------------------------

bool findTest(char *testname, ListNode *theList, Book *searchFor,
              Book *expBook) {
  Book *book;
  bool fail;

  fail = false;
  book = findItem(theList, searchFor, (ComparisonFunction)compareByTitle);
  if (expBook == NULL) {
    if (book != NULL) {
      printf("%s: bad result from find; expected result == NULL for finding "
             "'%s'\n",
             testname, searchFor->title);
      fail = true;
    }
  } else {
    if (book == NULL) {
      printf("%s: bad result from find; expected result != NULL for finding "
             "'%s'\n",
             testname, searchFor->title);
      fail = true;
    } else {
      if (strcmp(book->title, expBook->title) != 0) {
        printf("%s: bad result from find; expected title='%s' got '%s'\n",
               testname, expBook->title, book->title);
        fail = true;
      }

      if (strcmp(book->author, expBook->author) != 0) {
        printf("%s: bad result from find; expected author='%s' got '%s'\n",
               testname, expBook->author, book->author);
        fail = true;
      }

      if (strcmp(book->author2, expBook->author2) != 0) {
        printf("%s: bad result from find; expected author2='%s' got '%s'\n",
               testname, expBook->author2, book->author2);
        fail = true;
      }

      if (book->year != expBook->year) {
        printf("%s: bad result from find; expected year='%d' got '%d'\n",
               testname, expBook->year, book->year);
        fail = true;
      }

      if (book->genre != expBook->genre) {
        printf("%s: bad result from find; expected genre='%d' got '%d'\n",
               testname, expBook->genre, book->genre);
        fail = true;
      }

      if (book->rating != expBook->rating) {
        printf("%s: bad result from find; expected rating='%.2f' got '%.2f'\n",
               testname, expBook->rating, book->rating);
        fail = true;
      }
    }
  }

  return fail;
} // findTest()

//---------------------------------------------------------------

bool findNthTest(char *testname, ListNode *theList, int pos, Book *expBook) {
  Book *book;
  bool fail;

  fail = false;
  book = findNthItem(theList, pos);
  if (expBook == NULL) {
    if (book != NULL) {
      printf("%s: bad result from findNth; expected result == NULL for finding "
             "item at position %d\n",
             testname, pos);
      fail = true;
    }
  } else {
    if (book == NULL) {
      printf("%s: bad result from findNth; expected result != NULL for finding "
             "item at position %d\n",
             testname, pos);
      fail = true;
    } else {
      if (strcmp(book->title, expBook->title) != 0) {
        printf("%s: bad result from findNth pos=%d; expected title='%s' got "
               "'%s'\n",
               testname, pos, expBook->title, book->title);
        fail = true;
      }

      if (strcmp(book->author, expBook->author) != 0) {
        printf("%s: bad result from findNth pos=%d; expected author='%s' got "
               "'%s'\n",
               testname, pos, expBook->author, book->author);
        fail = true;
      }

      if (strcmp(book->author2, expBook->author2) != 0) {
        printf("%s: bad result from findNth pos=%d; expected author2='%s' got "
               "'%s'\n",
               testname, pos, expBook->author2, book->author2);
        fail = true;
      }

      if (book->year != expBook->year) {
        printf(
            "%s: bad result from findNth pos=%d; expected year='%d' got '%d'\n",
            testname, pos, expBook->year, book->year);
        fail = true;
      }

      if (book->genre != expBook->genre) {
        printf("%s: bad result from findNth pos=%d; expected genre='%d' got "
               "'%d'\n",
               testname, pos, expBook->genre, book->genre);
        fail = true;
      }

      if (book->rating != expBook->rating) {
        printf("%s: bad result from findNth pos=%d; expected rating='%.2f' got "
               "'%.2f'\n",
               testname, pos, expBook->rating, book->rating);
        fail = true;
      }
    }
  }
  return fail;
} // findNthTest()

//---------------------------------------------------------------

bool removeNthTest(char *testname, ListNode **theList, int pos, Book *expBook) {
  Book *book;
  bool fail;

  fail = false;
  book = removeNthItem(theList, pos);
  if (expBook == NULL) {
    if (book != NULL) {
      printf("%s: bad result from removeNth; expected result == NULL for "
             "removing item at position %d\n",
             testname, pos);
      fail = true;
    }
  } else {
    if (book == NULL) {
      printf("%s: bad result from removeNth; expected result != NULL for "
             "removing item at position %d\n",
             testname, pos);
      fail = true;
    } else {
      if (strcmp(book->title, expBook->title) != 0) {
        printf("%s: bad result from removeNth pos=%d; expected title='%s' got "
               "'%s'\n",
               testname, pos, expBook->title, book->title);
        fail = true;
      }

      if (strcmp(book->author, expBook->author) != 0) {
        printf("%s: bad result from removeNth pos=%d; expected author='%s' got "
               "'%s'\n",
               testname, pos, expBook->author, book->author);
        fail = true;
      }

      if (strcmp(book->author2, expBook->author2) != 0) {
        printf("%s: bad result from removeNth pos=%d; expected author2='%s' "
               "got '%s'\n",
               testname, pos, expBook->author2, book->author2);
        fail = true;
      }

      if (book->year != expBook->year) {
        printf("%s: bad result from removeNth pos=%d; expected year='%d' got "
               "'%d'\n",
               testname, pos, expBook->year, book->year);
        fail = true;
      }
      if (book->genre != expBook->genre) {
        printf("%s: bad result from removeNth pos=%d; expected genre='%d' got "
               "'%d'\n",
               testname, pos, expBook->genre, book->genre);
        fail = true;
      }

      if (book->rating != expBook->rating) {
        printf("%s: bad result from removeNth pos=%d; expected rating='%.2f' "
               "got '%.2f'\n",
               testname, pos, expBook->rating, book->rating);
        fail = true;
      }
    }
  }
  return fail;
} // removeNthTest()

//---------------------------------------------------------------

bool removeTest(char *testname, ListNode **theList, ComparisonFunction compare,
                Book *expBook, bool expResult) {
  Book *book;
  bool fail;

  fail = false;
  book = removeItem(theList, expBook, compare);
  if (expResult == false) {
    if (book != NULL) {
      printf("%s: bad result from removeItem(); expected result == NULL for "
             "removing item\n",
             testname);
      fail = true;
    }
  } else {
    if (book == NULL) {
      printf("%s: bad result from removeItem(); expected result != NULL for "
             "removing item\n",
             testname);
      fail = true;
    } else {
      if (strcmp(book->title, expBook->title) != 0) {
        printf(
            "%s: bad result from removeItem(); expected title='%s' got '%s'\n",
            testname, expBook->title, book->title);
        fail = true;
      }

      if (strcmp(book->author, expBook->author) != 0) {
        printf(
            "%s: bad result from removeItem(); expected author='%s' got '%s'\n",
            testname, expBook->author, book->author);
        fail = true;
      }

      if (strcmp(book->author2, expBook->author2) != 0) {
        printf("%s: bad result from removeItem(); expected author2='%s' got "
               "'%s'\n",
               testname, expBook->author2, book->author2);
        fail = true;
      }

      if (book->year != expBook->year) {
        printf(
            "%s: bad result from removeItem(); expected year='%d' got '%d'\n",
            testname, expBook->year, book->year);
        fail = true;
      }
      if (book->genre != expBook->genre) {
        printf(
            "%s: bad result from removeItem(); expected genre='%d' got '%d'\n",
            testname, expBook->genre, book->genre);
        fail = true;
      }

      if (book->rating != expBook->rating) {
        printf("%s: bad result from removeItem(); expected rating='%.2f' got "
               "'%.2f'\n",
               testname, expBook->rating, book->rating);
        fail = true;
      }
    }
  }
  return fail;
} // removeTest()

//---------------------------------------------------------------

int csvTests() {
  ListNode *bookList = NULL;
  ListNode *stringsList = NULL;
  ListNode *listNode;
  int rc, fail;
  FILE *fp;

  fail = false;

  fp = fopen(BOOKS_CSV_FILENAME, "r");
  if (fp == NULL) {
    printf("cannot open file '%s'\n", BOOKS_CSV_FILENAME);
    return 1;
  }

  rc = readcsv(fp, '|', BOOKS_CSV_NUMFIELDS, &stringsList);
  if (rc != 0) {
    printf("error from readcsv()\n");
    return 1;
  }

  fclose(fp);

  listNode = stringsList;
  while (listNode != NULL) {
    char **stringArray = (char **)listNode->data;
    Book *book = malloc(sizeof(Book));
    rc = initializeBookFromStrings(book, stringArray);
    if (rc == 0) {
      rc = insertItem(&bookList, book, (ComparisonFunction)compareByRating);
      if (rc != 0) {
        printf("ERROR: insertItem() failed\n");
        fail = true;
      }
    } else {
      printf("ERROR: initializeBookFromStrings() failed\n");
      fail = true;
    }
    listNode = listNode->next;
  }

  // check the tenth item (position = 9)
  Book sunAlsoRisesBook;
  rc = initializeBook(&sunAlsoRisesBook, "The Sun Also Rises",
                      "Hemingway, Ernest", NULL, 1926, GENRE_FICTION, 3.79);
  if (rc != 0) {
    printf("ERROR: initializeBook() failed\n");
    fail = true;
  }

  rc = findNthTest("T1a", bookList, 9, &sunAlsoRisesBook);
  if (rc != 0)
    fail = true;

  Book powersThatBeBook;
  rc = initializeBook(&powersThatBeBook, "Powers That Be", "McCaffrey, Anne",
                      "Scarborough, Elizabeth Anne", 1966, GENRE_FICTION, 3.93);
  if (rc != 0) {
    printf("ERROR: initializeBook() failed\n");
    fail = true;
  }

  rc = findTest("T1b", bookList, &powersThatBeBook, &powersThatBeBook);
  if (rc != 0)
    fail = true;

  if (fail) {
    printf("csv tests failed\n");
    return 1;
  } else {
    printf("csv tests passed\n");
    return 0;
  }

} // csvTests()

//---------------------------------------------------------------

int generalTests() {
  ListNode *bookList = NULL;
  ListNode *listNode;
  int rc;
  int numfails = 0;

  Book sunAlsoRisesBook;
  rc = initializeBook(&sunAlsoRisesBook, "The Sun Also Rises",
                      "Hemingway, Ernest", NULL, 1926, GENRE_FICTION, 3.79);
  if (rc != 0) {
    printf("ERROR: initializeBook() failed\n");
    ++numfails;
  }

  Book powersThatBeBook;
  rc = initializeBook(&powersThatBeBook, "Powers That Be", "McCaffrey, Anne",
                      "Scarborough, Elizabeth Anne", 1966, GENRE_FICTION, 3.93);
  if (rc != 0) {
    printf("ERROR: initializeBook() failed\n");
    ++numfails;
  }

  Book watershipDownBook;
  rc = initializeBook(&watershipDownBook, "Watership Down", "Adams, Richard",
                      NULL, 1972, GENRE_FICTION, 4.09);
  if (rc != 0) {
    printf("ERROR: initializeBook() failed\n");
    ++numfails;
  }

  Book poisonwoodBibleBook;
  rc = initializeBook(&poisonwoodBibleBook, "The Poisonwood Bible",
                      "Kingsolver, Barbara", NULL, 1998, GENRE_FICTION, 4.11);
  if (rc != 0) {
    printf("ERROR: initializeBook() failed\n");
    ++numfails;
  }

  rc = insertItem(&bookList, &sunAlsoRisesBook,
                  (ComparisonFunction)compareByAuthor);
  if (rc != 0) {
    printf("ERROR: insertItem() failed\n");
    ++numfails;
  }

  rc = insertItem(&bookList, &poisonwoodBibleBook,
                  (ComparisonFunction)compareByAuthor);
  if (rc != 0) {
    printf("ERROR: insertItem() failed\n");
    ++numfails;
  }

  rc = insertItem(&bookList, &watershipDownBook,
                  (ComparisonFunction)compareByAuthor);
  if (rc != 0) {
    printf("ERROR: insertItem() failed\n");
    ++numfails;
  }

  rc = insertItem(&bookList, &powersThatBeBook,
                  (ComparisonFunction)compareByAuthor);
  if (rc != 0) {
    printf("ERROR: insertItem() failed\n");
    ++numfails;
  }

  // list should now be:
  // "Watership Down" (Adams, Richard), 1972, fiction, 4.09
  // "The Sun Also Rises" (Hemingway, Ernest), 1926, fiction, 3.79
  // "The Poisonwood Bible" (Kingsolver, Barbara), 1998, fiction, 4.11
  // "Powers That Be" (McCaffrey, Anne and Scarborough, Elizabeth Anne), 1966,
  // fiction, 3.93

  printf("\nhere's the list:\n");
  listNode = bookList;
  while (listNode != NULL) {
    printBook((Book *)listNode->data);
    listNode = listNode->next;
  }

  printf("\n");

  rc = findTest("T2a", bookList, &watershipDownBook, &watershipDownBook);
  if (rc != 0)
    ++numfails;

  rc = findTest("T2b", bookList, &powersThatBeBook, &powersThatBeBook);
  if (rc != 0)
    ++numfails;

  rc = findTest("T2c", bookList, &sunAlsoRisesBook, &sunAlsoRisesBook);
  if (rc != 0)
    ++numfails;

  rc = findTest("T2d", bookList, &poisonwoodBibleBook, &poisonwoodBibleBook);
  if (rc != 0)
    ++numfails;

  Book siddharthaBook;
  rc = initializeBook(&siddharthaBook, "Siddhartha", "Hesse, Herman", NULL,
                      1922, GENRE_FICTION, 4.09);
  if (rc != 0) {
    printf("ERROR: initializeBook() failed\n");
    ++numfails;
  }

  rc = findTest("T2e", bookList, &siddharthaBook, NULL);
  if (rc != 0)
    ++numfails;

  // find The Sun Also Rises: it's in position one (list starts at pos zero)
  rc = findNthTest("T2f", bookList, 1, &sunAlsoRisesBook);
  if (rc != 0)
    ++numfails;

  // find the nonexistent 10th item
  rc = findNthTest("T2g", bookList, 10, NULL);
  if (rc != 0)
    ++numfails;

  // remove The Poisonwood Bible: it's in position two (list starts at pos zero)
  rc = removeNthTest("T2h", &bookList, 2, &poisonwoodBibleBook);
  if (rc != 0)
    ++numfails;

  // remove the nonexistent 20th item
  rc = removeNthTest("T2i", &bookList, 20, NULL);
  if (rc != 0)
    ++numfails;

  // remove Watership Downe
  rc = removeTest("T2j", &bookList, (ComparisonFunction)compareByTitle,
                  &watershipDownBook, true);
  if (rc != 0)
    ++numfails;

  // attempt to remove a book that is not in the list
  Book theStrangerBook;
  rc = initializeBook(&theStrangerBook, "The Stranger", "Camus, Albert", NULL,
                      1942, GENRE_FICTION, 4.03);
  if (rc != 0) {
    printf("ERROR: initializeBook() failed\n");
    ++numfails;
  }

  rc = removeTest("T2k", &bookList, (ComparisonFunction)compareByTitle,
                  &theStrangerBook, false);
  if (rc != 0)
    ++numfails;

  // remove the rest of the books
  // "The Sun Also Rises" (Hemingway, Ernest), 1926, fiction, 3.79
  // "The Poisonwood Bible" (Kingsolver, Barbara), 1998, fiction, 4.11

  rc = removeTest("T2l", &bookList, (ComparisonFunction)compareByTitle,
                  &powersThatBeBook, true);
  if (rc != 0)
    ++numfails;

  rc = removeTest("T2m", &bookList, (ComparisonFunction)compareByTitle,
                  &sunAlsoRisesBook, true);
  if (rc != 0)
    ++numfails;

  // add a couple of books
  rc = insertItem(&bookList, &watershipDownBook,
                  (ComparisonFunction)compareByRating);
  if (rc != 0) {
    printf("ERROR: insertItem() failed\n");
    ++numfails;
  }

  rc = insertItem(&bookList, &theStrangerBook,
                  (ComparisonFunction)compareByRating);
  if (rc != 0) {
    printf("ERROR: insertItem() failed\n");
    ++numfails;
  }

  printf("here's the list now:\n");
  printList(bookList, (PrintFunction)printBook);
  printf("\n");

  // find Watership Down: should be in position one
  rc = findNthTest("T2n", bookList, 1, &watershipDownBook);
  if (rc != 0)
    ++numfails;

  // find The Stranger: should be in position zero
  rc = findNthTest("T2o", bookList, 0, &theStrangerBook);
  if (rc != 0)
    ++numfails;

  // summarize
  if (numfails > 0) {
    printf("general tests failed\n");
    return 1;
  } else {
    printf("general tests passed\n");
    return 0;
  }
} // generalTests()

//--------------------------------------------------------------------------

int main() {
  bool fail = false;
  int rc;

  rc = csvTests();
  if (rc != 0)
    fail = true;

  rc = generalTests();
  if (rc != 0)
    fail = true;

  if (!fail)
    printf("SUCCESS: all tests pass\n");
}
