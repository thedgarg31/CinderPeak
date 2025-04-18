#include <iostream>
#include "PeakStore.hpp"
#include "GraphMatrix.hpp"
using namespace CinderPeak::PeakStore;
using namespace CinderPeak;

class Vertex : public CinderVertex
{
  int data;

public:
  Vertex() {}
  
};
class Edge : public CinderEdge
{
  int dd;

public:
  Edge() {}
};
int main()
{
  GraphCreationOptions options({GraphCreationOptions::Directed,
                                GraphCreationOptions::Weighted,
                                GraphCreationOptions::SelfLoops});
  GraphInternalMetadata metadata;

  GraphMatrix<Vertex, Edge> gm(options);

  Vertex v;
  gm.greet();
  gm.addVertex(v);
  gm.addVertex(v);
  // Vertex vv(v);
  return 0;
}