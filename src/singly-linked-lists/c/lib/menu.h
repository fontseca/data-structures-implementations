#ifndef __MENU_H__
#define __MENU_H__
#include <stdlib.h>
#include <stdio.h>
#include "./structures.h"
#include "./operations.h"

void menu(int *);
void print_list_menu(Node *);
void create_list_menu(Node **);
void insert_element_menu(Node **);
void delete_node_menu(Node **);
void reverse_list_menu(Node **);

#endif