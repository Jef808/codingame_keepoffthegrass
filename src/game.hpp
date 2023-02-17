#ifndef GAME_H_
#define GAME_H_

#include <iosfwd>

#include "grid.hpp"

namespace offgrass {

class Game {
static constexpr int INITIAL_MATTER = 10;
 public:
  Game(unsigned long width, unsigned long height);

  void update(std::istream& stream);

  [[nodiscard]] int my_matter() const;
  [[nodiscard]] int opp_matter() const;
  [[nodiscard]] unsigned int number_of_turns() const;
  [[nodiscard]] const Grid& grid() const;


private:
  int m_my_matter{ INITIAL_MATTER };
  int m_opp_matter{ INITIAL_MATTER };
  unsigned int m_number_of_turns{ 0 };
  Grid m_grid;
};

};

#endif // GAME_H_
