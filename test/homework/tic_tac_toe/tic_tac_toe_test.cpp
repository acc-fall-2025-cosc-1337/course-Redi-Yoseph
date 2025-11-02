#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Game over only after 9th move (check after each mark)")
{
    TicTacToe game;
    game.start_game("X");

    const int moves[9] = {1,2,3,4,5,7,6,9,8};

    for (int i = 0; i < 9; ++i)
    {
        game.mark_board(moves[i]);
        REQUIRE(game.game_over() == (i == 8));
    }
}
