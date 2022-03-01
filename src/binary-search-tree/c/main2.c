#include <stdio.h>
#include <stdlib.h>

typedef struct object_t
{
  char *first;
  char *last;
} object_t;

typedef struct tree_node_t
{
  int key;
  struct tree_node_t *left;
  struct tree_node_t *right;
} tree_node_t;


tree_node_t *create_tree(void)
{
  tree_node_t *tmp_node;
  tmp_node = (tree_node_t*) malloc(sizeof(tree_node_t));
  tmp_node = NULL;
  // tmp_node->left = NULL;
  // tmp_node->right = NULL;
  return tmp_node;
}

int insert(tree_node_t *tree, int new_key)
{
  tree_node_t *y = NULL;
  tree_node_t *x = tree;
  while (x != NULL)
  {
    y = x;
    if (new_key < x->key)
      x = x->left;
    else
      x = x->right;
  }
}

void main()
{
  tree_node_t *tree = create_tree();
}