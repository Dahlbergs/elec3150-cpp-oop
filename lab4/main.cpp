#include <iostream>

#include "tictactoe.hpp"

int main() {

    TicTacToe game;

    while(game.total_turns_ < 9) {
        game.XTurn();
        game.DrawGameBoard();
        if (game.CheckWinner() == 10) {
            // game.DrawGameBoard();
            std::cout << "Player X wins" << std::endl;
            return 1;
        }

        if (game.CheckWinner() == 1) {
            // game.DrawGameBoard();
            std::cout << "Draw" << std::endl;
            return 1;
        }

        game.OTurn();
        game.DrawGameBoard();
        if (game.CheckWinner() == -10) {
            // game.DrawGameBoard();
            std::cout << "Player O wins" << std::endl;
            return 1;
        }

        if (game.CheckWinner() == 1) {
            // game.DrawGameBoard();
            std::cout << "Draw" << std::endl;
            return 1;
        }
    }

    game.DrawGameBoard();
    return 0;
}

