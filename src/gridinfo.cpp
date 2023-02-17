#include "gridinfo.hpp"


namespace offgrass
{

void GridInfo::clear()
{
  my_tiles.clear();
  opp_tiles.clear();
  neutral_tiles.clear();
  my_units.clear();
  opp_units.clear();
  my_recyclers.clear();
  opp_recyclers.clear();
}

void GridInfo::update(const Tile &tile)
{
  if (tile.owner == Player::ME) {
    my_tiles.emplace_back(std::cref(tile));
    if (tile.units > 0) {
      my_units.emplace_back(std::cref(tile));
    } else if (tile.recycler) {
      my_recyclers.emplace_back(std::cref(tile));
    }
  } else if (tile.owner == Player::OPP) {
    opp_tiles.emplace_back(std::cref(tile));
    if (tile.units > 0) {
      opp_units.emplace_back(std::cref(tile));
    } else if (tile.recycler) {
      opp_recyclers.emplace_back(std::cref(tile));
    }
  } else {
    neutral_tiles.emplace_back(std::cref(tile));
  }
}

} // namespace offgrass
