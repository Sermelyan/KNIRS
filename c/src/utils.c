//
// Created by ser on 16.12.2019.
//

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"

static inline Vector *new_vector(unsigned int size, unsigned int capacity, unsigned int *from) {
    Vector *temp = (Vector *) calloc(1, sizeof(Vector));
    if (!temp) {
        perror("Can't allocate memory for vector!\n");
        return NULL;
    }
    temp->size = size;
    temp->capacity = capacity;
    temp->array = (unsigned int *) calloc(capacity, sizeof(unsigned int));
    if (!temp->array) {
        perror("Can't allocate memory for vector array!\n");
        free(temp);
        return NULL;
    }
    if (from) {
        memcpy(temp->array, from, size * sizeof(unsigned int));
    }
    return temp;
}

static inline int resize(Vector *ths) {
    ths->capacity *= 2;
    unsigned int *temp = (unsigned int *) calloc(ths->capacity, sizeof(unsigned int));
    if (!temp) {
        perror("Can't allocate memory for vector array!\n");
        free(temp);
        return 0;
    }
    memcpy(temp, ths->array, ths->size * sizeof(unsigned int)); //TODO Add memcpy after check
    free(ths->array);
    ths->array = temp;
    return 1;
}

Vector *create() {
    return new_vector(0, 2, NULL);
}

Vector *create_size(unsigned int size) {
    return new_vector(size, size, NULL);
}
Vector *create_from(unsigned int size, unsigned int *from) {
    return new_vector(size, size, from);
}

void delete_vec(Vector *ths) {
    free(ths->array);
    free(ths);
}

inline int push_back(Vector *ths, unsigned int element) {
    if (ths->size == ths->capacity)
        if (!resize(ths))
            return 0;
    (ths->array)[ths->size++] = element;
    return 1;
}

inline unsigned int get_at(Vector *ths, unsigned int pos) {
    assert(pos >=0 && pos < ths->size);
    return ths->array[pos];
}

int set_at(Vector *ths, unsigned int pos, unsigned int element) {
    if (pos >=0 && pos < ths->size) {
        ths->array[pos] = element;
        return 1;
    }
    return 0;
}
