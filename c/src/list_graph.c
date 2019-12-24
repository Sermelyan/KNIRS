//
// Created by ser on 17.12.2019.
//

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "list_graph.h"

List_graph *list_graph_create(unsigned int count) {
    List_graph *temp = (List_graph *) calloc(1, sizeof(List_graph));
    if (!temp) {
        perror("Can't allocate memory for graph!\n");
        return NULL;
    }
    temp->count = count;
    temp->adjacency_lists = (Vector **) calloc(count, sizeof(Vector *));
    if (!temp->adjacency_lists) {
        perror("Can't allocate memory for graph array!\n");
        list_graph_delete(temp);
        return NULL;
    }
    for (unsigned int i = 0; i < count; i++) {
        temp->adjacency_lists[i] = create();
        if (!temp->adjacency_lists[i]) {
            perror("Can't allocate memory for graph array part!\n");
            list_graph_delete(temp);
            return NULL;
        }
    }
    return temp;
}

void list_graph_delete(List_graph *ths) {
    for (unsigned int i = 0; i < ths->count; i++)
        delete_vec(ths->adjacency_lists[i]);
    free(ths->adjacency_lists);
    free(ths);
}

inline void list_graph_add_edge(List_graph *ths, unsigned int from, unsigned int to) {
    assert(from >= 0 && from < ths->count);
    assert(to >= 0 && to < ths->count);
    push_back(ths->adjacency_lists[from], to);
}

inline Vector *list_graph_get_next_vertices(List_graph *ths, unsigned int vertex) {
    assert(vertex >= 0 && vertex < ths->count);
    return create_from(ths->adjacency_lists[vertex]->size, ths->adjacency_lists[vertex]->array);
}

Vector *list_graph_get_prev_vertices(List_graph *ths, unsigned int vertex) {
    assert(vertex >= 0 && vertex < ths->count);
    Vector *result = create();
    for (unsigned int from = 0; from < ths->count; from++)
        for (unsigned int i = 0; i < ths->adjacency_lists[from]->size; i++)
            if (get_at(ths->adjacency_lists[from], i) == vertex)
                push_back(result, from);
    return result;
}
