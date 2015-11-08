//
// Created by lucas on 11/08/15.
//

#ifndef LIBHASH_HASH_H
#define LIBHASH_HASH_H

#include <stdbool.h>



#define SYMBOL_FUNCTION 8
#define SYMBOL_VARIABLE 9
#define SYMBOL_VECTOR 10
#define SYMBOL_TEMP 11
#define SYNBOL_LABEL 12

//datatypes

#define DATATYPE_UNDEFINED   0
#define DATATYPE_INT         1
#define DATATYPE_CHAR        2
#define DATATYPE_REAL        3
#define DATATYPE_BOOL        4





typedef struct hash_node {
    char * data;
    int type;
    int dataType;
    struct hash_node * next;
} hash_node_t;

typedef struct hash_map {
    hash_node_t ** nodes;
    int size;
} hash_map_t;

hash_node_t * hash_map_maketemp(hash_map_t * hash_map);
hash_node_t * hash_map_makelabel(hash_map_t * hash_map);

hash_map_t * hash_map_new();
void hash_map_insert(hash_map_t * hash_map, int type, const char *data);
hash_node_t * hash_map_search(hash_map_t * hash_map, const char * data);
void hash_map_print(hash_map_t * hash_map);

#endif //LIBHASH_HASH_H
