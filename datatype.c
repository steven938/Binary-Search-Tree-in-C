#include "datatype.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

// Duplicate string pointed to by str with dynamic memory allocation.
char * string_dup(char *str){
    int size = 0;
    while(str[size++]);
    char * pointer = malloc((size_t)(size * sizeof(char)));
    int i=0;
    for(; i<size; i++){
        pointer[i] = str[i];
    }
    return(pointer);
}

// Generate a key with dynamic memory allocation.
Key key_gen(char *skey1, char *skey2){
    Key keyPointer;
    keyPointer = malloc(sizeof(Key_struct));
    keyPointer->skey1 = string_dup(skey1);
    keyPointer->skey2 = string_dup(skey2);
    return keyPointer;
}


//Use strcmp( ) to do comparison. If key1->skey1 and key2->skey1 are different, then
//they determine the comparison result. If key1->skey1 and key2->skey1 are the same,
//then key1->skey2 and key2->skey2 determine the comparison result.
int key_comp(Key key1, Key key2){
    int comp = strcmp(key1->skey1, key2->skey2);
    if(comp==0){
        comp = strcmp(key1->skey2, key2->skey2);
    }
    return comp;
}

// Print a key.
void key_print(Key key){
    printf("%s %s", key->skey1, key->skey2);
}

// Free memory allocated for key
void key_free(Key key){
    free(key->skey2);
    free(key->skey1);
    free(key);
}

// Generate a data with dynamic memory allocation
Data data_gen(int idata){
    Data newData;
    newData = malloc(sizeof(int));
    *newData = idata;
    return newData;
}

// Assign data with idata.
void data_set(Data data, int idata){
    *data = idata;
}

// Print a data.
void data_print(Data data){
    printf("%d", *data);
}

// Free memory allocated for data
void data_free(Data data){
    free(data);
}


