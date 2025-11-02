#include "tic_tac_toe.h"
#include <iostream>
#include <stdexcept>

bool TicTacToe::game_over() const
{
    return check_board_full();
}

void TicTacToe::start_game(const std::string& first_player)
{
    if (first_player != "X" && first_player != "O")
        throw std::invalid_argument("first_player must be \"X\" or \"O\"");
    player = first_player;
    clear_board();
}

void TicTacToe::mark_board(int position)
{
    if (position < 1 || position > static_cast<int>(pegs.size()))
        throw std::out_of_range("position must be 1..9");

    if (pegs[position - 1] == " ")
    {
        pegs[position - 1] = player;
        set_next_player();
    }
}

std::string TicTacToe::get_player() const
{
    return player;
}

void TicTacToe::display_board() const
{
    for (std::size_t i = 0; i < pegs.size(); i += 3)
    {
        std::cout << " " << pegs[i] << " | " << pegs[i+1] << " | " << pegs[i+2] << "\n";
        if (i < 6) std::cout << "---+---+---\n";
    }
}

void TicTacToe::set_next_player()
{
    player = (player == "X") ? "O" : "X";
}

bool TicTacToe::check_board_full() const
{
    for (const auto& p : pegs)
        if (p == " ") return false;
    return true;
}

void TicTacToe::clear_board()
{
    std::fill(pegs.begin(), pegs.end(), " ");
}
