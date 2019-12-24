//
// Created by ser on 17.12.2019.
//

#include "utils.h"

#ifndef GRAPH_ARC_GRAPH_H
#define GRAPH_ARC_GRAPH_H

typedef struct a_graph {
    Vector *arcs;
    unsigned int count;
} Arc_graph;

Arc_graph *arc_graph_create(unsigned int count);
void arc_graph_delete(Arc_graph *ths);

void arc_graph_add_edge(Arc_graph *ths, unsigned int from, unsigned int to);

Vector *arc_graph_get_next_vertices(Arc_graph *ths, unsigned int vertex);
Vector *arc_graph_get_prev_vertices(Arc_graph *ths, unsigned int vertex);

#endif //GRAPH_ARC_GRAPH_H
