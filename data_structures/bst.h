#ifndef BST_H
#define BST_H

struct tree
{
  void **info;
  struct tree *left;
  struct tree *right;
};

struct tree *bst_create();
struct tree *bst_insert(struct tree *, void *);
int bst_delete(struct tree *, void *);
struct tree *large_element_lst(struct tree *);
struct tree *small_element_rst(struct tree *);
void bst_print_inorder(struct tree *);
void bst_print_preorder(struct tree *);
void bst_print_postorder(struct tree *);

#endif
