//
// Created by ser on 14.12.2019.
//

#include "UnorderedSetGraph.hpp"
#include <cassert>

UnorderedSetGraph::UnorderedSetGraph(unsigned int count) : adjacencySets(count) {}

UnorderedSetGraph::UnorderedSetGraph(const IGraph &graph) : UnorderedSetGraph(graph.VerticesCount()) {
    for (unsigned int i = 0; i < graph.VerticesCount(); i++)
        for (const auto &nextVertex : graph.GetNextVertices(i))
            adjacencySets[i].insert(nextVertex);
}

UnorderedSetGraph::~UnorderedSetGraph() = default;

void UnorderedSetGraph::AddEdge(unsigned int from, unsigned int to) {
    assert(from >= 0 && from < adjacencySets.size());
    assert(to >= 0 && to < adjacencySets.size());
    adjacencySets[from].insert(to);
}

unsigned int UnorderedSetGraph::VerticesCount() const { return adjacencySets.size(); }

std::vector<unsigned int> UnorderedSetGraph::GetNextVertices(unsigned int vertex) const {
    assert(vertex >= 0 && vertex < adjacencySets.size());
    return std::vector<unsigned int>(adjacencySets[vertex].begin(),
                                     adjacencySets[vertex].end());
}

std::vector<unsigned int> UnorderedSetGraph::GetPrevVertices(unsigned int vertex) const {
    assert(vertex >= 0 && vertex < adjacencySets.size());
    std::vector<unsigned int> result;
    for (unsigned int i = 0; i < adjacencySets.size(); i++)
        if (adjacencySets[i].find(vertex) != adjacencySets[i].end())
            result.push_back(i);
    return result;
}
