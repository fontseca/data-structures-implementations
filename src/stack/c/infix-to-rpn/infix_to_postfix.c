/**
 * @file infix_to_postfix.c
 * @author Jeremy Fonseca (github.com/fontseca)
 * @brief Convert an expression from Infix Notation to Reverse Polish Notation (RPN) using a stacks
 * @date 2022-02-25 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* structures */
typedef struct st_t
{
  char c;
  struct st_t *next;
} stack;

/* declaration */
char *infix_to_postfix(char*);
char *to_string(stack*);
int is_operand(char);
int is_operator(char);
int is_opening_parenthesis(char);
int is_closing_parenthesis(char);
int has_higher_precedence(char, char);
int is_valid_character(const char);
int is_balanced(const char *);
int match(const char, const char);
/* stack declarations */
stack *create_stack();
void push(char, stack*);
char pop(stack*);
char peek(stack*);
int empty(stack*);
void destroy_stack(stack*);
void display_stack(stack*);

/* definitions */
int main()
{
  char exp[100]; 
  printf("\n\n\tCONVERT INFIX NOTATION TO REVERSE POLISH NOTATION:");
  printf("\n\t(Note: only numbers of one digit and integers are allowed)");
  printf("\n\n\t[INFIX]\t\t<< ");
  scanf("%[^\n]s", exp);
  if (!is_balanced(exp))
  {
    printf("\n\terror: expected paretheses are missing\n");
    return 0;
  }
  printf("\n\t[POSTFIX]\t>> %s\n\n", infix_to_postfix(exp));
  return 0;
}

char *infix_to_postfix(char *exp)
{
  stack *st = create_stack();
  stack *RPN = create_stack();
  int i;
  char *res;
  for (i = 0; i < strlen(exp); ++i)
  {
    if (!is_valid_character(exp[i]))
    {
      printf("\n\terror: character `%c' is not allowed\n", exp[i]);
      destroy_stack(st);
      return "";
    }
    if (is_operand(exp[i]))
      push(exp[i], RPN);
    else if (is_operator(exp[i]))
    {
      while (!empty(st) && !is_opening_parenthesis(peek(st)) && has_higher_precedence(peek(st), exp[i]))
        push(pop(st), RPN);
      push(exp[i], st);
    }
    else if (is_opening_parenthesis(exp[i]))
      push(exp[i], st);
    else if (is_closing_parenthesis(exp[i]))
    {
      while (!empty(st) && !is_opening_parenthesis(peek(st)))
        push(pop(st), RPN);
      pop(st);
    }
  }
  while (!empty(st))
    push(pop(st), RPN);
  destroy_stack(st);
  return to_string(RPN);
}

int is_balanced(const char *str)
{
  int i;
  stack *st = create_stack();
  for (i = 0; i <= strlen(str); ++i)
  {
    if (is_opening_parenthesis(str[i]))
      push(str[i], st);
    else if (is_closing_parenthesis(str[i]))
    {
      if (!empty(st) || match(peek(st), str[i]))
        pop(st);
      else
      {
        destroy_stack(st);
        return 0;
      }
    }
    else
      continue;
  }
  return empty(st) ? 1 : 0;
}

int match(const char c1, const char c2)
{
  return (c1 == 40 && c2 == 41) || (c1 == 91 && c2 == 93) || (c1 == 123 && c2 == 125) ? 1 : 0;
}

int is_valid_character(const char c)
{
  return is_operand(c) || is_operator(c) || is_opening_parenthesis(c) || is_closing_parenthesis(c) || c == ' ';
}

int has_higher_precedence(char op1, char op2)
{
  switch (op1)
  {
    case '^': return op2 == '^' ? 0 : 1;
    case '+': case '-':
      if (op2 == '*' || op2 == '/') return 0;
      else break;
    case '*': case '/':
      if (op2 == '+' || op2 == '-') return 1;
      else break;
    default: return 0;
  }
  return 0;
}

int is_closing_parenthesis(char c)
{
  return (c == ')' || c == '}' || c == ']') ? 1 : 0;
}

int is_opening_parenthesis(char c)
{
  return (c == '(' || c == '{' || c == '[') ? 1 : 0;
}

int is_operator(char c)
{
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^') ? 1 : 0;
}

int is_operand(char c)
{
  if (c >= 65 && c <= 90)         /* uppercase letter */
    return 1;
  else if (c >= 97 && c <= 122)   /* lowercase letter */
    return 1;
  else if (c >= 48 && c <= 57)    /* number */
    return 1;
  else
    return 0;
}

char *to_string(stack *st)
{
  stack *tmp = st->next;
  char *res;
  int i = 0;
  while (tmp != NULL)
  {
    res[i++] = tmp->c;
    tmp = tmp->next;
  }
  stack *tmp_stack = create_stack(); /*stack to invert string*/
  int length = strlen(res);
  char tmp_char, *reversed = (char*) malloc(sizeof(char[length]));
  /*invert string*/
  for (i = 0; i < length; ++i)
    push(res[i], tmp_stack);
  for (i = 0; i < length; ++i)
  {
    tmp_char = pop(tmp_stack);
    *(reversed + i) = tmp_char;
  }
  destroy_stack(tmp_stack);
  return reversed;
}

/* stack definitions */
stack *create_stack()
{
  stack *st = (stack*) malloc(sizeof(stack));
  st->next = NULL;
  return st;
}

void push(char c, stack *st)
{
  stack *new = (stack*) malloc(sizeof(stack));
  new->c = c;
  new->next = st->next;
  st->next = new;
}

char pop(stack *st)
{
  stack *tmp = st->next;
  char c  = tmp->c;
  st->next = tmp->next;
  free(tmp);
  return c;
}

char peek(stack *st)
{
  return st->next->c;
}

int empty(stack *st)
{
  return st->next == NULL;
}

void destroy_stack(stack *st)
{
  stack *tmp;
  do
  {
    tmp = st->next;
    free(tmp);
  } while (tmp != NULL);
  free(st);
}

void display_stack(stack *st)
{
  stack *tmp = st->next;
  if (tmp == NULL)
    return;
  display_stack(tmp);
  printf("%c", tmp->c);
}