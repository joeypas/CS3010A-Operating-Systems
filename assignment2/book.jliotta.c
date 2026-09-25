#include "book.jliotta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int initializeBook(Book *book, char *title, char *author, char *author2,
                   int year, BookGenre genre, float rating) {
  // Bail out if any of these are NULL
  if (book == NULL || title == NULL || author == NULL)
    return 1;

  // Do all of the checks before setting any values
  int title_len = strlen(title);
  int author_len = (int)strlen(author);
  int title_ok = title_len > 0 && title_len <= MAX_BOOK_NAME_LEN;
  int author_ok = author_len > 0 && author_len <= MAX_AUTHOR_NAME_LEN;
  int year_ok = year >= 1600;
  int rating_ok = rating >= 0.0 && rating <= 5.0;

  if (!(title_ok && author_ok && year_ok && rating_ok))
    return 1;

  // Initialize the struct since all checks passed
  strcpy(book->title, title);
  strcpy(book->author, author);
  book->year = year;
  book->rating = rating;
  book->genre = genre;

  // Handle author2 case
  if (author2 != NULL) {
    int author2_len = strlen(author2);
    if (!(author2_len > 0 && author2_len <= MAX_AUTHOR_NAME_LEN))
      return 1;
    else
      strcpy(book->author2, author2);
  } else {
    strcpy(book->author2, "");
  }

  return 0;
}

int compareStr(char *str1, char *str2) {
  int res = strcmp(str1, str2);

  if (res > 0)
    return 1;
  else if (res < 0)
    return -1;
  else
    return 0;
}

int compareByTitle(Book *b1, Book *b2, int *result) {
  if (b1 == NULL || b2 == NULL || result == NULL)
    return 1;

  *result = compareStr(b1->title, b2->title);

  return 0;
}

int compareByAuthor(Book *b1, Book *b2, int *result) {
  if (b1 == NULL || b2 == NULL || result == NULL)
    return 1;

  *result = compareStr(b1->author, b2->author);

  return 0;
}

int compareByYear(Book *b1, Book *b2, int *result) {
  if (b1 == NULL || b2 == NULL || result == NULL)
    return 1;

  if (b1->year < b2->year)
    *result = -1;
  else if (b1->year > b2->year)
    *result = 1;
  else
    *result = 0;
  return 0;
}

int compareByGenre(Book *b1, Book *b2, int *result) {
  if (b1 == NULL || b2 == NULL || result == NULL)
    return 1;

  if (b1->genre == b2->genre)
    *result = 0;
  else
    *result = 1;

  return 0;
}

int compareByRating(Book *b1, Book *b2, int *result) {
  if (b1 == NULL || b2 == NULL || result == NULL)
    return 1;

  if (b1->rating < b2->rating)
    *result = -1;
  else if (b1->rating > b2->rating)
    *result = 1;
  else
    *result = 0;
  return 0;
}

int numAuthors(Book *book, int *result) {
  if (book == NULL || result == NULL)
    return 1;

  *result = 1;

  if (strlen(book->author2) > 0)
    *result = 2;

  return 0;
}

void printBook(void *b) {
  if (b == NULL)
    return;

  Book *book = (Book *)b;
  char *genre;
  switch (book->genre) {
  case GENRE_FICTION:
    genre = "fiction";
    break;
  case GENRE_NONFICTION:
    genre = "nonfiction";
    break;
  default:
    genre = "self-help";
    break;
  }

  printf("\"%s\" (", book->title);

  if (strlen(book->author2) > 0)
    printf("%s and %s", book->author, book->author2);
  else
    printf("%s", book->author);

  printf("), %d, %s, %.2f\n", book->year, genre, book->rating);
}

char *skipFirst(char *title) {
  int title_len = strlen(title);
  if (title_len >= 4 && title[0] == 'T' && title[1] == 'h' && title[2] == 'e' &&
      title[3] == ' ')
    return title + 4;

  if (title_len >= 2 && title[0] == 'A' && title[1] == ' ')
    return title + 2;

  return title;
}

int compareByTitleDeluxe(Book *b1, Book *b2, int *result) {
  if (b1 == NULL || b2 == NULL || result == NULL)
    return 1;

  char *title1 = skipFirst(b1->title);

  char *title2 = skipFirst(b2->title);

  *result = compareStr(title1, title2);
  return 0;
}

int initializeBookFromStrings(Book *book, char **stringArray) {
  if (stringArray == NULL || book == NULL)
    return 1;

  char *title = stringArray[0];
  char *author = stringArray[1];
  char *author2 = stringArray[2];
  if (strcmp(author2, "") == 0)
    author2 = NULL;

  int year = atoi(stringArray[3]);

  BookGenre genre;

  if (strcmp(stringArray[4], "FICTION") == 0)
    genre = GENRE_FICTION;
  else if (strcmp(stringArray[4], "NONFICTION") == 0)
    genre = GENRE_NONFICTION;
  else if (strcmp(stringArray[4], "SELF_HELP") == 0)
    genre = GENRE_SELF_HELP;
  else
    return 1;

  float rating = atof(stringArray[5]);

  return initializeBook(book, title, author, author2, (int)year, genre, rating);
}
