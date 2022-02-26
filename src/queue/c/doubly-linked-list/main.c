#include <stdio.h>
#include <stdlib.h>

typedef struct qu_t
{
  int x;
  struct qu_t *next;
  struct qu_t *prev;
} queue_t;

queue_t *create_queue();
int queue_empty(const queue_t*);
void enqueue(const int, queue_t*);
int dequeue(queue_t*);
int peek(const queue_t*);
void destroy_queue(queue_t*);

int main()
{
  queue_t *qu = create_queue();

  enqueue(1, qu);
  enqueue(2, qu);
  enqueue(3, qu);
  enqueue(4, qu);
  enqueue(5, qu);
  enqueue(6, qu);

  printf("Top: %i\n", peek(qu));

  return 0;
}

queue_t *create_queue()
{
  queue_t *entrypoint;
  entrypoint = (queue_t*) malloc(sizeof(queue_t));
  entrypoint->next = entrypoint;
  entrypoint->prev = entrypoint;
  return entrypoint;
}

void enqueue(const int x, queue_t *qu)
{
  queue_t *new;
  new = (queue_t*) malloc(sizeof(queue_t));
  new->x = x;
  new->next = qu->next;
  qu->next = new;
  new->next->prev = new;
  new->prev = qu;
}

int dequeue(queue_t *qu)
{
  queue_t *tmp;
  int x_tmp;
  tmp = qu->prev;
  x_tmp = tmp->x;
  tmp->prev->next = qu;
  qu->prev = tmp->prev;
  free(tmp);
  return x_tmp;
}

int peek(const queue_t *qu)
{
  return qu->prev->x;
}

void destroy_queue(queue_t *qu)
{
  queue_t *tmp;
  // tmp = qu->next->next;
  qu->prev->next = NULL;
  do
  {
    tmp = qu->next;
    free(tmp);
    qu = tmp;
  } while (qu != NULL);
}

int queue_empty(const queue_t *qu)
{
  return qu->next == qu;
}