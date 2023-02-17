#include "tile.hpp"

#include <sstream>

#include "gtest/gtest.h"

// Tests Tile istream input.

using namespace offgrass;

TEST(TileTestIstream, DefaultTilePopulatedCorrectly) {
    std::string stream_content = "-1 0 0 0 0 0 0";
    std::stringstream ss;
    ss << stream_content;

    Tile tile_default{ 2, 3 };
    Tile tile_populated{ 2, 3 };

    ss >> tile_populated;

    EXPECT_EQ(tile_default, tile_populated);
}

TEST(TileTestIStream, TilesPopulatedCorrectly) {

    const int owner = 1;
    const int scrap_amount = 10;
    const int units = 7;
    const int recycler = 0;
    const int can_build = 1;
    const int can_spawn = 1;
    const int in_range_of_recycler = 0;

    std::stringstream ss;

    for (const int item : { owner, scrap_amount, units, recycler, can_build, can_spawn}) {
        ss << item << ' ';
    }
    ss << in_range_of_recycler << '\n';

    Tile tile { 2, 3 };

    Tile expected_tile{2, 3};
    expected_tile.owner = Player::ME;
    expected_tile.scrap_amount = scrap_amount;
    expected_tile.units = units;
    expected_tile.recycler = false;
    expected_tile.can_build = true;
    expected_tile.can_spawn = true;
    expected_tile.in_range_of_recycler = false;

    ss >> tile;

    EXPECT_EQ(tile, expected_tile);
}

TEST(TileTestIStream, TilesPopulatedCorrectlyWhenRepopulated) {

    const int owner_1 = 1;
    const int owner_2 = 0;
    const int owner_3 = -1;
    const int scrap_amount = 10;
    const int units = 7;
    const int recycler = 0;
    const int can_build = 1;
    const int can_spawn = 1;
    const int in_range_of_recycler = 0;

    Tile tile { 2, 3 };

    Tile expected_tile = {
        2,
        3,
        Player::ME,
        scrap_amount,
        units,
        recycler,
        can_build,
        can_spawn,
        in_range_of_recycler
    };

    std::stringstream ss;

    for (const int item : { owner_1, scrap_amount, units, recycler, can_build, can_spawn}) {
        ss << item << ' ';
    }
    ss << in_range_of_recycler << '\n';
    for (const int item : { owner_2, scrap_amount, units, recycler, can_build, can_spawn}) {
        ss << item << ' ';
    }
    ss << in_range_of_recycler << '\n';
    for (const int item : { owner_3, scrap_amount, units, recycler, can_build, can_spawn}) {
        ss << item << ' ';
    }
    ss << in_range_of_recycler << '\n';

    ss >> tile;
    EXPECT_EQ(tile, expected_tile);

    ss >> tile;
    expected_tile.owner = Player::OPP;
    EXPECT_EQ(tile, expected_tile);

    ss >> tile;
    expected_tile.owner = Player::NONE;
    EXPECT_EQ(tile, expected_tile);
}

// Test tile implicit conversion to Position

TEST(TilePosition, TileCanImplicitlyConvertToPosition) {
    const auto tile_to_position_string = [](const Position& position) {
        std::stringstream ss;
        ss << "x: " << position.x << ", y: " << position.y;
        return ss.str();
    };

    Tile tile{2, 3, };
    std::string position_string;

    EXPECT_NO_THROW(position_string = tile_to_position_string(tile));
    EXPECT_EQ(position_string, "x: 2, y: 3");
}
