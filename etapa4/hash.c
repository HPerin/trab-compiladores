//
// Created by lucas on 11/08/15.
//

#include "hash.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define HASH_MAP_INITIAL_SIZE 997

int get_hash(const char * data) {
    int i;
    int hash = 1;

    for (i = 0; i < strlen(data); i++)
        hash = (hash * data[i]) % HASH_MAP_INITIAL_SIZE;

    return hash;
}

hash_map_t *hash_map_new() {
    hash_map_t * hash_map;

    hash_map = malloc(sizeof(hash_map));
    hash_map->nodes = calloc(HASH_MAP_INITIAL_SIZE, sizeof(hash_node_t*));
    hash_map->size = 0;

    return hash_map;
}

void hash_map_insert(hash_map_t * hash_map, int type, const char *data) {
    hash_node_t * hash_node;
    int hash;

    hash_node = hash_map_search(hash_map, data);
    if (hash_node != NULL) {
        return;
    }

    hash_node = malloc(sizeof(hash_node_t));
    hash_node->data = calloc(strlen(data), sizeof(char));
    hash_node->type = type;

   if(type == 3) hash_node->dataType = DATATYPE_INT;
    strcpy(hash_node->data, data);
    hash_node->next = NULL;

    hash = get_hash(data);
    if (hash_map->nodes[hash] == NULL) {
        hash_map->nodes[hash] = hash_node;
    } else {
        hash_node_t * hash_node_aux = hash_map->nodes[hash];
        while(hash_node_aux->next != NULL)
            hash_node_aux = hash_node_aux->next;

        hash_node_aux->next = hash_node;
    }

    hash_map->size++;
}

hash_node_t * hash_map_search(hash_map_t * hash_map, const char *data) {
    hash_node_t * hash_node;
    int hash = get_hash(data);

    hash_node = hash_map->nodes[hash];
    while(hash_node != NULL) {
        if (!strcmp(data, hash_node->data))
            return hash_node;

        hash_node = hash_node->next;
    }

    return false;
}

void hash_map_print(hash_map_t *hash_map) {
    hash_node_t * hash_node;
    int i;

    for (i = 0; i < HASH_MAP_INITIAL_SIZE; i++) {
        hash_node = hash_map->nodes[i];
        while(hash_node != NULL) {
            printf("{ hash: %d, type: %d, data: %s, dataType: %d}\n", i, hash_node->type, hash_node->data, hash_node->dataType);
            hash_node = hash_node->next;
        }
    }
}
