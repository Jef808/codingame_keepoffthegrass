#include "agent.hpp"

#include <iostream>

namespace offgrass
{

Agent::Agent(const Game &game) : m_game{game}
{
}

void Agent::output_actions(std::ostream &stream) const {
  if (m_actions.empty()) {
    stream << "WAIT";
  }
  else {
    for (std::string_view sv : m_actions) {
      stream << sv << ';';
    }
  }
  stream << std::endl;
}

} // namespace offgrass
