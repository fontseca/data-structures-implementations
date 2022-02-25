#include <stdio.h>
#include <stdlib.h>

typedef struct itm_t
{
  int n;
} item_t;

typedef struct st_t
{
  item_t item;
  struct st_t *next;
} stack_t;

stack_t *create_stack(void);
int stack_empty(stack_t*);
void push(item_t, stack_t*);
item_t pop(stack_t*);
item_t peek(stack_t *);
void remove_stack(stack_t*);

void main()
{
  stack_t *st = create_stack();
  item_t itm;

  itm.n = 1;
  push(itm, st);
  itm.n = 2;
  push(itm, st);
  itm.n = 3;
  push(itm, st);
  itm.n = 4;
  push(itm, st);
  itm.n = 5;
  push(itm, st);

  printf("Top: %i\n", peek(st)); // 5
  return;
}

stack_t *create_stack(void)
{
  stack_t *st;
  st = (stack_t*) malloc(sizeof(stack_t));
  st->item.n = 18;
  st->next = NULL;
  return st;
}

int stack_empty(stack_t *st)
{
  return (st->next == NULL);
}

void push(item_t x, stack_t *st)
{
  stack_t *tmp;
  tmp = (stack_t*) malloc(sizeof(stack_t));
  tmp->item = x;
  tmp->next = st->next;
  st->next = tmp;
}

item_t pop(stack_t *st)
{
  stack_t *tmp = st->next;  
  item_t tmp_item;
  st->next = tmp->next;
  tmp_item = tmp->item;
  free(tmp);
  return tmp_item;
}

item_t peek(stack_t *st)
{
  return st->next->item;
}

void remove_stack(stack_t *st)
{
  stack_t *tmp;
  do
  {
    tmp = st->next;
    free(tmp);
  } while (tmp != NULL);
}