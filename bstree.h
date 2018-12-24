#include "datatype.h"
#ifndef ASN5_BSTREE_H
#define ASN5_BSTREE_H


typedef struct BStree_node {
    Key key;
    Data data;
    struct BStree_node *left, *right;
} BStree_node;

typedef BStree_node** BStree;

BStree bstree_ini(void);
void bstree_insert(BStree bst, Key key, Data data);
BStree_node *new_node(Key key, Data data);
Data bstree_search(BStree bst, Key key);
void bstree_traversal(BStree bst);
void bstree_free(BStree bst);
void free_helper(BStree bst);

#endif //ASN5_BSTREE_H
