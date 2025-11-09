#pragma once

#include <string>
#include <vector>

class TicTacToe
{
public:
    // Now: checks for row/column/diagonal win OR tie.
    bool game_over();

    // Start game with first_player "X" or "O"
    void start_game(const std::string& first_player);

    // Mark position 1–9, then switch player.
    void mark_board(int position);

    // Current player to move
    std::string get_player() const;

    // Print 3x3 board
    void display_board() const;

    // "X", "O", or "C" (for tie)
    std::string get_winner() const;

private:
    void set_next_player();
    bool check_board_full() const;
    void clear_board();

    bool check_column_win() const;
    bool check_row_win() const;
    bool check_diagonal_win() const;
    void set_winner();

private:
    std::string player;
    std::vector<std::string> pegs = std::vector<std::string>(9, " ");
    std::string winner{" "}; // "X", "O", or "C"
};
