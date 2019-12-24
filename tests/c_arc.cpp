//
// Created by ser on 22.12.2019.
//

#include <gtest/gtest.h>
#include <queue>
#include <random>
#include <vector>

extern "C" {
#include "arc_graph.h"
#include "utils.h"
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

TEST(DataPrerpare, ArcAlloc) {
    ag = arc_graph_create(count);
}

TEST(GraphFilling, ArcFill) {
    for (const auto &arc : arcs) {
        arc_graph_add_edge(ag, arc.first, arc.second);
    }
}

TEST(GraphBFSTest, Arc) {
    for (int v = 0; v < 1000; ++v) {
        BFS(ag, v);
    }
}

TEST(DataFree, CleanUp) {
    arc_graph_delete(ag);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}