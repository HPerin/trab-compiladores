//
// Created by lucas on 11/08/15.
//

#ifndef LIBHASH_HASH_H
#define LIBHASH_HASH_H

#include <stdbool.h>

typedef struct hash_node {
    char * data;
    int type;
    struct hash_node * next;
} hash_node_t;

typedef struct hash_map {
    hash_node_t ** nodes;
    int size;
} hash_map_t;

hash_map_t * hash_map_new();
void hash_map_insert(hash_map_t * hash_map, int type, const char *data);
hash_node_t * hash_map_search(hash_map_t * hash_map, const char * data);
void hash_map_print(hash_map_t * hash_map);

#endif //LIBHASH_HASH_H
