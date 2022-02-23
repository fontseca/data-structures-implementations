/* Jeremy Fonseca | Feb 23, 2022
 * Doubly Linked List implementation.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int num;
	struct node *prev;
	struct node *next;
} node;

typedef struct list
{
	char *list_name;
	node *head;
	int size;
} list;

node *get_node(int);
void insert_at_start(int, list*);
node *node_at(int, list*);
void insert_at_end(int, list*);
void insert_at(int, int, list*);
void modify_at(int, int, list*);
void delete_at(int, list*);
list *create_list(char*);
void display_forward(list*);
void display_backward(list*);
void delete_list(list*);

int main()
{
	puts("\n\n\tDOUBLY LINKED LIST BY JEREMY FONSECA\n");
	list *l = create_list("Years");
	
	printf("\n\t(Create && insert)");
	
	insert_at_end(2018, l);
	insert_at_end(2019, l);
	insert_at_end(2020, l);
	insert_at_end(2021, l);
	insert_at_end(2022, l);
	insert_at_end(2023, l);
	
	display_forward(l);
	
	printf("\n\n\t(Modify 3th node)");
	modify_at(3, 2003, l);
	
	display_forward(l);
	
	printf("\n\n\t(Delete last node and display backward)");
	delete_at(l->size, l);
	
	display_backward(l);
	
	//delete_list(l);
	
	//display_forward(l);
	
	//printf("\n\tList size: %i\n", l->size);
	putchar(10);
	return 0;
}

node *get_node(int x)
{
	node *tmp = (node *) malloc(sizeof(node));
	tmp->prev = NULL;
	tmp->num = x;
	tmp->next = NULL;
	return tmp;
}

list *create_list(char *name)
{
	list *lst = (list *) malloc(sizeof(list));
	lst->list_name = name;
	lst->head = NULL;
	lst->size = 0;
	return lst;
}

void insert_at_start(int datum, list *lst)
{
	node *new_node = get_node(datum);
	if (lst->head == NULL)
	{
		lst->head = new_node;
		lst->size++;
		return;
	}
	lst->head->prev = new_node;
	new_node->next = lst->head;
	lst->head = new_node;
	lst->size++;
}

void display_forward(list *lst)
{
	node *head = lst->head;
	if (head == NULL) {
		printf("\n\n\t(List '%s' is empty.)\n", lst->list_name);
		return;
	}
	printf("\n\n\tList '%s' has %i element(s):\n", lst->list_name, lst->size);
	printf("\t[F>>:]");
	while (head != NULL)
	{
		printf(" %i ", head->num);
		head = head->next;
	}
}

void insert_at(int pos, int datum, list *lst)
{
	if (pos < 1 || pos > lst->size)
	{
		printf("\n\n\tError in list '%s': Position to insert (%i) is not valid.", lst->list_name, pos);
		return;
	}
	if (pos == 1)
	{
		insert_at_start(datum, lst);
		return;
	}
	
	node *new_node = get_node(datum);
	node *prev_node = lst->head, *next_node;
	int i;
	for (i = 1; i <= pos - 2; ++i)
		prev_node = prev_node->next;
	next_node = prev_node->next;
	next_node->prev = new_node;
	prev_node->next = new_node;
	new_node->prev = prev_node;
	new_node->next = next_node;
	lst->size++;
}

node *node_at(int pos, list *lst)
{
	if (pos < 1 || pos > lst->size)
	{
		printf("\n\n\tError in list '%s': Position (%i) is not valid.", lst->list_name, pos);
		return lst->head;
	}
	node *tmp_node = lst->head;
	int i;
	for (i = 1; i < pos; ++i)
		tmp_node = tmp_node->next;
	return tmp_node;
}


void modify_at(int pos, int new_value, list *lst)
{
	node *modify = node_at(pos, lst);
	modify->num = new_value;
}

void delete_at(int pos, list *lst)
{
	if (pos == 1 && lst->head == NULL)
	{
		/* if the node is the first one and only one */
		free(lst->head);
		lst->head = NULL;
		lst->size--;
		return;	
	}
	else if (pos == 1 && lst->head != NULL)
	{
		/* if the node is the first one and not the only one */
		node *tmp = lst->head;
		lst->head = lst->head->next;
		free(tmp);
		lst->size--;
		return;
	}
	else if(pos == lst->size)
	{
		/* if node is the last one */
		node *last_node = node_at(lst->size, lst);
		last_node->prev->next = NULL;
		last_node->prev = NULL;
		free(last_node);
		lst->size--;
		return;
	}
	node *_delete = node_at(pos, lst);
	node *prev_node = _delete->prev;
	node *next_node = _delete->next;
	prev_node->next = next_node;
	next_node->prev = prev_node;
	free(_delete);
	lst->size--;
}

/*
void delete_list(list *lst)
{
	node *head = lst->head;
	node *prev_node = lst->head;
	
	while (head != NULL)
	{
		prev_node = head;
		//head = head->next;
		//free();
		head->prev = NULL;
		prev_node->next = NULL;
		free(prev_node);
		head = head->next;
	}
	free(head);
	free(lst);
}
*/

void insert_at_end(int datum, list *lst)
{
	node *new_node = get_node(datum);
	if (lst->head == NULL)
	{
		lst->head = new_node;
		lst->size++;
		return;
	}
	node *last_node = node_at(lst->size, lst);
	last_node->next = new_node;
	new_node->prev = last_node;
	lst->size++;
}

void display_backward(list *lst)
{
	if (lst->head == NULL) {
		printf("\n\n\t(List '%s' is empty.)\n", lst->list_name);
		return;
	}
	node *last = node_at(lst->size, lst);
	printf("\n\n\tList '%s' has %i element(s):\n", lst->list_name, lst->size);
	printf("\t[<<B:]");
	while (last != NULL)
	{
		printf(" %i ", last->num);
		last = last->prev;
	}
}
