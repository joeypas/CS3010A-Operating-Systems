#define MAX_BOOK_NAME_LEN 63
#define MAX_AUTHOR_NAME_LEN 63

typedef enum { GENRE_FICTION, GENRE_NONFICTION, GENRE_SELF_HELP } BookGenre;

typedef struct {
  char title[MAX_BOOK_NAME_LEN + 1];
  char author[MAX_AUTHOR_NAME_LEN + 1];
  char author2[MAX_AUTHOR_NAME_LEN + 1];
  int year;
  BookGenre genre;
  float rating;
} Book;

int initializeBook(Book *book, char *title, char *author, char *author2,
                   int year, BookGenre genre, float rating);
int compareByTitle(Book *b1, Book *b2, int *result);
int compareByAuthor(Book *b1, Book *b2, int *result);
int compareByYear(Book *b1, Book *b2, int *result);
int compareByGenre(Book *b1, Book *b2, int *result);
int compareByRating(Book *b1, Book *b2, int *result);
int numAuthors(Book *book, int *result);
void printBook(void *b);
int initializeBookFromStrings(Book *book, char **stringArray);
