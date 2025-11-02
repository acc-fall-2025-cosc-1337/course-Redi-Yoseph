#pragma once
#include <string>
#include <vector>

class TicTacToe
{
public:
    bool game_over() const;                    // returns check_board_full()
    void start_game(const std::string& first_player); // set player, clear_board()
    void mark_board(int position);             // set peg, then set_next_player()
    std::string get_player() const;            // return current player
    void display_board() const;                // print 3x3 board

private:
    void set_next_player();                    // toggle X<->O
    bool check_board_full() const;             // true if no " " left
    void clear_board();                        // set all 9 to " "

private:
    std::string player;
    std::vector<std::string> pegs = std::vector<std::string>(9, " ");
};
