#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int *base;
  int front;
  int rear;
  int capacity;
} queue_t;

queue_t *create_queue(const int);
int queue_empty(const queue_t*);
int enqueue(const int, queue_t*);
int dequeue(queue_t*);
int peek(const queue_t*);
void destroy_queue(queue_t*);

int main()
{
  queue_t *qu = create_queue(7);

  enqueue(1, qu);
  dequeue(qu);
  // enqueue(2, qu);
  // enqueue(3, qu);
  // enqueue(4, qu);
  // enqueue(5, qu);
  // enqueue(6, qu);
  // enqueue(7, qu);

  // dequeue(qu);
  // dequeue(qu);
  // dequeue(qu);
  // dequeue(qu);
  // dequeue(qu);

  printf("qu->front: %i\n", qu->front);
  printf("qu->rear: %i\n", qu->rear);

  printf("Is empty: %i\n", queue_empty(qu));

  return 0;
}

queue_t *create_queue(const int capacity)
{
  queue_t *qu;
  qu = (queue_t*) malloc(sizeof(queue_t));
  qu->base = (int *) malloc(sizeof(int[capacity]));
  qu->capacity = capacity;
  qu->front = -1;
  qu->rear = -1;
  return qu;
}

int enqueue(const int x, queue_t* qu)
{
  if ((qu->rear + 1) % qu->capacity == qu->front) /* queue is full */
    return printf("Queue is full, cannot push '%i'\n", x);

  if (!~qu->front) /* first element */
    qu->front = qu->rear = 0;

  qu->rear = (qu->rear + 1) % qu->capacity;
  qu->base[qu->rear] = x;
}

int dequeue(queue_t *qu)
{  
  int tmp;
  if (queue_empty(qu))
    return -1;
  if (qu->front == qu->rear)
    qu->front = qu->rear = -1;
  qu->front = ((qu->front + 1) % qu->capacity);
  tmp = qu->front;
  return qu->base[tmp];
}

int peek(const queue_t *qu)
{
  return qu->base[qu->front];
}

void destroy_queue(queue_t *qu)
{
  free(qu->base);
  free(qu);
}

int queue_empty(const queue_t *qu)
{
  // return qu->front == qu->rear;
  return qu->front == -1 && qu->rear == -1;
}