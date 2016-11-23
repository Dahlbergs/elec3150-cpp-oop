#include <vector>

class TicTacToe {
public:
    TicTacToe();

    void XTurn();
    void OTurn();

    int Minimax(bool player);

    int CheckWinner();
    void DrawGameBoard();

    int total_turns_;
private:
    const bool player_x_;
    const bool player_o_;

    char board_[9];
    bool is_winner_;

};
