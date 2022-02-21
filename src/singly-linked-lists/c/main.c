#include "./lib/menu.h"

void main() {
  Node *head = NULL;
  int opt;
  puts("\n SINGLY LINKED LIST\n");
  for (;;) {
    menu(&opt);
    
    switch (opt) {
      case 0:
        puts(" bye : )");
        exit(EXIT_SUCCESS);
      case 1:
        create_list_menu(&head);
        break;
      case 2:
        print_list_menu(head);
        break;
      case 3:
        insert_element_menu(&head);
        break;
      case 4:
        delete_node_menu(&head);
        break;
      case 5:
        reverse_list_menu(&head);
        break;
      default:
        break;
    }
  }
}