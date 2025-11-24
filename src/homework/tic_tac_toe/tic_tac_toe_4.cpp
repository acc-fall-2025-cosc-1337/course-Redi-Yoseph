#include "tic_tac_toe_4.h"

TicTacToe4::TicTacToe4()
    : TicTacToe(4)
{
}

bool TicTacToe4::check_column_win()
{
    // 4 columns
    for (int col = 0; col < 4; ++col)
    {
        int i = col;
        if (pegs[i] != " " &&
            pegs[i] == pegs[i + 4] &&
            pegs[i] == pegs[i + 8] &&
            pegs[i] == pegs[i + 12])
        {
            return true;
        }
    }
    return false;
}

bool TicTacToe4::check_row_win()
{
    for (int row = 0; row < 4; ++row)
    {
        int i = row * 4;
        if (pegs[i] != " " &&
            pegs[i] == pegs[i + 1] &&
            pegs[i] == pegs[i + 2] &&
            pegs[i] == pegs[i + 3])
        {
            return true;
        }
    }
    return false;
}

bool TicTacToe4::check_diagonal_win()
{
    // main diag 0‑5‑10‑15
    if (pegs[0] != " " &&
        pegs[0] == pegs[5] &&
        pegs[0] == pegs[10] &&
        pegs[0] == pegs[15])
    {
        return true;
    }

    // other diag 3‑6‑9‑12
    if (pegs[3] != " " &&
        pegs[3] == pegs[6] &&
        pegs[3] == pegs[9] &&
        pegs[3] == pegs[12])
    {
        return true;
    }

    return false;
}
