#include "datatype.h"
#include "bstree.h"
#ifndef ASN5_MATRIX_H
#define ASN5_MATRIX_H

typedef BStree Matrix;
typedef char* Index;
typedef int Value;

Matrix matrix_construction(void);
unsigned char matrix_isin(Matrix m, Index index1, Index index2);
Value *matrix_get(Matrix m, Index index1, Index index2);
void matrix_set(Matrix m, Index index1, Index index2, Value value);
void matrix_inc(Matrix m, Index index1, Index index2, Value value);
void matrix_list(Matrix m);
void matrix_destruction(Matrix m);

#endif //ASN5_MATRIX_H
