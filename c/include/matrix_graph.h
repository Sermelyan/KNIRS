//
// Created by ser on 16.12.2019.
//

#include "utils.h"

#ifndef GRAPH_MATRIX_GRAPH_H
#define GRAPH_MATRIX_GRAPH_H

typedef struct graph {
    unsigned int **matrix;
    unsigned int count;
} Matrix_graph;

Matrix_graph *create_graph(unsigned int count);
void delete_graph(Matrix_graph *ths);

void add_edge(Matrix_graph *ths, unsigned int from, unsigned int to);

Vector *get_next_vertices(Matrix_graph *ths, unsigned int vertex);
Vector *get_prev_vertices(Matrix_graph *ths, unsigned int vertex);

#endif //GRAPH_MATRIX_GRAPH_H
