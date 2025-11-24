#include "tic_tac_toe_manager.h"

void TicTacToeManager::save_game(std::unique_ptr<TicTacToe>& game)
{
    // first, update winner totals
    update_winner_count(game->get_winner());

    // move the unique_ptr into the vector
    games.push_back(std::move(game));
}

void TicTacToeManager::get_winner_totals(int& x, int& o, int& t) const
{
    x = x_wins;
    o = o_wins;
    t = ties;
}

void TicTacToeManager::update_winner_count(std::string winner)
{
    if (winner == "X")
    {
        ++x_wins;
    }
    else if (winner == "O")
    {
        ++o_wins;
    }
    else if (winner == "C")
    {
        ++ties;
    }
}

std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager)
{
    for (const auto& game : manager.games)
    {
        out << *game << "\n";
    }

    int x, o, t;
    manager.get_winner_totals(x, o, t);

    out << "X wins: " << x << "\n";
    out << "O wins: " << o << "\n";
    out << "Ties:   " << t << "\n";

    return out;
}
