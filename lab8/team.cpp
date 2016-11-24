#include "team.hpp"

#include <time.h>

#include <string>
#include <iostream>

Team::Team() {
    srand(time(NULL));
    createTeam();
}

void Team::createTeam() {
    std::string names[] = {"Larry Bird",
                           "Rajon Rando",
                           "Allen Iverson",
                           "Kevin Garnett",
                           "Paul Pierce"};

    int numbers[] = {33, 9, 3, 5, 34};

    int two_total = 0;
    int three_total = 0;

    const int TWO_MAX = 300;
    const int THREE_MAX = 200;

    for (int i = 0; i < 5; i++) {
        int two_acc = rand() % 100;
        int three_acc = rand() % 100;

        if (i > 3) {
            two_acc = TWO_MAX - two_total;
            two_total += two_acc;

            three_acc = THREE_MAX - three_total;
            three_total += three_acc;
        } else {
            if (two_total + two_acc > TWO_MAX) {
                two_acc /= 2;
                two_total += two_acc;
            } else {
                two_total += two_acc;
            }

            if (three_total + three_acc > THREE_MAX) {
                three_acc /= 2;
                three_total += three_acc;
            } else {
                three_total += three_acc;
            }
        }
        players.push_back(Player(names[i], numbers[i], two_acc, three_acc));
    }
}

void Team::takeShots() {
    int shot_total = 0;

    for (int i = 0; i < 100; i++) {
        int player = rand() % 5;

        shot_total += players[i % 5].takeShot(rand() % 3);
    }

    std::cout << "Shot total: " << shot_total << std::endl;
}
