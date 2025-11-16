#include "tic_tac_toe_manager.h"

void TicTacToeManager::save_game(const TicTacToe& b)
{
    games.push_back(b);
    update_winner_count(b.get_winner());
}

void TicTacToeManager::get_winner_total(int& o, int& x, int& t) const
{
    o = o_win;
    x = x_win;
    t = ties;
}

void TicTacToeManager::update_winner_count(std::string winner)
{
    if (winner == "X")
        x_win++;
    else if (winner == "O")
        o_win++;
    else
        ties++;
}
