//
// Created by ser on 14.12.2019.
//

#include <gtest/gtest.h>
#include <queue>
#include <random>
#include <vector>

extern "C" {
    #include "matrix_graph.h"
    #include "list_graph.h"
    #include "arc_graph.h"
    #include "utils.h"
}

void BFS(Matrix_graph *graph, unsigned int vertex) {
    std::vector<bool> visited(graph->count, false);
    std::queue<unsigned int> qu;
    qu.push(vertex);
    visited[vertex] = true;

    while (!qu.empty()) {
        unsigned int current = qu.front();
        qu.pop();
        Vector *nextVertices = matrix_graph_get_next_vertices(graph, current);
        for (unsigned int i = 0; i < nextVertices->size; i++) {
            unsigned int v = get_at(nextVertices, i);
            if (!visited[v]) {
                qu.push(v);
                visited[v] = true;
            }
        }
        delete_vec(nextVertices);
    }
}

void BFS(List_graph *graph, unsigned int vertex) {
    std::vector<bool> visited(graph->count, false);
    std::queue<unsigned int> qu;
    qu.push(vertex);
    visited[vertex] = true;

    while (!qu.empty()) {
        unsigned int current = qu.front();
        qu.pop();
        Vector *nextVertices = list_graph_get_next_vertices(graph, current);
        for (unsigned int i = 0; i < nextVertices->size; i++) {
            unsigned int v = get_at(nextVertices, i);
            if (!visited[v]) {
                qu.push(v);
                visited[v] = true;
            }
        }
        delete_vec(nextVertices);
    }
}

void BFS(Arc_graph *graph, unsigned int vertex) {
    std::vector<bool> visited(graph->count, false);
    std::queue<unsigned int> qu;
    qu.push(vertex);
    visited[vertex] = true;

    while (!qu.empty()) {
        unsigned int current = qu.front();
        qu.pop();
        Vector *nextVertices = arc_graph_get_next_vertices(graph, current);
        for (unsigned int i = 0; i < nextVertices->size; i++) {
            unsigned int v = get_at(nextVertices, i);
            if (!visited[v]) {
                qu.push(v);
                visited[v] = true;
            }
        }
        delete_vec(nextVertices);
    }
}

std::vector<std::pair<unsigned int, unsigned int>> arcs;
List_graph *lg;
Matrix_graph *mg;
Arc_graph *ag;
unsigned int count = 10000;

TEST(DataPrerpare, ArcsGen) {
    std::random_device rd{};
    std::mt19937 gen{rd()};
    srandom(rd());

    std::normal_distribution<> d{(count / 2.0), 10};

    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < random() % 10; ++j)
            arcs.emplace_back(i, static_cast<unsigned int>(d(gen)));
    }
}

TEST(DataPrerpare, ListAlloc) {
    lg = list_graph_create(count);
}

TEST(DataPrerpare, MatrixAlloc) {
    mg = matrix_graph_create(count);
}

TEST(DataPrerpare, SetAlloc) {
    ag = arc_graph_create(count);
}

TEST(GraphFilling, ListFill) {
    for (const auto &arc : arcs) {
        list_graph_add_edge(lg, arc.first, arc.second);
    }
}

TEST(GraphFilling, MatrixFill) {
    for (const auto &arc : arcs) {
        matrix_graph_add_edge(mg, arc.first, arc.second);
    }
}

TEST(GraphFilling, ArcFill) {
    for (const auto &arc : arcs) {
        arc_graph_add_edge(ag, arc.first, arc.second);
    }
}

TEST(GraphBFSTest, List) {
    for (int v = 0; v < lg->count; ++v) {
        BFS(lg, v);
    }
}

TEST(GraphBFSTest, Matrix) {
    for (int v = 0; v < mg->count; ++v) {
        BFS(mg, v);
    }
}

TEST(GraphBFSTest, Arc) {
    for (int v = 0; v < ag->count; ++v) {
        BFS(ag, v);
    }
}

TEST(DataFree, CleanUp) {
    list_graph_delete(lg);
    matrix_graph_delete_graph(mg);
    arc_graph_delete(ag);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}