#ifndef __STRUCTURES_H__
#define __STRUCTURES_H__
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int num;
  char *name;
} item_t;

typedef struct stack_t
{
  int capacity;
  item_t *array;
  item_t *top;
} stack_t;

#endif