#include "./structures.h"

stack_t *new_stack(int);
void push(item_t, stack_t*);
void pop(stack_t*);
item_t peek(stack_t*);
void print_stack(stack_t *st);

int main(int argc, char *argv[])
{
	stack_t *st = new_stack(3);
	item_t i1, i2, i3;
	i1.num = 1; i2.num = 2; i3.num = 3;
	i1.name = "Jeremy"; i2.name = "Alexander"; i3.name = "Carlos";
	push(i1, st);
	push(i2, st);
	push(i3, st);
	printf("\n\tLast item in stack: (num:) %i (name:) %s\n", peek(st).num, peek(st).name);
	print_stack(st);
	return 0;
}

stack_t *new_stack(int capacity)
{
	stack_t *st = (stack_t*) malloc(sizeof(stack_t));
	st->array = (item_t*) malloc(sizeof(item_t[capacity]));
	st->capacity = capacity;
	st->top = st->array;
}

void push(item_t datum, stack_t *st)
{
	*(st->top) = datum;
	st->top += 1;
}

void pop(stack_t *st)
{
	st->top -= 1;
}

item_t peek(stack_t *st)
{
	return *(st->top - 1);
}

void print_stack(stack_t *st)
{
	int i;
	int items_number = *(&st->array + 1) - st->array;
	for (i = items_number; i >= 1; --i)
	{
		printf("\t%i - %s\n", *(st->top - i), *(st->top - i));
	}
}