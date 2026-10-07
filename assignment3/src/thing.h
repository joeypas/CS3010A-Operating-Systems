#define MAX_NAME_LENGTH 63

typedef struct {
  int weight;
  char name[1 + MAX_NAME_LENGTH];
} Thing;

void printThing(void *data);
Thing *createThing(char *name, int weight);
