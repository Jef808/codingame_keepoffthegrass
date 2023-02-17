#include "game.hpp"

#include <iostream>

namespace offgrass
{

Game::Game(unsigned long width, unsigned long height)
    : m_grid{ width, height }
{}

void Game::update(std::istream& stream) {
  stream >> m_my_matter >> m_opp_matter;
  m_grid.update(stream);
  ++m_number_of_turns;
}

int Game::my_matter() const { return m_my_matter; }
int Game::opp_matter() const { return m_opp_matter; }
unsigned int Game::number_of_turns() const { return m_number_of_turns; }
const Grid& Game::grid() const { return m_grid; }

} // namespace offgrass
