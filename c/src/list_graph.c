//
// Created by ser on 17.12.2019.
//

#include <stdlib.h>
#include <assert.h>

#include "list_graph.h"

List_graph *create_graph(unsigned int count) {
    List_graph *temp = (List_graph *) calloc(1, sizeof(List_graph));
    if (!temp) {
        perror("Can't allocate memory for graph!\n");
        return NULL;
    }
    temp->count = count;
    temp->adjacency_lists = (Vector **) calloc(count, sizeof(Vector *));
    if (!temp->adjacency_lists) {
        perror("Can't allocate memory for graph array!\n");
        delete_graph(temp);
        return NULL;
    }
    for (unsigned int i = 0; i < count; i++) {
        temp->adjacency_lists[i] = create();
        if (!temp->adjacency_lists[i]) {
            perror("Can't allocate memory for graph array part!\n");
            delete_graph(temp);
            return NULL;
        }
    }
    return temp;
}

void delete_graph(List_graph *ths) {
    for (unsigned int i = 0; i < ths->count; i++)
        delete_vec(ths->adjacency_lists[i]);
    free(ths->adjacency_lists);
    free(ths);
}

inline void add_edge(List_graph *ths, unsigned int from, unsigned int to) {
    assert(from >= 0 && from < ths->count);
    assert(to >= 0 && to < ths->count);
    push_back(ths->adjacency_lists[from], to);
}

Vector *get_next_vertices(List_graph *ths, unsigned int vertex) {
    assert(vertex >= 0 && vertex < ths->count);
    Vector *result = create();
    for (unsigned int i = 0; i < ths->count; i++)
        if (ths->adjacency_lists[vertex][i] > 0)
            push_back(result, i);
    return result;
}

Vector *get_prev_vertices(List_graph *ths, unsigned int vertex) {
    assert(vertex >= 0 && vertex < ths->count);
    Vector *result = create();
    for (unsigned int i = 0; i < ths->count; i++)
        if (ths->adjacency_lists[vertex][i] > 0)
            push_back(result, i);
    return result;
}
