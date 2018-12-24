#include "stdio.h"
#include "bstree.h"
#include "datatype.h"
#include "stdlib.h"
//Allocate memory of type BStree_node*, set the value to NULL, and return a pointer to the
//allocated memory.
BStree bstree_ini(void){
    BStree nodePointer;
    nodePointer = malloc(sizeof(BStree_node*));
    *nodePointer = NULL;
    return nodePointer;
}

//Insert data with key into bst. If key is in bst, then do nothing.
void bstree_insert(BStree bst, Key key, Data data){
    if(*bst == NULL)
        *bst = new_node(key, data);
    int comp = key_comp((*bst)->key, key);
    if(comp > 0)
        bstree_insert(&((*bst)->left), key, data);
    else if(comp < 0)
        bstree_insert(&((*bst)->right), key, data);
    else
        return;
}

// a helper function for insertion to create a pointer to a tree node from
//key and data
BStree_node *new_node(Key key, Data data){
    BStree_node* newNode = malloc(sizeof(BStree_node));
    newNode->key = key;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// If key is in bst, return key’s associated data. If key is not in bst, return NULL.
Data bstree_search(BStree bst, Key key){
    if(*bst == NULL)
        return NULL;
    int comp = key_comp((*bst)->key, key);
    if(comp > 0)
        bstree_search(&((*bst)->left), key);
    else if(comp < 0)
        bstree_search(&((*bst)->right), key);
    else
        return (*bst)->data;
}

// In order traversal of bst and print each node’s key and data.
void bstree_traversal(BStree bst){
    if(*bst==NULL)
        return;
    bstree_traversal(&((*bst)->left));
    key_print((*bst)->key);
    printf(" ");
    data_print((*bst)->data);
    printf("\n");
    bstree_traversal(&((*bst)->right));
}

// Free all the dynamically allocated memory of bst.
void bstree_free(BStree bst){
    free_helper(bst);
    free(bst);
}

void free_helper(BStree bst){
    if(*bst == NULL)
        return;
    bstree_free(&((*bst)->left));
    bstree_free(&((*bst)->right));
    key_free((*bst)->key);
    data_free((*bst)->data);
    free(*bst);
}
