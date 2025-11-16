#include "tic_tac_toe.h"

TicTacToe::TicTacToe()
{
    clear_board();
}

void TicTacToe::start_game(std::string first_player)
{
    if (first_player == "X" || first_player == "O")
    {
        player = first_player;
    }
    else
    {
        player = "X"; // default safety
    }

    winner = "";
    clear_board();
}

void TicTacToe::mark_board(int position)
{
    // Position is 1-9, internally index 0-8
    if (position >= 1 && position <= 9 && pegs[position - 1] == " ")
    {
        pegs[position - 1] = player;
        // don't change player here; game_over logic uses current player for winner
        set_next_player();
    }
}

bool TicTacToe::game_over()
{
    if (check_row_win() || check_column_win() || check_diagonal_win())
    {
        // The winner is the *previous* player (we flipped after mark_board)
        // So flip once to get the last player who actually marked
        set_next_player();
        set_winner(player);
        return true;
    }

    if (check_board_full())
    {
        set_winner("C");  // Cat / tie game
        return true;
    }

    return false;
}

void TicTacToe::clear_board()
{
    for (auto& p : pegs)
    {
        p = " ";
    }
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

bool TicTacToe::check_row_win()
{
    // rows: (0,1,2), (3,4,5), (6,7,8)
    for (int row = 0; row < 9; row += 3)
    {
        if (pegs[row] != " " &&
            pegs[row] == pegs[row + 1] &&
            pegs[row] == pegs[row + 2])
        {
            return true;
        }
    }
    return false;
}

bool TicTacToe::check_column_win()
{
    // columns: (0,3,6), (1,4,7), (2,5,8)
    for (int col = 0; col < 3; ++col)
    {
        if (pegs[col] != " " &&
            pegs[col] == pegs[col + 3] &&
            pegs[col] == pegs[col + 6])
        {
            return true;
        }
    }
    return false;
}

bool TicTacToe::check_diagonal_win()
{
    // diagonals: (0,4,8) and (2,4,6)
    if (pegs[0] != " " && pegs[0] == pegs[4] && pegs[0] == pegs[8])
    {
        return true;
    }

    if (pegs[2] != " " && pegs[2] == pegs[4] && pegs[2] == pegs[6])
    {
        return true;
    }

    return false;
}

bool TicTacToe::check_board_full()
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

void TicTacToe::set_winner(const std::string& winr)
{
    winner = winr;
}

// ===================== STREAM OPERATORS =====================

std::ostream& operator<<(std::ostream& out, const TicTacToe& game)
{
    // Display 3x3 board
    for (int i = 0; i < 9; i += 3)
    {
        out << " " << game.pegs[i]     << " | "
            << game.pegs[i + 1] << " | "
            << game.pegs[i + 2] << "\n";
        if (i < 6)
        {
            out << "---+---+---\n";
        }
    }
    out << "\n";
    return out;
}

std::istream& operator>>(std::istream& in, TicTacToe& game)
{
    int position;
    std::cout << "Player " << game.player << ", enter position (1-9): ";
    in >> position;
    game.mark_board(position);
    return in;
}
