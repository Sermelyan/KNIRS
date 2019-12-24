//
// Created by ser on 22.12.2019.
//
//
// Created by ser on 14.12.2019.
//

#include <gtest/gtest.h>
#include <queue>
#include <random>
#include <vector>


#include "MatrixGraph.hpp"

void BFS(const IGraph &graph, unsigned int vertex) {
    std::vector<bool> visited(graph.VerticesCount(), false);
    std::queue<unsigned int> qu;
    qu.push(vertex);
    visited[vertex] = true;

    while (!qu.empty()) {
        unsigned int current = qu.front();
        qu.pop();
        std::vector<unsigned int> nextVertices = graph.GetNextVertices(current);
        for (const auto& v : nextVertices)
            if (!visited[v]) {
                qu.push(v);
                visited[v] = true;
            }
    }
}

std::vector<std::pair<unsigned int, unsigned int>> arcs;
MatrixGraph *mg;
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
    mg = new MatrixGraph(count);
}

TEST(GraphFilling, MatrixFill) {
    for (const auto &arc : arcs) {
        mg->AddEdge(arc.first, arc.second);
    }
}

TEST(GraphBFSTest, Matrix) {
    for (int v = 0; v < 1000; ++v) {
        BFS(*mg, v);
    }
}

TEST(DataFree, CleanUp) {
    delete mg;
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
