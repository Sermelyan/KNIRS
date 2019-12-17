//
// Created by ser on 17.12.2019.
//

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "arc_graph.h"

Arc_graph *arc_graph_create(unsigned int count) {
    Arc_graph *temp = (Arc_graph *) calloc(1, sizeof(Arc_graph));
    if (!temp) {
        perror("Can't allocate memory for graph!\n");
        return NULL;
    }
    temp->count = count;
    temp->arcs = create();
    if (!temp->arcs) {
        perror("Can't allocate memory for graph array!\n");
        arc_graph_delete(temp);
        return NULL;
    }
    return temp;
}

void arc_graph_delete(Arc_graph *ths) {
    delete_vec(ths->arcs);
    free(ths);
}

inline void arc_graph_add_edge(Arc_graph *ths, unsigned int from, unsigned int to) {
    assert(from >= 0 && from < ths->count);
    assert(to >= 0 && to < ths->count);
    push_back(ths->arcs, from);
    push_back(ths->arcs, to);
}

inline Vector *arc_graph_get_next_vertices(Arc_graph *ths, unsigned int vertex) {
    assert(vertex >= 0 && vertex < ths->count);
    Vector *result = create();
    for (unsigned int i = 0; i < ths->arcs->size; i += 2)
        if (get_at(ths->arcs, i) == vertex)
            push_back(result, get_at(ths->arcs,i + 1));
    return result;
}

Vector *arc_graph_get_prev_vertices(Arc_graph *ths, unsigned int vertex) {
    assert(vertex >= 0 && vertex < ths->count);
    Vector *result = create();
    for (unsigned int i = 1; i < ths->arcs->size; i += 2)
        if (get_at(ths->arcs, i) == vertex)
            push_back(result, get_at(ths->arcs,i - 1));
    return result;
}

