#include <iostream>

#include "game.hpp"
#include "agent.hpp"

using namespace offgrass;

int main(int argc, char *argv[])
{
    unsigned long width, height;
    std::cin >> width >> height;

    Game game{ width, height};
    Agent agent{ game };

    while (true) {
      game.update(std::cin);
      agent.output_actions(std::cout);
    }

    std::cout << "Hello world!" << std::endl;
}
