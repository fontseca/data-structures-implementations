/**
 * @file reverse_string.c
 * @author Jeremy Fonseca
 * @brief Reverse a string using a stack
 * @version 0.1
 * @date 2022-02-24
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
  char *base;
  char *top;
  int capacity;
} stack;

stack *create_stack(int);
void push(char*, stack*);
char pop(stack*);
char peek(stack*);
void display_stack(stack*);
int empty(stack*);
void destroy_stack(stack *);

int main()
{
  char str[100], reversed[100];
  int len = 0;

  printf("\n\tREVERSE STRING USING A STACK");
  printf("\n\n\tInput: ");
  scanf("%[^\n]s", &str);
  printf("\tCreating stack...");
  len = strlen(str);
  stack *st = create_stack(len);
  int i;
  printf("\n\tPushing onto stack...");
  for (i = 0; i < len; ++i)
    push(str + i, st);
  printf("\n\tCurrent stack:\n");
  display_stack(st);
  printf("\tPoping and peeking...\n");
  for (i = 0; i < len; ++i)
  {
    *(reversed + i) = peek(st);
    pop(st);
  }
  printf("\tDestroying stack...\n");
  destroy_stack(st);
  printf("\tOutput: %s\n", reversed);
}

stack *create_stack(int capacity)
{
  stack *st = (stack *) malloc(sizeof(stack));
  st->capacity = capacity;
  st->base = (char *) malloc(sizeof(char[capacity]));
  st->top = st->base;
  return st;
}

void push(char *c, stack *st)
{
  if (st->top >= st->base + st->capacity)
  {
    printf("\n\tError: stack overflow: cannot insert '%c'\n", *c);
    return;
  }
  *(st->top) = *c;
  st->top++;
}

char pop(stack *st)
{
  if (empty(st))
  {
    printf("\n\tError: stack underflow\n");
    return 0;
  }
  return *(--st->top);
}

char peek(stack *st)
{
  if (empty(st))
  {
    printf("\n\tError: Stack underflow\n");
    return 0;
  }
  return *(st->top - 1);
}

int empty(stack *st)
{
  return st->base == st->top;
}

void display_stack(stack *st)
{
  int i;
  int elements = *(&st->base + 1) - st->base;
  for (i = 1; i <= elements; ++i)
		printf("\t||  %-2c ||\n", *(st->top - i));
}

void destroy_stack(stack *st)
{
  free(st->base);
  free(st);
}