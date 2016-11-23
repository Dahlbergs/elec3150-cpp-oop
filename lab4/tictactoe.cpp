#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>

#include "tictactoe.hpp"

TicTacToe::TicTacToe()
    : total_turns_(0),
      player_x_(true),
      player_o_(false),
      is_winner_(false) {

    srand(time(0));

    for (int i = 0; i < 9; i++) {
        board_[i] = ' ';
    }
}

int TicTacToe::Minimax(bool player) {
    int winner = CheckWinner();

    if (winner != 0) {
        return winner;
    }

    int score = -1000;
    int move = -1;

    for (int i = 0; i < 9; i++) {
        if (board_[i] == ' ') {
            board_[i] = player ? 'X': 'O';

            int temp_score = -Minimax(!player);

            score = std::max(temp_score, score);

            board_[i] = ' ';
        }
    }

    // Draw
    if (move == -1) {
        return 0;
    }

    return move;
}

void TicTacToe::XTurn() {
    std::cout << "XTurn" << std::endl;

    int best_move = -1;
    int best_score = -1000;

    for (int i = 0; i < 9; i++) {
        if (board_[i] == ' ') {
            board_[i] = 'X';

            int move_score = Minimax(true);

            board_[i] = ' ';

            if (move_score > best_score) {
                best_score = move_score;
                best_move = i;
            }
        }
    }

    board_[best_move] = 'X';
    total_turns_++;
}

void TicTacToe::OTurn() {
    int move;

    /* Shamelessly borrowed from http://www.cplusplus.com/forum/beginner/52609/
     * because I've never seen a useful reason to use a do-while loop
     */

    do {
        move = rand() % 9;
    } while(move < 0 || move > 8 || board_[move] != ' ');

    board_[move] = 'O';
    total_turns_++;
}

int TicTacToe::CheckWinner() {
    int winning_combos[9][3] =
        { {0,1,2}, {3,4,5}, {6,7,8}, // Rows
          {0,3,6}, {1,4,7}, {2,5,8}, // Columns
          {0,4,8}, {2,4,6}           // Diagonals
        };

    for(int i = 0; i < 8; i++) {
        // X win
        if (board_[winning_combos[i][0]] == 'X' &&
            board_[winning_combos[i][1]] == 'X' &&
            board_[winning_combos[i][2]] == 'X') {
            return 10;
        }
        // O win
        else if (board_[winning_combos[i][0]] == 'O' &&
                   board_[winning_combos[i][1]] == 'O' &&
                   board_[winning_combos[i][2]] == 'O') {
            return -10;
        }
    }

    // Draw
    if (total_turns_ == 9) {
        return 1;
    }

    // Game still going
    return 0;
}

void TicTacToe::DrawGameBoard() {
    std::cout
        << board_[0] << " | " << board_[1] << " | " << board_[2] << std::endl
        << "--|---|--" << std::endl
        << board_[3] << " | " << board_[4] << " | " << board_[5] << std::endl
        << "--|---|--" << std::endl
        << board_[6] << " | " << board_[7] << " | " << board_[8] << std::endl
        << std::endl;
}
