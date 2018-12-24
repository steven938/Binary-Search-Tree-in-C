#include "matrix.h"
#include "bstree.h"
#include "datatype.h"
#include "stdlib.h"
#include "stdio.h"

//Matrix construction using bstree_ini();
Matrix matrix_construction(void){
    Matrix new_matrix = bstree_ini();
    return new_matrix;
}

//If location (index1, index2) is defined in Matrix m, then return 1. Otherwise, return 0.
unsigned char matrix_isin(Matrix m, Index index1, Index index2){
    Key tempKey = key_gen(index1, index2);
    Data result = bstree_search(m, tempKey);
    if(result==NULL)
        return 0;
    return 1;
}

//If location (index1, index2) is defined in Matrix m, then return a pointer to the associated
//value. Otherwise, return NULL.
Value *matrix_get(Matrix m, Index index1, Index index2){
    Key tempKey = key_gen(index1, index2);
    return bstree_search(m, tempKey);
}

//Assign value to Matrix m at location (index1, index2). If that location already has value,
//then overwrite.
void matrix_set(Matrix m, Index index1, Index index2, Value value){
    Value* valuePointer = matrix_get(m, index1, index2);
    if(valuePointer!=NULL){
        *valuePointer = value;
    }else{
        Key newKey = key_gen(index1, index2);
        Data newData = data_gen(value);
        bstree_insert(m, newKey, newData);
    }
}


//If location (index1, index2) is defined in Matrix m, then increase the associated value by
//value. Otherwise, report error.
void matrix_inc(Matrix m, Index index1, Index index2, Value value){
    Value* valuePointer = matrix_get(m, index1, index2);
    if(valuePointer!=NULL)
        *valuePointer += value;
    else
        printf("ERROR: location does not exist in matrix");
}

//Print indices and values in the Matrix m (with bstree_traversal()).
void matrix_list(Matrix m){
    bstree_traversal(m);
}

//Free allocated space (with bstree_free()).
void matrix_destruction(Matrix m){
    bstree_free(m);
    free(m);
}
