#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include "tic_tac_toe.h"

class TicTacToeManager
{
public:
    void save_game(std::unique_ptr<TicTacToe>& game);
    void get_winner_totals(int& x, int& o, int& t) const;

    friend std::ostream& operator<<(std::ostream& out,
                                    const TicTacToeManager& manager);

private:
    std::vector<std::unique_ptr<TicTacToe>> games;
    int o_wins{0};
    int ties{0};
    int x_wins{0};

    void update_winner_count(std::string winner);
};

#endif
