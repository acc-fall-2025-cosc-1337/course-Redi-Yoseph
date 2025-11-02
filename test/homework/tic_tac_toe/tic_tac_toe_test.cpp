#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "tic_tac_toe.h"
#include <sstream>

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

TEST_CASE("start_game throws on invalid first player")
{
    TicTacToe game;
    REQUIRE_THROWS_AS(game.start_game("A"), std::invalid_argument);
}

TEST_CASE("mark_board throws on out of range positions")
{
    TicTacToe game;
    game.start_game("X");
    REQUIRE_THROWS_AS(game.mark_board(0), std::out_of_range);
    REQUIRE_THROWS_AS(game.mark_board(10), std::out_of_range);
}

TEST_CASE("marking an occupied position does not change player")
{
    TicTacToe game;
    game.start_game("X");
    game.mark_board(1);
    std::string player_after_first = game.get_player();
    REQUIRE(player_after_first == "O");
    // marking the same occupied position should be ignored and player should remain the same
    game.mark_board(1);
    REQUIRE(game.get_player() == player_after_first);
}

TEST_CASE("display_board prints empty board after start_game")
{
    TicTacToe game;
    game.start_game("X");
    std::ostringstream oss;
    auto* old = std::cout.rdbuf(oss.rdbuf());
    game.display_board();
    std::cout.rdbuf(old);
    std::string out = oss.str();

    std::string expected =
        "  |   |  \n"
        "---+---+---\n"
        "  |   |  \n"
        "---+---+---\n"
        "  |   |  \n";

    REQUIRE(out == expected);
}
