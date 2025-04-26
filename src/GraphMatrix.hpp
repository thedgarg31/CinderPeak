#include "StorageEngine/Utils.hpp"
#include <iostream>

namespace CinderPeak {
namespace PeakStore {
template <typename VertexType, typename EdgeType> class PeakStore;
}

template <typename VertexType, typename EdgeType> class GraphMatrix {
private:
  std::unique_ptr<CinderPeak::PeakStore::PeakStore<VertexType, EdgeType>>
      peak_store;

public:
  GraphMatrix(const GraphCreationOptions &options =
                  CinderPeak::PeakStore::DEFAULT_GRAPH_OPTIONS) {
    CinderPeak::PeakStore::GraphInternalMetadata metadata("graph_matrix");
    peak_store = std::make_unique<
        CinderPeak::PeakStore::PeakStore<VertexType, EdgeType>>(metadata,
                                                                options);
  }
  void addVertex(const VertexType &src) {
    auto resp = peak_store->addVertex(src);
    if (!resp.isOK()) {
      Exceptions::handle_exception_map(resp);
      return;
    }
  }
  void addEdge(const VertexType &src, const VertexType &dest) {
    auto resp = peak_store->addEdge(src, dest);
    if (!resp.isOK()) {
      Exceptions::handle_exception_map(resp);
      return;
    }
    auto ctx = peak_store->getContext();
    if (ctx->create_options->hasOption(GraphCreationOptions::Undirected)) {
      LOG_INFO("Called unweighted addEdge undirected");
      auto resp = peak_store->addEdge(dest, src);
      if (!resp.isOK()) {
        Exceptions::handle_exception_map(resp);
        return;
      }
    }
  }
  void addEdge(const VertexType &src, const VertexType &dest,
               const EdgeType &weight) {
    auto resp = peak_store->addEdge(src, dest, weight);
    if (!resp.isOK()) {
      LOG_INFO("Called weighted addEdge");
      Exceptions::handle_exception_map(resp);
      return;
    }
    auto ctx = peak_store->getContext();
    if (ctx->create_options->hasOption(GraphCreationOptions::Undirected)) {
      LOG_INFO("Called weighted addEdge undirected");
      auto resp = peak_store->addEdge(dest, src, weight);
      if (!resp.isOK()) {
        Exceptions::handle_exception_map(resp);
        return;
      }
    }
  }
  EdgeType getEdge(const VertexType &src, const VertexType &dest) {
    LOG_INFO("Called getEdge");
    auto [data, status] = peak_store->getEdge(src, dest);
    if(!status.isOK()){
      Exceptions::handle_exception_map(status);
      return EdgeType();
    }
    return data;
  }
};
} // namespace CinderPeak
