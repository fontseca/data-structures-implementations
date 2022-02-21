#ifndef __OPERATIONS_H__
#define __OPERATIONS_H__
#include <stdlib.h>
#include <stdio.h>
#include "./structures.h"

void insert_at_start(Node **, int);
void insert_at(int, Node **, int);
void delete_at(int, Node **);
void reverse_list(Node **);
void reverse_list_with_recursion(Node **);
void get_list_nodes_data(Node *);
void get_list_nodes_data_reversed(Node *);
int count_list_elements(Node *);

#endif