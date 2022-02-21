#include "../lib/operations.h"

void insert_at_start(Node **head, int number) {
  Node *temp = (Node *) malloc(sizeof(Node*));

  temp->number = number;
  temp->next = NULL;

  if (*head != NULL)
    temp->next = *head;
  
  *head = temp;
}

void insert_at(int position, Node **head, int number) {
  if (position == 1)
    return insert_at_start(head, number);
  
  int i = 0;
  Node *new_node = (struct Node*) malloc(sizeof(Node *));
  Node *temp_node = (struct Node*) malloc(sizeof(Node *));
  
  new_node->number = number;
  new_node->next = NULL;

  temp_node = *head;
  for (i = 0; i < (position - 2); ++i)
    temp_node = temp_node->next;

  new_node->next = temp_node->next;
  temp_node->next = new_node;
}

void delete_at(int position, Node **head) {
  int i = 0;
  Node *temp_node = *head;
  
  if (position == 1) {
    *head = temp_node->next;
    free(temp_node);
    return;
  }

  for (i = 0; i < position - 2; ++i)
    temp_node = temp_node->next;

  Node *node_to_delete = temp_node->next;
  temp_node->next = node_to_delete->next;
  free(node_to_delete);
}

int count_list_elements(Node *head) {
  int counter = 0;
  while (head != NULL) {
    ++counter;
    head = head->next;
  }
  return counter;
}

void reverse_list(Node **head) {
  Node *current, *prev, *next;
  current = *head;
  prev = NULL;

  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *head = prev;
}

void reverse_list_with_recursion(Node **head) {
  Node *p = *head;

  if (p->next == NULL) {
    *head = p;
    return;
  }
  reverse_list_with_recursion(&(p->next));
  Node *temp = p->next;
  temp->next = p;
  p->next = NULL;
}

void get_list_nodes_data(Node *head) {
  if (head->next == NULL) return;
  printf(" %i ", head->number);
  get_list_nodes_data(head->next);
}


void get_list_nodes_data_reversed(Node *head) {
  if (head->next == NULL) return;
  get_list_nodes_data_reversed(head->next);
  printf(" %i ", head->number);
}