#include "StorageEngine/AdjacencyList.hpp"
#include "StorageEngine/HybridCSR_COO.hpp"
#include "StorageEngine/Utils.hpp"
#include <iostream>
#include <memory>
#include <type_traits>
#include <vector>
namespace CinderPeak
{
  namespace PeakStore
  {
    const CinderPeak::GraphCreationOptions DEFAULT_GRAPH_OPTIONS(
        {CinderPeak::GraphCreationOptions::Directed,
         CinderPeak::GraphCreationOptions::SelfLoops});
    template <typename VertexType, typename EdgeType>
    class PeakStore
    {
    public:
      std::unique_ptr<HybridCSR_COO<VertexType, EdgeType>> hybrid_storage = nullptr;
      std::shared_ptr<GraphInternalMetadata> graph_metadata = nullptr;
      std::shared_ptr<GraphCreationOptions> create_options = nullptr;
      std::unique_ptr<AdjacencyList<VertexType, EdgeType>> adjacency_storage = nullptr;

      PeakStore(const GraphInternalMetadata &metadata, const GraphCreationOptions &options = DEFAULT_GRAPH_OPTIONS)
      {
        graph_metadata = std::make_shared<GraphInternalMetadata>(metadata);
        create_options = std::make_shared<GraphCreationOptions>(options);
        hybrid_storage =
            std::make_unique<HybridCSR_COO<VertexType, EdgeType>>(graph_metadata, create_options);
        adjacency_storage =
            std::make_unique<AdjacencyList<VertexType, EdgeType>>(graph_metadata, create_options);
      }
    };

  } // namespace PeakStore
} // namespace CinderPeak
