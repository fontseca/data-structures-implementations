#include "../lib/menu.h"

void menu(int *option) {
  puts(" 1. Create a list");
  puts(" 2. Display list");
  puts(" 3. Insert node");
  puts(" 4. Delete node");
  puts(" 5. Reverse list");
  puts(" 0. Exit");

  fflush(stdin);
  printf("\n Select an option: ");
  scanf("%i", &(*option));
}

void print_list_menu(Node *head) {
  system("clear");
  printf(" Printing list:\n");
  printf(" (List has %i nodes)\n\n", count_list_elements(head));
  get_list_nodes_data(head);
  printf("\n\n");
}

void insert_element_menu(Node **head) {
  int elem, pos, nodes, invalid_position;
  nodes = count_list_elements(*head);

  do {
  printf(" Insert at position: ");
  scanf("%i", &pos);
  
  invalid_position = pos > nodes || pos < 1;

  if (invalid_position)
    printf(" Position %i is not valid\n", pos);
  } while (invalid_position);

  printf(" Node datum: ");
  scanf("%i", &elem);

  insert_at(pos, head, elem);
  print_list_menu(*head);
}

void create_list_menu(Node **head) {
  system("clear");
  unsigned int number_of_nodes = 0;
  short int i = 0;
  int node_data;

  printf(" Number of nodes: ");
  scanf("%i", &number_of_nodes);

  printf(" (Data type of nodes: integer)\n\n");
  
  for (i = 0; i < number_of_nodes; ++i) {
    printf(" Node #%i: ", i + 1);
    scanf("%i", &node_data);
    insert_at_start(&(*head), node_data);
  }
  
  print_list_menu(*head);
}

void delete_node_menu(Node **head) {
  int pos, nodes, invalid_position;
  nodes = count_list_elements(*head);

  do {
  printf(" Delete node at position: ");
  scanf("%i", &pos);
  
  invalid_position = pos > nodes || pos < 1;

  if (invalid_position)
    printf(" Position %i is not valid\n", pos);
  } while (invalid_position);

  delete_at(pos, head);
  print_list_menu(*head);
}

void reverse_list_menu(Node **head) {
  printf(" Reversing this list...\n\n");
  reverse_list(head);
  print_list_menu(*head);
}