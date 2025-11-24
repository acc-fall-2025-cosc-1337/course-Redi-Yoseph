#include "tic_tac_toe_3.h"

TicTacToe3::TicTacToe3()
    : TicTacToe(3)
{
}

// These implementations are the 3x3 win‑checking
// logic from the previous homework.

bool TicTacToe3::check_column_win()
{
    // columns 0,1,2
    for (int col = 0; col < 3; ++col)
    {
        int i = col;
        if (pegs[i] != " " &&
            pegs[i] == pegs[i + 3] &&
            pegs[i] == pegs[i + 6])
        {
            return true;
        }
    }
    return false;
}

bool TicTacToe3::check_row_win()
{
    // rows 0,1,2
    for (int row = 0; row < 3; ++row)
    {
        int i = row * 3;
        if (pegs[i] != " " &&
            pegs[i] == pegs[i + 1] &&
            pegs[i] == pegs[i + 2])
        {
            return true;
        }
    }
    return false;
}

bool TicTacToe3::check_diagonal_win()
{
    // main diag 0‑4‑8
    if (pegs[0] != " " &&
        pegs[0] == pegs[4] &&
        pegs[0] == pegs[8])
    {
        return true;
    }

    // other diag 2‑4‑6
    if (pegs[2] != " " &&
        pegs[2] == pegs[4] &&
        pegs[2] == pegs[6])
    {
        return true;
    }

    return false;
}
