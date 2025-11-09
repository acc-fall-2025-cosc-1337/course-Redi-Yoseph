#include "tic_tac_toe.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

bool TicTacToe::game_over()
{
    // Check for wins first
    if (check_row_win() || check_column_win() || check_diagonal_win())
    {
        set_winner();
        return true;
    }
    // Then check for tie
    else if (check_board_full())
    {
        winner = "C"; // C for "cat" (tie)
        return true;
    }
    // Game still in progress
    else
    {
        return false;
    }
}

void TicTacToe::start_game(const std::string& first_player)
{
    if (first_player != "X" && first_player != "O")
    {
        throw std::invalid_argument("first_player must be \"X\" or \"O\"");
    }

    player = first_player;
    winner = " "; // reset winner
    clear_board();
}

void TicTacToe::mark_board(int position)
{
    if (position < 1 || position > static_cast<int>(pegs.size()))
    {
        throw std::out_of_range("position must be 1..9");
    }

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

std::string TicTacToe::get_winner() const
{
    return winner;
}

void TicTacToe::display_board() const
{
    for (std::size_t i = 0; i < pegs.size(); i += 3)
    {
        std::cout << " " << pegs[i] << " | " << pegs[i + 1] << " | " << pegs[i + 2] << "\n";
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
    {
        if (p == " ")
        {
            return false;
        }
    }
    return true;
}

void TicTacToe::clear_board()
{
    std::fill(pegs.begin(), pegs.end(), " ");
}

bool TicTacToe::check_row_win() const
{
    // Rows: (0,1,2), (3,4,5), (6,7,8)
    for (int i = 0; i <= 6; i += 3)
    {
        if (pegs[i] != " " &&
            pegs[i] == pegs[i + 1] &&
            pegs[i] == pegs[i + 2])
        {
            return true;
        }
    }
    return false;
}

bool TicTacToe::check_column_win() const
{
    // Columns: (0,3,6), (1,4,7), (2,5,8)
    for (int i = 0; i < 3; ++i)
    {
        if (pegs[i] != " " &&
            pegs[i] == pegs[i + 3] &&
            pegs[i] == pegs[i + 6])
        {
            return true;
        }
    }
    return false;
}

bool TicTacToe::check_diagonal_win() const
{
    // Diagonal: (0,4,8)
    if (pegs[0] != " " &&
        pegs[0] == pegs[4] &&
        pegs[0] == pegs[8])
    {
        return true;
    }

    // Diagonal: (6,4,2)
    if (pegs[6] != " " &&
        pegs[6] == pegs[4] &&
        pegs[6] == pegs[2])
    {
        return true;
    }

    return false;
}

void TicTacToe::set_winner()
{
    // mark_board already called set_next_player(),
    // so `player` is now the NEXT player.
    // The winner is the previous one.
    winner = (player == "X") ? "O" : "X";
}
