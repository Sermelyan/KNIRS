//
// Created by ser on 16.12.2019.
//

#include "utils.h"

#ifndef GRAPH_MATRIX_GRAPH_H
#define GRAPH_MATRIX_GRAPH_H

typedef struct m_graph {
    unsigned int **matrix;
    unsigned int count;
} Matrix_graph;

Matrix_graph *matrix_graph_create(unsigned int count);
void matrix_graph_delete_graph(Matrix_graph *ths);

void matrix_graph_add_edge(Matrix_graph *ths, unsigned int from, unsigned int to);

Vector *matrix_graph_get_next_vertices(Matrix_graph *ths, unsigned int vertex);
Vector *matrix_graph_get_prev_vertices(Matrix_graph *ths, unsigned int vertex);

#endif //GRAPH_MATRIX_GRAPH_H
