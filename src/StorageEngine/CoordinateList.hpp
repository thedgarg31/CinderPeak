#include "Utils.hpp"

namespace CinderPeak {
namespace PeakStore {
template <typename VertexType, typename EdgeType> class CoordinateList {
public:
  std::shared_ptr<GraphInternalMetadata> graph_metadata = nullptr;
  std::shared_ptr<GraphCreationOptions> create_options = nullptr;
  std::unique_ptr<AdjacencyList<VertexType, EdgeType>> adjacency_storage =
      nullptr;
  CoordinateList(const std::shared_ptr<GraphInternalMetadata>& metadata,
  const std::shared_ptr<GraphCreationOptions>& options,
  const std::): graph_metadata(metadata), create_options(options), adjacency_storage(adj_list){

  }
};
} // namespace PeakStore

} // namespace CinderPeak
