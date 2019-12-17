//
// Created by ser on 17.12.2019.
//

#include "utils.h"

#ifndef GRAPH_LIST_GRAPH_H
#define GRAPH_LIST_GRAPH_H

typedef struct l_graph {
    Vector **adjacency_lists;
    unsigned int count;
} List_graph;

List_graph *list_graph_create(unsigned int count);
void list_graph_delete(List_graph *ths);

void list_graph_add_edge(List_graph *ths, unsigned int from, unsigned int to);

Vector *list_graph_get_next_vertices(List_graph *ths, unsigned int vertex);
Vector *list_graph_get_prev_vertices(List_graph *ths, unsigned int vertex);

#endif //GRAPH_LIST_GRAPH_H
