//
// Created by ser on 22.12.2019.
//

#include <gtest/gtest.h>
#include <queue>
#include <random>
#include <vector>

extern "C" {
#include "list_graph.h"
#include "utils.h"
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

std::vector<std::pair<unsigned int, unsigned int>> arcs;
List_graph *lg;
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

TEST(GraphFilling, ListFill) {
    for (const auto &arc : arcs) {
        list_graph_add_edge(lg, arc.first, arc.second);
    }
}

TEST(GraphBFSTest, List) {
    for (int v = 0; v < 1000; ++v) {
        BFS(lg, v);
    }
}

TEST(DataFree, CleanUp) {
    list_graph_delete(lg);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}