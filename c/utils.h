//
// Created by ser on 16.12.2019.
//

#ifndef GRAPH_UTILS_H
#define GRAPH_UTILS_H

typedef struct dynamic_array {
    unsigned int *array;
    unsigned int size;
    unsigned int capacity;
} Vector;

Vector *create();
Vector *create_size(unsigned int size);
Vector *create_from(unsigned int size, unsigned int *from);

void delete_vec(Vector *ths);

int push_back(Vector *ths, unsigned int element);
const unsigned int get_at(Vector *ths, unsigned int pos);
int set_at(Vector *ths, unsigned int pos, unsigned int element);

#endif //GRAPH_UTILS_H
