#pragma once
#include "Utils.hpp"
namespace CinderPeak {
namespace PeakStore {
template <typename VertexType, typename EdgeType> class AdjacencyList {
private:
  std::unordered_map<VertexType, std::vector<std::pair<VertexType, EdgeType>>,
                     VertexHasher<VertexType>>
      _adj_list;

public:
  std::shared_ptr<GraphInternalMetadata> graph_metadata = nullptr;
  std::shared_ptr<GraphCreationOptions> create_options = nullptr;

  AdjacencyList(const std::shared_ptr<GraphInternalMetadata> &metadata,
                const std::shared_ptr<GraphCreationOptions> &options)
      : graph_metadata(metadata), create_options(options) {}

  void impl_addEdge(const VertexType &src, const VertexType &dest,
                    const EdgeType &weight) {
    _adj_list[src].emplace_back(dest, weight);
    std::cout << "Edge addition success\n";
  }
  void impl_addEdge(const VertexType &src, const VertexType &dest) {
    _adj_list[src].emplace_back(dest, EdgeType());
    std::cout << "Edge addition success\n";
  }
  void impl_addVertex(const VertexType &src) {
    _adj_list[src] = std::vector<std::pair<VertexType, EdgeType>>();
    std::cout << "Vertex addition success\n";
  }
  const EdgeType impl_getEdge(const VertexType &src,
                              const VertexType &dest) const {
    auto it = _adj_list.find(src);
    if (it != _adj_list.end()) {
      for (const auto &neighbor : it->second) {
        if (neighbor.first == dest) {
          return neighbor.second;
        }
      }
    }
    throw std::runtime_error("Edge not found"); // Handle missing edge
  }

  const std::vector<std::pair<VertexType, EdgeType>> &
  getNeighbors(const VertexType &src) const {
    static const std::vector<std::pair<VertexType, EdgeType>> empty;
    auto it = _adj_list.find(src);
    return (it != _adj_list.end()) ? it->second : empty;
  }
};
} // namespace PeakStore

} // namespace CinderPeak
