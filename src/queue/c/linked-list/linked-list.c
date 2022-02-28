#include <stdio.h>
#include <stdlib.h>

typedef struct qu_node_t
{
  int data;
  struct qu_node_t *next;
} qu_node_t;

typedef struct queue_t
{
  qu_node_t *front;
  qu_node_t *rear;
} queue_t;

queue_t *create_queue();
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
  enqueue(3, qu);
  // enqueue(4, qu);
  dequeue(qu);
  dequeue(qu);
  // enqueue(20, qu);
  printf("QUEUE FRONT: %i\n", peek(qu));
  return;
}

queue_t *create_queue()
{
  queue_t *new = (queue_t*) malloc(sizeof(queue_t));
  new->front = new->rear= NULL;
  return new;
}

void enqueue(const int data, queue_t *qu)
{
  qu_node_t *new = (qu_node_t*) malloc(sizeof(qu_node_t));
  new->data = data;
  new->next = NULL;
  if (qu->rear != NULL)
  {
    qu->rear->next = new;
    qu->rear = new;
  } else
    qu->rear = qu->front = new;
}

int dequeue(queue_t *qu)
{
  if (queue_empty(qu))
    return 0 * printf("queue is empty, cannot dequeue\n") - 1;
  qu_node_t *tmp = qu->front;
  int data;
  data = tmp->data;
  qu->front = tmp->next;
  if (qu->front == NULL)
    qu->rear = NULL;
  free(tmp);
  return data;
}

int queue_empty(const queue_t *qu)
{
  return qu->front == NULL;
}

int peek(const queue_t *qu)
{
  if (queue_empty(qu))
    return 0 * printf("queue is empty, cannot peek\n") - 1;
  return qu->front->data;
}

void destroy_queue(queue_t *qu)
{
  qu_node_t *tmp_node = qu->front;
  while (qu->front != NULL)
  {
    tmp_node = qu->front;
    qu->front = tmp_node->next;
    free(tmp_node);
  }
  free(qu);
}