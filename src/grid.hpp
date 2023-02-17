#ifndef __GRID_HPP
# define __GRID_HPP

#include <functional>
#include <iosfwd>
#include <vector>

#include "gridinfo.hpp"
#include "position.hpp"
#include "tile.hpp"

namespace offgrass {

class Grid {
public:
    Grid(unsigned long width, unsigned long height);

    // To update data each turn
    void update(std::istream&);

    // Convert from (x, y) coordinates to index in vector of tiles
    [[nodiscard]] unsigned long from_xy_to_index(unsigned long x, unsigned long y) const;

    // Convert from Position object to index in vector of tiles
    [[nodiscard]] unsigned long from_position_to_index(const Position& position) const;

    // Convert from index in vector of tiles to Position object
    [[nodiscard]] Position from_index_to_position(unsigned long idx) const;

    // Getters
    [[nodiscard]] const std::vector<Tile>& tiles() const;
    [[nodiscard]] const GridInfo& info() const;

private:
    const unsigned long m_width;
    const unsigned long m_height;
    const unsigned long max_index;
    std::vector<Tile> m_tiles;
    GridInfo m_info;
};

} // namespace offgrass

#endif
