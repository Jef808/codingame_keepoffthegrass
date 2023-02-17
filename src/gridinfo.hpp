#ifndef GRIDINFO_HPP_
# define GRIDINFO_HPP_

#include <functional>
#include <vector>

#include "tile.hpp"

namespace offgrass {

struct GridInfo {
  std::vector<std::reference_wrapper<const Tile>> my_tiles;
  std::vector<std::reference_wrapper<const Tile>> opp_tiles;
  std::vector<std::reference_wrapper<const Tile>> neutral_tiles;
  std::vector<std::reference_wrapper<const Tile>> my_units;
  std::vector<std::reference_wrapper<const Tile>> opp_units;
  std::vector<std::reference_wrapper<const Tile>> my_recyclers;
  std::vector<std::reference_wrapper<const Tile>> opp_recyclers;

  void clear();
  void update(const Tile& tile);
};

} // offgrass

#endif // GRIDINFO_HPP_
