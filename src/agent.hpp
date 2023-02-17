#ifndef AGENT_H_
#define AGENT_H_

#include <string>
#include <vector>

#include "game.hpp"

namespace offgrass {

class Agent {
public:
  Agent(const Game& game);

  void output_actions(std::ostream& out) const;

private:
  const Game& m_game;
  std::vector<std::string> m_actions;
};

} // namespace offgrass

#endif // AGENT_H_
