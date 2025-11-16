#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include <vector>
#include "tic_tac_toe.h"

class TicTacToeManager
{
public:
    void save_game(const TicTacToe& b);
    void get_winner_total(int& o, int& x, int& t) const;

private:
    std::vector<TicTacToe> games;
    int x_win{0};
    int o_win{0};
    int ties{0};

    void update_winner_count(std::string winner);
};

#endif
