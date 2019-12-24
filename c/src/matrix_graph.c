//
// Created by ser on 16.12.2019.
//

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "matrix_graph.h"

Matrix_graph *matrix_graph_create(unsigned int count) {
    Matrix_graph *temp = (Matrix_graph *) calloc(1, sizeof(Matrix_graph));
    if (!temp) {
        perror("Can't allocate memory for graph!\n");
        return NULL;
    }
    temp->count = count;
    temp->matrix = (unsigned int **) calloc(count, sizeof(unsigned int *));
    if (!temp->matrix) {
        perror("Can't allocate memory for graph array!\n");
        matrix_graph_delete_graph(temp);
        return NULL;
    }
    for (unsigned int i = 0; i < count; i++) {
        temp->matrix[i] = (unsigned int *) calloc(count, sizeof(unsigned int));
        if (!temp->matrix[i]) {
            perror("Can't allocate memory for graph array part!\n");
            matrix_graph_delete_graph(temp);
            return NULL;
        }
    }
    return temp;
}

void matrix_graph_delete_graph(Matrix_graph *ths) {
    for (unsigned int i = 0; i < ths->count; i++)
        free(ths->matrix[i]);
    free(ths->matrix);
    free(ths);
}

inline void matrix_graph_add_edge(Matrix_graph *ths, unsigned int from, unsigned int to) {
    assert(from >= 0 && from < ths->count);
    assert(to >= 0 && to < ths->count);
    ths->matrix[from][to]++;
}

Vector *matrix_graph_get_next_vertices(Matrix_graph *ths, unsigned int vertex) {
    assert(vertex >= 0 && vertex < ths->count);
    Vector *result = create();
    for (unsigned int i = 0; i < ths->count; i++)
        if (ths->matrix[vertex][i] > 0)
            push_back(result, i);
    return result;
}

Vector *matrix_graph_get_prev_vertices(Matrix_graph *ths, unsigned int vertex) {
    assert(vertex >= 0 && vertex < ths->count);
    Vector *result = create();
    for (unsigned int i = 0; i < ths->count; i++)
        if (ths->matrix[vertex][i] > 0)
            push_back(result, i);
    return result;
}
