//
// Created by ser on 14.12.2019.
//

#ifndef GRAPH_UNORDERED_SETGRAPH_HPP
#define GRAPH_UNORDERED_SETGRAPH_HPP

#include <unordered_set>
#include <vector>

#include "interface.hpp"

class UnorderedSetGraph : public IGraph {
  public:
    explicit UnorderedSetGraph(unsigned int count);
    UnorderedSetGraph(const IGraph &graph);
    ~UnorderedSetGraph() override;

    void AddEdge(unsigned int from, unsigned int to) override;

    [[nodiscard]] unsigned int VerticesCount() const override;

    [[nodiscard]] std::vector<unsigned int>
    GetNextVertices(unsigned int vertex) const override;
    [[nodiscard]] std::vector<unsigned int>
    GetPrevVertices(unsigned int vertex) const override;

  private:
    std::vector<std::unordered_set<unsigned int>> adjacencySets;
};

#endif // GRAPH_UNORDERED_SETGRAPH_HPP
