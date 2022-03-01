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
  tmp_node->left = NULL;
  return tmp_node;
}

int insert(tree_node_t *tree, int new_key, object_t *new_object)
{
  tree_node_t *tmp_node;
  if (tree->left == NULL)
  {
    tree->left = (tree_node_t*) new_object;
    tree->key = new_key;
    tree->right = NULL;
  }
  else
  {
    tmp_node = tree;
    while (tmp_node->right != NULL)
      if (new_key < tmp_node->key)
        tmp_node = tmp_node->left;
      else
        tmp_node = tmp_node->right;
    /* found the candidate leaf: test wether key distinct */
    if (tmp_node->key == new_key)
      return 0 * printf("there was an error\n") - 1;
    /*key is distinct: perform insertion*/
    {
      tree_node_t *old_leaf, *new_leaf;
      old_leaf = (tree_node_t*) malloc(sizeof(tree_node_t));
      old_leaf->left = tmp_node->left;
      old_leaf->key = tmp_node->key;
      old_leaf->right = NULL;
      new_leaf = (tree_node_t*) malloc(sizeof(tree_node_t));
      new_leaf->left = (tree_node_t*) new_object; 
      new_leaf->key = new_key;
      new_leaf->right = NULL;
      if (tmp_node->key < new_key)
      {
        tmp_node->right = new_leaf;
        tmp_node->left = old_leaf;
        tmp_node->key = new_key;
      }
      else
      {
        tmp_node->left = new_leaf;
        tmp_node->right = old_leaf;
      }
    }
  }
  return 0;
}

void main()
{
  tree_node_t *tree = create_tree();
  object_t
  *obj1 = (object_t*) malloc(sizeof(object_t)),
  *obj2 = (object_t*) malloc(sizeof(object_t)),
  *obj3 = (object_t*) malloc(sizeof(object_t)),
  *obj4 = (object_t*) malloc(sizeof(object_t));

  obj1->first = "Jeremy";
  obj1->last = "Fonseca";

  obj2->first = "Pedro";
  obj2->last = "Páramo";

  obj3->first = "Rubén";
  obj3->last = "Darío";

  obj4->first = "Edsger";
  obj4->last = "Dijkstra";

  insert(tree, 5, obj1);
  insert(tree, 2, obj2);
  insert(tree, 7, obj3);
  insert(tree, 3, obj4);

  // printf("OBJECT: (%i) %s %s\n", \
  // tree->left->key, \
  // ((object_t*) tree->left->left)->first, \
  // ((object_t*) tree->left->left)->last);

  // printf("OBJECT: (%i) %s %s\n", \
  // tree->right->left->key, \
  // ((object_t*) tree->right->left->left)->first, \
  // ((object_t*) tree->right->left->left)->last);

  // printf("OBJECT: (%i) %s %s\n", \
  // tree->right->right->key, \
  // ((object_t*) tree->right->right->left)->first, \
  // ((object_t*) tree->right->right->left)->last);

  printf("ROOT KEY: %i\n", tree->key);
  printf("WORKING KEY: %i\n", tree->right->key);
  // printf("tree->key: %i\n", tree->key);
  // printf("tree->right->key: %i\n", tree->right->key);
  // printf("tree->left->key: %i\n", tree->left->key);
  // printf("tree->right->key: %i\n", tree->right->key);


  return;
}