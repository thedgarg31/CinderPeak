#include <iostream>
#include "PeakStore.hpp"
#include "GraphMatrix.hpp"
using namespace CinderPeak::PeakStore;
using namespace CinderPeak;
int main()
{
  GraphCreationOptions options({GraphCreationOptions::Directed,
                                GraphCreationOptions::Weighted,
                                GraphCreationOptions::SelfLoops});
  GraphInternalMetadata metadata;

  GraphMatrix<int, int> gm(options);
  gm.greet();
  gm.addVertex(1);
  return 0;

}