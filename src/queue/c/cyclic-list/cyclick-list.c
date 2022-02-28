#include <stdio.h>
#include <stdlib.h>

typedef struct qu_t
{
  int x;
  struct qu_t *next;
} queue_t;

queue_t *create_queue(void);
void enqueue(const int, queue_t*);
int dequeue(queue_t*);
int peek(const queue_t*);
int queue_empty(const queue_t*);
void destroy_queue(queue_t*);

void main()
{
  queue_t *qu = create_queue();
  enqueue(1, qu);
  enqueue(2, qu);
  dequeue(qu);
  /* dequeue(qu); */
  printf("Removed: %i\n", dequeue(qu));
  dequeue(qu);
  printf("Is empty: %s\n", queue_empty(qu) ? "true" : "false"); /* true */
  printf("Top: %i\n", peek(qu));
  return;
}

queue_t *create_queue(void)
{
  queue_t *entrypoint, *placeholder;
  entrypoint = (queue_t*) malloc(sizeof(queue_t));
  placeholder = (queue_t*) malloc(sizeof(queue_t));
  /* entrypoint->next will have a reference to the rear node */
  entrypoint->next/*<rear>*/= placeholder;
  /* placeholder->next will have a reference to the front node */
  placeholder->next/*<top>*/= placeholder;
  return entrypoint;
}

void enqueue(const int x, queue_t *qu)
{
  queue_t *new, *tmp;
  new = (queue_t*) malloc(sizeof(queue_t));
  new->x = x;
  tmp = qu->next/*<rear>*/;
  qu->next = new;
  new->next = tmp->next/*<placeholder>*/;
  tmp->next = new;
}

int dequeue(queue_t *qu)
{
  if (queue_empty(qu))
    return 0 * printf("queue is empty, cannot dequeu\n") - 1;
  queue_t *placeholder = qu->next->next;
  queue_t *top = placeholder->next;
  int x_tmp;
  placeholder->next = top->next;
  if (top->next == placeholder)
    qu->next = placeholder;
  x_tmp = top->x;
  free(top);
  return x_tmp;
}

int peek(const queue_t *qu)
{
  if (queue_empty(qu))
    return 0 * printf("queue is empty, cannot peek\n") - 1;
  return qu->next->next->next->x;
}

int queue_empty(const queue_t *qu)
{
  return qu->next == qu->next->next;
}

void destroy_queue(queue_t *qu)
{
  queue_t *tmp;
  tmp = qu->next->next/*<placeholder>*/;
  while (tmp != qu->next/*<rear>*/)
  {
    qu->next->next/*<placeholder>*/= tmp->next/*<top>*/;
    free(tmp);
    tmp = qu->next->next/*<placeholder>*/;
  }
  free(qu->next/*<rear>*/);
  free(qu);
}