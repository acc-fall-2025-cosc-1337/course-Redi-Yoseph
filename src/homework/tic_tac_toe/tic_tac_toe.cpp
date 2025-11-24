#include "tic_tac_toe.h"
#include <cmath>

TicTacToe::TicTacToe(int size)
    : pegs(size * size, " ")
{
}

void TicTacToe::start_game(std::string first_player)
{
    player = first_player;
    clear_board();
}

void TicTacToe::mark_board(int position)
{
    // positions are 1-based
    if (position >= 1 && static_cast<std::size_t>(position) <= pegs.size())
    {
        pegs[position - 1] = player;
        set_next_player();
    }
}

void TicTacToe::clear_board()
{
    for (auto& peg : pegs)
    {
        peg = " ";
    }
    winner = " ";
}

bool TicTacToe::game_over()
{
    if (check_column_win() || check_row_win() || check_diagonal_win())
    {
        // determine winner from the board (don't rely on current player)
        std::string win = find_winner();
        if (win != " ")
        {
            set_winner(win);
        }
        return true;
    }
    else if (check_board_full())
    {
        winner = "C"; // tie / cat game
        return true;
    }

    return false;
}

bool TicTacToe::check_board_full()
{
    for (const auto& peg : pegs)
    {
        if (peg == " ")
        {
            return false;
        }
    }
    return true;
}

void TicTacToe::set_next_player()
{
    if (player == "X")
    {
        player = "O";
    }
    else
    {
        player = "X";
    }
}

void TicTacToe::set_winner(std::string winner_value)
{
    winner = winner_value;
}

// base versions now do nothing (3x3 / 4x4 logic lives in derived classes)
bool TicTacToe::check_column_win()
{
    return false;
}

bool TicTacToe::check_row_win()
{
    return false;
}

bool TicTacToe::check_diagonal_win()
{
    return false;
}

std::ostream& operator<<(std::ostream& out, const TicTacToe& game)
{
    int size = static_cast<int>(std::sqrt(game.pegs.size()));

    for (int row = 0; row < size; ++row)
    {
        for (int col = 0; col < size; ++col)
        {
            out << game.pegs[row * size + col];
            if (col < size - 1)
            {
                out << " | ";
            }
        }
        out << "\n";
        if (row < size - 1)
        {
            out << std::string(size * 4 - 3, '-') << "\n";
        }
    }
    return out;
}

std::istream& operator>>(std::istream& in, TicTacToe& game)
{
    int position;
    std::cout << "Enter position: ";
    in >> position;
    game.mark_board(position);
    return in;
}

// Inspect the board to determine which player (if any) has a winning line.
// Returns "X", "O", or " " when no winner is found.
std::string TicTacToe::find_winner()
{
    int size = static_cast<int>(std::sqrt(pegs.size()));

    // check rows
    for (int r = 0; r < size; ++r)
    {
        int start = r * size;
        const std::string& first = pegs[start];
        if (first == " ") continue;
        bool all_same = true;
        for (int c = 1; c < size; ++c)
        {
            if (pegs[start + c] != first)
            {
                all_same = false;
                break;
            }
        }
        if (all_same) return first;
    }

    // check columns
    for (int c = 0; c < size; ++c)
    {
        const std::string& first = pegs[c];
        if (first == " ") continue;
        bool all_same = true;
        for (int r = 1; r < size; ++r)
        {
            if (pegs[r * size + c] != first)
            {
                all_same = false;
                break;
            }
        }
        if (all_same) return first;
    }

    // main diagonal
    const std::string& diag_first = pegs[0];
    if (diag_first != " ")
    {
        bool all_same = true;
        for (int i = 1; i < size; ++i)
        {
            if (pegs[i * size + i] != diag_first)
            {
                all_same = false;
                break;
            }
        }
        if (all_same) return diag_first;
    }

    // other diagonal
    const std::string& other_first = pegs[size - 1];
    if (other_first != " ")
    {
        bool all_same = true;
        for (int i = 1; i < size; ++i)
        {
            if (pegs[i * size + (size - 1 - i)] != other_first)
            {
                all_same = false;
                break;
            }
        }
        if (all_same) return other_first;
    }

    return " ";
}
