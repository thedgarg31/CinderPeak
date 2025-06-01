# CinderPeak: A Modern C++ Graph Library (Work in Progress)

CinderPeak is a fast and efficient, open-source C++ graph library designed to handle directed, undirected, and mixed graphs with customizable vertex and edge types. Built with modern C++ (C++17/C++20), it offers a flexible, templated API for graph manipulation and analysis. The library includes an integrated visualization engine powered by SFML, enabling intuitive graph rendering for visual insights. CinderPeak is thread-safe, portable, and optimized for integration into larger projects, making it ideal for graph theory applications, data analysis, and network modeling.

## Key Features
- **Flexible Graph Representations**: Supports adjacency lists, adjacency matrices, and hybrid CSR/COO formats for efficient storage and computation.
- **Customizable and Templated**: Fully templated design allows users to define custom vertex and edge types for maximum flexibility.
- **Visualization Engine**: Integrated SFML-based visualizer for rendering graphs in real-time.
- **Thread Safety**: Designed to work seamlessly with multi-threaded applications, ensuring safe access to shared resources.
- **High Performance**: Leverages modern C++ features like smart pointers, STL containers, and optimized algorithms for fast execution.
- **Comprehensive Testing**: Built with Google Test (GTest) to ensure reliability and robustness across features.
- **Documentation**: Extensive documentation hosted with Docusaurus, including usage guides, examples, and API references.

## Development Notice

CinderPeak is actively under development, with ongoing enhancements to its documentation, CI/CD, issues and pull requests, and overall structure. We are committed to delivering a polished and comprehensive release. The stable version, including complete documentation and refined functionalities, is scheduled to be available by **June 12, 2025**. Thank you for your patience and support as we continue to improve the library.

## Project Structure
```
/CinderPeak
├── CMakeLists.txt              # Build system configuration
├── docs                        # Docusaurus documentation
│   ├── examples
│   │   └── GraphMatrixExample.md  # Example usage for GraphMatrix
│   ├── GraphList.md            # Adjacency List documentation
│   ├── GraphMatrix.md          # Adjacency Matrix documentation
│   ├── index.md                # Main documentation page
│   ├── installation.md         # Installation guide
│   └── usage.md                # Usage guide
├── examples                    # Sample code demonstrating usage
│   ├── CMakeLists.txt          # Build config for examples
│   ├── extras
│   │   ├── COOExample.cpp      # Coordinate List example
│   │   ├── CSRExample.cpp      # Compressed Sparse Row example
│   │   ├── LogExample.cpp      # Logging utility example
│   │   └── PeakExample.cpp     # General CinderPeak usage example
│   ├── ListExample1.cpp        # Adjacency List example
│   ├── MatrixExample.cpp       # Adjacency Matrix example
│   └── PrimitiveGraph.cpp      # Basic graph example
├── src                         # Source files
│   ├── ArialFontDataEmbed.hpp  # Embedded font data for visualization
│   ├── CinderExceptions.hpp    # Custom exception handling
│   ├── CinderPeak.hpp          # Main API entry point
│   ├── GraphList.hpp           # Adjacency List implementation
│   ├── GraphMatrix.hpp         # Adjacency Matrix implementation
│   ├── PeakLogger.hpp          # Logging utility
│   ├── PeakStore.hpp           # Core storage engine
│   ├── StorageEngine
│   │   ├── AdjacencyList.hpp   # Adjacency List storage
│   │   ├── CoordinateList.hpp  # Coordinate List storage
│   │   ├── ErrorCodes.hpp      # Error handling codes
│   │   ├── GraphContext.hpp    # Graph context management
│   │   ├── HybridCSR_COO.hpp   # Hybrid CSR/COO storage
│   │   └── Utils.hpp           # Utility functions
│   ├── StorageInterface.hpp    # Storage interface definition
│   └── Visualizer.hpp          # SFML-based visualization engine
├── tests                       # Unit tests
│   ├── AdjacencyShard.cpp      # Tests for adjacency list
│   ├── CoordinateShard.cpp     # Tests for coordinate list
│   ├── HybridShard.cpp         # Tests for hybrid CSR/COO
│   └── tests.cpp               # Main test suite
├── README.md                   # Project overview and setup
└── LICENSE                     # License file
```

## Getting Started
1. **Installation**: Follow the [installation guide](docs/installation.md) to set up CinderPeak with CMake.
2. **Usage**: Check the [usage guide](docs/usage.md) for API details and the [examples](examples/) directory for sample code.
3. **Documentation**: Explore the full documentation hosted with Docusaurus in the [docs](docs/) directory.
4. **Contributing**: Contributions are welcome! See the [CONTRIBUTING.md](CONTRIBUTING.md) file for guidelines.

## Build System
CinderPeak uses CMake for cross-platform compilation, ensuring seamless integration across different environments. The build system is configured to support both development and production workflows, with separate targets for tests, examples, and benchmarks.

## Technology Stack
- **C++17/C++20**: Leverages modern C++ features like smart pointers, templates, and concepts for performance and flexibility.
- **SFML**: Powers the visualization engine for rendering graphs.
- **Google Test**: Ensures robust unit testing for all features.
- **Docusaurus**: Hosts comprehensive documentation with examples and API references.

## Why CinderPeak?
CinderPeak stands out for its balance of performance, flexibility, and ease of use. Whether you're building complex network models, analyzing graph-based data, or visualizing relationships, CinderPeak provides a robust and intuitive solution. Its open-source nature encourages community contributions, and its modular design makes it easy to extend for specialized use cases.


## Community
Join the CinderPeak community on [GitHub](https://github.com/SharonIV0X86/CinderPeak) to report issues, suggest features, or contribute code. Check out the [examples](examples/) directory to see CinderPeak in action!
