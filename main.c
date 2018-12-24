#include <stdio.h>
#include "datatype.h"
#include "bstree.h"
#include "matrix.h"
#include "datatype.h"


int main() {
    Matrix m = matrix_construction();
//    matrix_set(m, "aaaaaa", "bbbbb", 1);
    matrix_set(m, "aab", "aab", 1);
    matrix_set(m, "hello", "aa", 1);
    matrix_list(m);
//    while(scanf" ")
    return 0;
}

