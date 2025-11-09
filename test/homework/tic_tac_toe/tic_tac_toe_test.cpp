#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "tic_tac_toe.h"

// Test first player set to X
TEST_CASE("Test first player set to X")
{
    TicTacToe game;
    game.start_game("X");
    REQUIRE(game.get_player() == "X");
}

// Test first player set to O
TEST_CASE("Test first player set to O")
{
    TicTacToe game;
    game.start_game("O");
    REQUIRE(game.get_player() == "O");
}

// Tie game: 9 moves, no winner, winner == "C"
TEST_CASE("Test game over if 9 slots are selected - tie")
{
    TicTacToe game;
    game.start_game("X");

    const int moves[9] = {1,2,3,4,5,7,6,9,8};

    for (int i = 0; i < 9; ++i)
    {
        game.mark_board(moves[i]);
        if (i < 8)
        {
            REQUIRE(game.game_over() == false);
        }
        else
        {
            REQUIRE(game.game_over() == true);
            REQUIRE(game.get_winner() == "C");
        }
    }
}

// Win by first column (1,4,7)
TEST_CASE("Test win by first column")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1); // X
    REQUIRE(game.game_over() == false);

    game.mark_board(2); // O
    REQUIRE(game.game_over() == false);

    game.mark_board(4); // X
    REQUIRE(game.game_over() == false);

    game.mark_board(5); // O
    REQUIRE(game.game_over() == false);

    game.mark_board(7); // X
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}

// Win by second column (2,5,8)
TEST_CASE("Test win by second column")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(2); // X
    REQUIRE(game.game_over() == false);

    game.mark_board(1); // O
    REQUIRE(game.game_over() == false);

    game.mark_board(5); // X
    REQUIRE(game.game_over() == false);

    game.mark_board(3); // O
    REQUIRE(game.game_over() == false);

    game.mark_board(8); // X
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}

// Win by third column (3,6,9)
TEST_CASE("Test win by third column")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(3); // X
    REQUIRE(game.game_over() == false);

    game.mark_board(1); // O
    REQUIRE(game.game_over() == false);

    game.mark_board(6); // X
    REQUIRE(game.game_over() == false);

    game.mark_board(2); // O
    REQUIRE(game.game_over() == false);

    game.mark_board(9); // X
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}

// Win by first row (1,2,3)
TEST_CASE("Test win by first row")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1); // X
    REQUIRE(game.game_over() == false);

    game.mark_board(4); // O
    REQUIRE(game.game_over() == false);

    game.mark_board(2); // X
    REQUIRE(game.game_over() == false);

    game.mark_board(5); // O
    REQUIRE(game.game_over() == false);

    game.mark_board(3); // X
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}

// Win by second row (4,5,6)
TEST_CASE("Test win by second row")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(4); // X
    REQUIRE(game.game_over() == false);

    game.mark_board(1); // O
    REQUIRE(game.game_over() == false);

    game.mark_board(5); // X
    REQUIRE(game.game_over() == false);

    game.mark_board(2); // O
    REQUIRE(game.game_over() == false);

    game.mark_board(6); // X
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}

// Win by third row (7,8,9)
TEST_CASE("Test win by third row")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(7); // X
    REQUIRE(game.game_over() == false);

    game.mark_board(1); // O
    REQUIRE(game.game_over() == false);

    game.mark_board(8); // X
    REQUIRE(game.game_over() == false);

    game.mark_board(2); // O
    REQUIRE(game.game_over() == false);

    game.mark_board(9); // X
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}

// Win diagonally from top left (1,5,9)
TEST_CASE("Test win diagonally from top left")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1); // X
    REQUIRE(game.game_over() == false);

    game.mark_board(2); // O
    REQUIRE(game.game_over() == false);

    game.mark_board(5); // X
    REQUIRE(game.game_over() == false);

    game.mark_board(3); // O
    REQUIRE(game.game_over() == false);

    game.mark_board(9); // X
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}

// Win diagonally from bottom left (7,5,3)
TEST_CASE("Test win diagonally from bottom left")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(7); // X
    REQUIRE(game.game_over() == false);

    game.mark_board(1); // O
    REQUIRE(game.game_over() == false);

    game.mark_board(5); // X
    REQUIRE(game.game_over() == false);

    game.mark_board(2); // O
    REQUIRE(game.game_over() == false);

    game.mark_board(3); // X
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}
