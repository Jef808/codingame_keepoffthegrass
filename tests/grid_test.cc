#include "grid.hpp"

#include <algorithm>
#include <sstream>

#include "gtest/gtest.h"

#include "position.hpp"
#include "tile.hpp"

using namespace offgrass;

TEST(GridConstructorTest, TilesVectorPopulatedWithCorrectPositions) {
  const unsigned long width = 3;
  const unsigned long height = 1;

  Grid grid{ width, height };

  EXPECT_EQ(grid.tiles().size(), 3);

  std::vector<Position> positions;
  std::transform(
      grid.tiles().begin(),
      grid.tiles().end(),
      std::back_inserter(positions),
      [](const Tile& tile) {
        return (Position)tile;
      });
  std::vector<Position> expected_positions{ {0, 0}, {1, 0}, {2, 0} };

  EXPECT_EQ(positions, expected_positions);
}

TEST(GridUpdateTest, TilesVectorPopulatedCorrectly) {
  const unsigned long width = 3;
  const unsigned long height = 1;
  const int owner_1 = 1;
  const int owner_2 = 0;
  const int owner_3 = -1;
  const int scrap_amount_1 = 10;
  const int scrap_amount_2 = 5;
  const int scrap_amount_3 = 7;
  const int units_1 = 7;
  const int units_2 = 8;
  const int units_3 = 9;
  const int recycler_1 = 0;
  const int recycler_2 = 0;
  const int recycler_3 = 1;
  const int can_build_1 = 1;
  const int can_build_2 = 0;
  const int can_build_3 = 1;
  const int can_spawn_1 = 0;
  const int can_spawn_2 = 1;
  const int can_spawn_3 = 1;
  const int in_range_of_recycler_1 = 1;
  const int in_range_of_recycler_2 = 1;
  const int in_range_of_recycler_3 = 0;

  std::stringstream ss;
  ss << owner_1 << ' '
     << scrap_amount_1 << ' '
     << units_1 << ' '
     << recycler_1 << ' '
     << can_build_1 << ' '
     << can_spawn_1 << ' '
     << in_range_of_recycler_1 << '\n';
  ss << owner_2 << ' '
     << scrap_amount_2 << ' '
     << units_2 << ' '
     << recycler_2 << ' '
     << can_build_2 << ' '
     << can_spawn_2 << ' '
     << in_range_of_recycler_2 << '\n';
  ss << owner_3 << ' '
     << scrap_amount_3 << ' '
     << units_3 << ' '
     << recycler_3 << ' '
     << can_build_3 << ' '
     << can_spawn_3 << ' '
     << in_range_of_recycler_3 << '\n';

  std::vector<Tile> tiles_expected {
    {
      0, 0, player_from_int(owner_1), scrap_amount_1, units_1, recycler_1, can_build_1, can_spawn_1, in_range_of_recycler_1
    },
    {
      1, 0, player_from_int(owner_2), scrap_amount_2, units_2, recycler_2, can_build_2, can_spawn_2, in_range_of_recycler_2
    },
    {
      2, 0, player_from_int(owner_3), scrap_amount_3, units_3, recycler_3, can_build_3, can_spawn_3, in_range_of_recycler_3
    }
  };

  Grid grid{ width, height };
  grid.update(ss);

  for (int i = 0; i < 3; ++i) {
    EXPECT_EQ(grid.tiles()[i], tiles_expected[i]);
  }
}
