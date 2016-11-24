#include "player.hpp"

#include <vector>

class Team {
public:
    Team();

    void takeShots();

private:
    void createTeam();

    std::vector<Player> players;
};
