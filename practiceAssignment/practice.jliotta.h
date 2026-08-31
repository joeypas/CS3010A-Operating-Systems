#define MAX_NAME_LEN 63
typedef struct {
  char title[1+MAX_NAME_LEN];
  char author[1+MAX_NAME_LEN];
  int numPages;
} Book;

int compare(int val1, int val2);
int compare_p(int *val1, int *val2);
int countChar(char ch, char *str);
char *buildString(char *str1, char *str2);
int allocInt(int value, int **newValue);
int initializeBook(char *title, char *author, int numPages, Book **newBook);
