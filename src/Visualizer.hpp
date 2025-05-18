#pragma once
#include "ArialFontDataEmbed.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <type_traits>
#include <cmath> // for std::cos, std::sin

namespace CinderPeak
{
  template <typename VertexType, typename EdgeType>
  class GraphVisualizer
  {
  public:
    using AdjListType = std::unordered_map<VertexType, std::vector<std::pair<VertexType, EdgeType>>, VertexHasher<VertexType>>;

    explicit GraphVisualizer(const AdjListType &adj_list)
        : _adj_list(adj_list) {}

    void visualize()
    {
      sf::RenderWindow window(sf::VideoMode({1200, 800}), "Graph Visualization");

      while (window.isOpen())
      {
        while (auto event = window.pollEvent())
        {
          if (event->is<sf::Event::Closed>())
            window.close();
        }

        window.clear(sf::Color::White);
        window.display();
      }
    }

  private:
    const AdjListType &_adj_list;
  };

} // namespace CinderPeak
