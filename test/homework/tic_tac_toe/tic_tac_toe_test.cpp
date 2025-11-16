#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

TEST_CASE("TicTacToe winner must be X, O, or C")
{
    TicTacToe game;
    game.start_game("X");

    // X wins across top row: positions 1,2,3
    game.mark_board(1); // X
    game.mark_board(4); // O
    game.mark_board(2); // X
    game.mark_board(5); // O
    game.mark_board(3); // X

    REQUIRE(game.game_over());
    auto winner = game.get_winner();
    REQUIRE((winner == "X" || winner == "O" || winner == "C"));
}

TEST_CASE("TicTacToeManager tracks X, O, and tie totals")
{
    TicTacToeManager manager;

    // Game 1: X wins
    TicTacToe game1;
    game1.start_game("X");
    game1.mark_board(1); // X
    game1.mark_board(4); // O
    game1.mark_board(2); // X
    game1.mark_board(5); // O
    game1.mark_board(3); // X (X wins top row)
    REQUIRE(game1.game_over());
    REQUIRE(game1.get_winner() == "X");
    manager.save_game(game1);

    // Game 2: O wins
    TicTacToe game2;
    game2.start_game("O");
    game2.mark_board(1); // O
    game2.mark_board(4); // X
    game2.mark_board(2); // O
    game2.mark_board(5); // X
    game2.mark_board(3); // O (O wins top row)
    REQUIRE(game2.game_over());
    REQUIRE(game2.get_winner() == "O");
    manager.save_game(game2);

    // Game 3: tie (C)
    TicTacToe game3;
    game3.start_game("X");
    // Fill board with no winner
    game3.mark_board(1); // X
    game3.mark_board(2); // O
    game3.mark_board(3); // X
    game3.mark_board(5); // O
    game3.mark_board(4); // X
    game3.mark_board(6); // O
    game3.mark_board(8); // X
    game3.mark_board(7); // O
    game3.mark_board(9); // X

    REQUIRE(game3.game_over());
    REQUIRE(game3.get_winner() == "C");
    manager.save_game(game3);

    int x = 0, o = 0, t = 0;
    manager.get_winner_total(o, x, t);

    REQUIRE(x == 1);
    REQUIRE(o == 1);
    REQUIRE(t == 1);
}
