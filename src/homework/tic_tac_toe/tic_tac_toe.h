#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <string>
#include <vector>
#include <iostream>

class TicTacToe
{
public:
    // default 3x3 constructor (used in older code/tests)
    TicTacToe() : pegs(9, " ") {}

    // size constructor: size will be 3 or 4 for this assignment
    TicTacToe(int size);

    bool game_over();
    void start_game(std::string first_player);
    void mark_board(int position);
    void clear_board();

    std::string get_player() const { return player; }
    std::string get_winner() const { return winner; }
    const std::vector<std::string>& get_pegs() const { return pegs; }

    // stream operators for displaying and reading a game
    friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);
    friend std::istream& operator>>(std::istream& in, TicTacToe& game);

protected:
    // protected so derived classes (TicTacToe3/4) can use it
    std::vector<std::string> pegs;

    // virtual so derived classes override them with board‑size‑specific logic
    virtual bool check_column_win();
    virtual bool check_row_win();
    virtual bool check_diagonal_win();

private:
    std::string player;
    std::string winner;

    bool check_board_full();
    void set_next_player();
    void set_winner(std::string winner_value);
    std::string find_winner();
};

#endif
