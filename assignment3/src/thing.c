#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "thing.h"

Thing *createThing(char *name, int weight) {
  Thing *thing;
  if (name == NULL)
    return NULL;
  if (strlen(name) == 0 || strlen(name) > MAX_NAME_LENGTH)
    return NULL;
  thing = (Thing *) malloc(sizeof(Thing));
  strcpy(thing->name, name);
  thing->weight = weight;
  return thing;
}

//----------------------------------------------------------------------
  
void printThing(void *data) {
  Thing *thing; 
  thing = (Thing *) data;
  printf("\"%s\" (%u lbs)\n", thing->name, thing->weight);
} 
