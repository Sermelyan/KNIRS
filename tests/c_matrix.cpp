//
// Created by ser on 22.12.2019.
//

#include <gtest/gtest.h>
#include <queue>
#include <random>
#include <vector>

extern "C" {
#include "matrix_graph.h"
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

std::vector<std::pair<unsigned int, unsigned int>> arcs;
Matrix_graph *mg;
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

TEST(DataPrerpare, MatrixAlloc) {
    mg = matrix_graph_create(count);
}

TEST(GraphFilling, MatrixFill) {
    for (const auto &arc : arcs) {
        matrix_graph_add_edge(mg, arc.first, arc.second);
    }
}

TEST(GraphBFSTest, Matrix) {
    for (int v = 0; v < 1000; ++v) {
        BFS(mg, v);
    }
}

TEST(DataFree, CleanUp) {
    matrix_graph_delete_graph(mg);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}