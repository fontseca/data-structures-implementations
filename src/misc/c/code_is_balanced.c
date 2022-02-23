/* Jeremy Fonseca | Feb 27, 2022
 * Use a Stack to determine if a given code
 * is balanced. That is, each opening parenthesis
 * has an ending parenthesis. Compilers use this
 * method to find missing parentheses.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  int capacity;
  char *mem;
  char *top;
} stack;

stack *create_stack(int);
void pop(stack*);
void push(char, stack*);
int is_emtpy(stack*);
char peek(stack*);
int balanced(char*);
int match(char, char);
void remove_stack(stack*);

int main()
{
  char *exp = "\n\t{\n\t\tvoid say_hello_world()\n\t\t{\n\t\t\tprintf(\"Hello, world\");\n\t\t\tsay_hello_world();\n\t\t}\n\t}";
  printf("\n\tCODE:\t%s\n", exp);
  printf("\n\tSTATUS:\t\t%s\n", balanced(exp) ? "'BALANCED'" : "'NOT BALANCED'");
  exp = "\n\t{\n\t\tvoid say_hello_world()\n\t\t{\n\t\t\tprintf(\"Hello, world\");\n\t\t\tsay_hello_world);\n\t\t}\n\t}";
  printf("\n\tCODE:\t%s\n", exp);
  printf("\n\tSTATUS:\t\t%s\n", balanced(exp) ? "'BALANCED'" : "'NOT BALANCED'");
  return 0;
}

int match(char c1, char c2)
{
  return (c1 == 40 && c2 == 41) || (c1 == 91 && c2 == 93) || (c1 == 123 && c2 == 125) ? 1 : 0;
}

int balanced(char *str)
{
  int n = strlen(str), i, empty;
  stack *st = create_stack(n);
  for (i = 0; i <= n; ++i)
    if (*(str + i) == 40 || *(str + i) == 91 || *(str + i) == 123)
      push(*(str + i), st);
    else if (*(str + i) == 41 || *(str + i) == 93 || *(str + i) == 125)
    {
      if (is_emtpy(st) || !match(peek(st), *(str + i)))
        return 0;
      else
        pop(st);
    }
    else
      continue;
  empty = is_emtpy(st);
  remove_stack(st);
  return empty ? 1 : 0;
}

stack *create_stack(int capacity)
{
  stack *st = (stack*) malloc(sizeof(stack));
  st->capacity = capacity;
  st->mem = (char*) malloc(sizeof(char[capacity]));
  st->top = st->mem;
  return st;
}

void push(char c, stack *st)
{
  *(st->top) = c;
  st->top++;
}

void pop(stack *st)
{
  st->top -= 1;
}

char peek(stack *st)
{
  return *(st->top - 1);
}

int is_emtpy(stack *st)
{
  return st->top == st->mem;
}

void remove_stack(stack *st)
{
  free(st->mem);
  free(st);
}
