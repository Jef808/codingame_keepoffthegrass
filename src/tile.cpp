#include "tile.hpp"

#include <iostream>

namespace offgrass {

    Player player_from_int(int input) {
      return input == 1 ? Player::ME
          : input == 0 ? Player::OPP
          : Player::NONE;
    }

    std::string player_to_string(Player owner) {
      return owner == Player::ME ? "ME"
          : owner == Player::OPP? "OPP"
          : "NONE";
    }

    Tile::operator Position() const {
        return Position { x, y };
    }

    std::istream& operator>>(std::istream& stream, Tile& tile) {
        int _owner;
        stream  >> _owner
            >> tile.scrap_amount
            >> tile.units
            >> tile.recycler
            >> tile.can_build
            >> tile.can_spawn
            >> tile.in_range_of_recycler;
        tile.owner = player_from_int(_owner);
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, const Tile& tile) {
        return stream << std::boolalpha
            << "{\n"
            << "  \"x\": " << tile.x << ",\n"
            << "  \"y\": " << tile.y << ",\n"
            << "  \"owner\": " << player_to_string(tile.owner) << ",\n"
            << "  \"scrap_amount\": " << tile.scrap_amount << ",\n"
            << "  \"units\": " << tile.units << ",\n"
            << "  \"recycler\": " << tile.recycler << ",\n"
            << "  \"can_build\": " << tile.can_build << ",\n"
            << "  \"can_spawn\": " << tile.can_spawn << ",\n"
            << "  \"in_range_of_recycler\": " << tile.in_range_of_recycler << "\n"
            << "}";
    }

    bool Tile::operator==(const Tile& other) const {
        return x == other.x
            && y == other.y
            && owner == other.owner
            && scrap_amount == other.scrap_amount
            && units == other.units
            && recycler == other.recycler
            && can_build == other.can_build
            && can_spawn == other.can_spawn
            && in_range_of_recycler == other.in_range_of_recycler;
    }
}
