#include <stdio.h>
#define SIZE 3

int Q[SIZE];

int front = -1;
int rear = -1;

int empty();
int enqueue(int);
int full();
int dequeue();
int peek();

int main(int argc, char *argv[])
{
	enqueue(1);
	enqueue(2);
	enqueue(3);
	//enqueue(4);
	dequeue();
	dequeue();
	enqueue(-1);
	enqueue(-2);
	dequeue();
	
	printf("TOP: %i\n", peek());
	printf("EMPTY: %i\n", empty());
	printf("FULL: %i\n", full());
	
	return 0;
}

int empty()
{
	return front == -1 && rear == -1 ? 1 : 0;
}

int full()
{
	/*return rear == SIZE - 1 ? 1 : 0;*/
	return (rear + 1) % SIZE == front ? 1 : 0;
}

int enqueue(int x)
{
	if (full())
		return 0;
	else if (empty())
		front = rear = 0;
	else
		rear = (rear + 1) % SIZE;
	Q[rear] = x;
	return 1;
}

int dequeue()
{
	if (empty())
		return 0;
	else if (front == rear)
		front = rear = -1;
	else
		front = (front + 1) % SIZE;
	return 1;
}

int peek()
{
	return Q[front];
}