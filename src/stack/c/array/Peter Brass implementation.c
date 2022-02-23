#include <stdio.h>
#include <stdlib.h>

typedef struct item_t
{	int num;
} item_t;

typedef struct stack_t
{	item_t *base;
	item_t *top;
	int size;
} stack_t;

stack_t *create_stack(int);
int push(item_t, stack_t*);
int stack_empty(stack_t*);
item_t pop(stack_t*);
item_t peek(stack_t*);
void remove_stack(stack_t *);
void display_stack(stack_t*);

int main()
{	stack_t *st = create_stack(8);
	item_t i1, i2, i3, i4, i5, i6, i7;
	
	i1.num = 1;
	i2.num = 25;
	i3.num = 3;
	i4.num = 4;
	i5.num = 5;
	i6.num = 6;
	i7.num = 10;
	
	push(i1, st);
	push(i2, st);
	push(i3, st);
	push(i4, st);
	push(i5, st);
	push(i6, st);
	push(i7, st);
	i7.num = 18;
	push(i7, st);
	
	display_stack(st);
	return 0;
}

stack_t *create_stack(int size)
{	stack_t *st;
	st = (stack_t*) malloc(sizeof(stack_t));
	st->base = (item_t*) malloc(sizeof(item_t[size]));
	st->size = size;
	st->top = st->base;
	return st;
}

int push(item_t x, stack_t *st)
{	if (st->top < st->base + st->size)
	{	*(st->top) = x;
		st->top += 1;
		return 0;
	}
	/* stack overflow */
	else
		return -1;
}

item_t peek(stack_t *st)
{	return *(st->top -1);
}

item_t pop(stack_t *st)
{	st->top -= 1;
	return *(st->top);
}

int stack_empty(stack_t *st)
{	return st->base == st->top;
}

void remove_stack(stack_t *st)
{	free(st->base);
	free(st);
}

void display_stack(stack_t *st)
{	int i;
	putchar(10);
	printf("\t||  %-2i || <-- DO YOU WANT TO PEEK IT?\n", *(st->top - 1));
	for (i = 2; i <= st->size; ++i)
		printf("\t||  %-2i ||\n", *(st->top - i));
	printf("\t_________\n");
}











