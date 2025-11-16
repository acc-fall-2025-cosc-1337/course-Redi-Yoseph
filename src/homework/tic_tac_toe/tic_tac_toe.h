#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <iostream>
#include <string>
#include <vector>

class TicTacToe
{
public:
    TicTacToe();

    void start_game(std::string first_player);
    void mark_board(int position);
    bool game_over();

    std::string get_winner() const { return winner; }
    std::string get_player() const { return player; }

    // Stream operators (REQUIRED by assignment)
    friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);
    friend std::istream& operator>>(std::istream& in, TicTacToe& game);

private:
    std::string player;
    std::string winner;
    std::vector<std::string> pegs{9, " "};   // 3x3 board, positions 1-9

    void clear_board();
    void set_next_player();
    bool check_column_win();
    bool check_row_win();
    bool check_diagonal_win();
    bool check_board_full();
    void set_winner(const std::string& winr);
};

#endif
