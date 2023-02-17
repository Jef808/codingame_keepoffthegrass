#ifndef __TILE_HPP
# define __TILE_HPP

#include <iosfwd>

#include "position.hpp"

namespace offgrass {

    enum class Player {
        NONE,
        ME,
        OPP
    };

    Player player_from_int(int input);

    std::string player_to_string(Player owner);

    struct Tile {
        unsigned long x;
        unsigned long y;
        Player owner {Player::NONE};
        int scrap_amount {0};
        int units {0};
        bool recycler {false};
        bool can_build {false};
        bool can_spawn {false};
        bool in_range_of_recycler {false};

        operator Position() const;

        bool operator==(const Tile&) const;
        friend std::istream& operator>>(std::istream&, Tile&);
        friend std::ostream& operator<<(std::ostream&, const Tile&);
    };

} // offgrass

#endif
