#include "player.hpp"

#include <stdlib.h>

#include <iostream>

Player::Player(std::string name, int number, int two_accuracy, int three_accuracy)
    : name(name),
      number(number),
      two_accuracy(two_accuracy),
      three_accuracy(three_accuracy) {}

/* @param shot_type Whether the shot is a two or three point shot */
int Player::takeShot(int shot_type) {
    int shot = 0;

    if (shot_type % 2 == 1) {
        if (rand() % 100 < (100 - two_accuracy)) {
            shot = 2;
        }
    } else {
        if(rand() % 100 < (100 - three_accuracy)) {
            shot =  3;
        }
    }

    return shot;
}

void Player::setTwoPointAccuracy(int acc) {
    two_accuracy = acc;

    if (acc < 0 || acc > 100) {
        std::cout << "Invalid two point accuracy, must be (1-100)" << std::endl;
        two_accuracy = -1;
    }
}

void Player::setThreePointAccuracy(int acc) {
    three_accuracy = acc;

    if (acc < 0 || acc > 100) {
        std::cout << "Invalid three point accuracy, must be (1-100)" << std::endl;
        three_accuracy = -1;
    }
}
