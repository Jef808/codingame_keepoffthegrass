
#include "grid.hpp"
#include "gridinfo.hpp"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <stdexcept>

namespace offgrass
{

Grid::Grid(unsigned long width, unsigned long height) : m_width{width}, m_height{height}, max_index{width * height}
{
    std::generate_n(std::back_inserter(m_tiles), max_index, [width, n = 0]() mutable {
        const unsigned long _x = n % width;
        const unsigned long _y = n / width;
        ++n;
        return Tile{
            .x = _x,
            .y = _y,
        };
    });
}

unsigned long Grid::from_xy_to_index(unsigned long x, unsigned long y) const
{
    return x + y * m_width;
}

unsigned long Grid::from_position_to_index(const Position &position) const
{
    return position.x + position.y * m_width;
}

Position Grid::from_index_to_position(unsigned long idx) const
{
  return m_tiles.at(idx); // Use implicit conversion from Tile to Position
}

void Grid::update(std::istream &stream)
{
    m_info.clear();
    for (int y = 0; y < m_height; ++y)
    {
        for (int x = 0; x < m_width; ++x)
        {
            Tile &tile = m_tiles[from_xy_to_index(x, y)];
            stream >> tile;
            m_info.update(tile);
        }
    }
}

const std::vector<Tile> &Grid::tiles() const
{
    return m_tiles;
}
const GridInfo &Grid::info() const
{
    return m_info;
}

} // namespace offgrass
