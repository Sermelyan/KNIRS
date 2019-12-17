//
// Created by ser on 17.12.2019.
//

#include "utils.h"

#ifndef GRAPH_LIST_GRAPH_H
#define GRAPH_LIST_GRAPH_H

typedef struct graph {
    Vector **adjacency_lists;
    unsigned int count;
} List_graph;

List_graph *create_graph(unsigned int count);
void delete_graph(List_graph *ths);

void add_edge(List_graph *ths, unsigned int from, unsigned int to);

Vector *get_next_vertices(List_graph *ths, unsigned int vertex);
Vector *get_prev_vertices(List_graph *ths, unsigned int vertex);

#endif //GRAPH_LIST_GRAPH_H
