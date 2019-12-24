//
// Created by ser on 14.12.2019.
//

#include <gtest/gtest.h>
#include <queue>
#include <random>
#include <vector>
#include <ListGraph.hpp>

#include "SetGraph.hpp"
#include "UnorderedSetGraph.hpp"

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
SetGraph *sg;
UnorderedSetGraph *ag;
ListGraph *lg;
unsigned int count = 100000;

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

TEST(DataPrerpare, SetAlloc) {
    sg = new SetGraph(count);
}

TEST(DataPrerpare, UnorderedSetAlloc) {
    ag = new UnorderedSetGraph(count);
}

TEST(DataPrerpare, ListAlloc) {
    lg = new ListGraph(count);
}

TEST(GraphFilling, SetFill) {
    for (const auto &arc : arcs) {
        sg->AddEdge(arc.first, arc.second);
    }
}

TEST(GraphFilling, UnorderedSetFill) {
    for (const auto &arc : arcs) {
        ag->AddEdge(arc.first, arc.second);
    }
}

TEST(GraphFilling, ListFill) {
    for (const auto &arc : arcs) {
        lg->AddEdge(arc.first, arc.second);
    }
}

TEST(GraphBFSTest, Set) {
    for (int v = 0; v < sg->VerticesCount(); ++v) {
        BFS(*sg, v);
    }
}

TEST(GraphBFSTest, UnorderedSet) {
    for (int v = 0; v < ag->VerticesCount(); ++v) {
        BFS(*ag, v);
    }
}

TEST(GraphBFSTest, List) {
    for (int v = 0; v < lg->VerticesCount(); ++v) {
        BFS(*lg, v);
    }
}

TEST(DataFree, CleanUp) {
    delete sg;
    delete ag;
    delete lg;
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}