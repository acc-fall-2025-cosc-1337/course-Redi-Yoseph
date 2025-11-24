#include "catch.hpp"
#include <memory>
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

// 
//   TICTACTOE 3 TESTS
// 

TEST_CASE("Test win by first column 3", "[TicTacToe3]")
{
    std::unique_ptr<TicTacToe> board = std::make_unique<TicTacToe3>();
    board->start_game("X");

    board->mark_board(1);  // X
    board->mark_board(2);  // O
    board->mark_board(4);  // X
    board->mark_board(3);  // O
    board->mark_board(7);  // X

    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Test win by second column 3", "[TicTacToe3]")
{
    std::unique_ptr<TicTacToe> board = std::make_unique<TicTacToe3>();
    board->start_game("O");

    board->mark_board(2);
    board->mark_board(1);
    board->mark_board(5);
    board->mark_board(3);
    board->mark_board(8);

    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "O");
}

TEST_CASE("Test win by third column 3", "[TicTacToe3]")
{
    std::unique_ptr<TicTacToe> board = std::make_unique<TicTacToe3>();
    board->start_game("X");

    board->mark_board(3);
    board->mark_board(1);
    board->mark_board(6);
    board->mark_board(2);
    board->mark_board(9);

    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Test win by first row 3", "[TicTacToe3]")
{
    std::unique_ptr<TicTacToe> board = std::make_unique<TicTacToe3>();
    board->start_game("X");

    board->mark_board(1);
    board->mark_board(4);
    board->mark_board(2);
    board->mark_board(5);
    board->mark_board(3);

    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Test win by diagonal 3", "[TicTacToe3]")
{
    std::unique_ptr<TicTacToe> board = std::make_unique<TicTacToe3>();
    board->start_game("O");

    board->mark_board(1);
    board->mark_board(2);
    board->mark_board(5);
    board->mark_board(3);
    board->mark_board(9);

    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "O");
}

TEST_CASE("Test tie 3", "[TicTacToe3]")
{
    std::unique_ptr<TicTacToe> board = std::make_unique<TicTacToe3>();
    board->start_game("X");

    // full board, no winner
    board->mark_board(1);
    board->mark_board(2);
    board->mark_board(3);
    board->mark_board(5);
    board->mark_board(4);
    board->mark_board(6);
    board->mark_board(8);
    board->mark_board(7);
    board->mark_board(9);

    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "C");
}


//   TICTACTOE 4 TESTS 


TEST_CASE("Test win by first column 4", "[TicTacToe4]")
{
    auto board = std::make_unique<TicTacToe4>();
    board->start_game("X");

    board->mark_board(1);
    board->mark_board(2);
    board->mark_board(5);
    board->mark_board(3);
    board->mark_board(9);
    board->mark_board(4);
    board->mark_board(13);

    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Test win by first row 4", "[TicTacToe4]")
{
    auto board = std::make_unique<TicTacToe4>();
    board->start_game("O");

    board->mark_board(1);
    board->mark_board(5);
    board->mark_board(2);
    board->mark_board(6);
    board->mark_board(3);
    board->mark_board(7);
    board->mark_board(4);

    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "O");
}

TEST_CASE("Test win by diagonal main 4", "[TicTacToe4]")
{
    auto board = std::make_unique<TicTacToe4>();
    board->start_game("X");

    board->mark_board(1);
    board->mark_board(2);
    board->mark_board(6);
    board->mark_board(3);
    board->mark_board(11);
    board->mark_board(4);
    board->mark_board(16);

    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Test win by diagonal other 4", "[TicTacToe4]")
{
    auto board = std::make_unique<TicTacToe4>();
    board->start_game("O");

    board->mark_board(4);
    board->mark_board(1);
    board->mark_board(7);
    board->mark_board(2);
    board->mark_board(10);
    board->mark_board(3);
    board->mark_board(13);

    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "O");
}

TEST_CASE("Test tie 4", "[TicTacToe4]")
{
    auto board = std::make_unique<TicTacToe4>();
    board->start_game("X");

    // 16 moves arranged to produce a true tie (no 4-in-a-row)
    std::vector<int> moves =
    {1,2, 4,3, 6,5, 7,8, 9,10, 12,11, 14,13, 15,16};

    for (int pos : moves)
    {
        board->mark_board(pos);
    }

    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "C");
}
