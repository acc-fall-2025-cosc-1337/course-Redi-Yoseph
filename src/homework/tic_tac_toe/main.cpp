#include <iostream>
#include <string>
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

int main()
{
    TicTacToeManager manager;
    char choice = 'y';

    while (choice == 'y' || choice == 'Y')
    {
        TicTacToe game;
        std::string first_player;

        std::cout << "Enter first player (X or O): ";
        std::cin >> first_player;

        while (first_player != "X" && first_player != "O")
        {
            std::cout << "Invalid. Enter X or O: ";
            std::cin >> first_player;
        }

        game.start_game(first_player);

        // Show empty board at start
        std::cout << game;

        // Play until game is over
        while (!game.game_over())
        {
            // Read move (via overloaded >>), then display board
            std::cin >> game;
            std::cout << game;  // ✅ board displayed after each mark
        }

        std::string winner = game.get_winner();

        if (winner == "C")
        {
            std::cout << "Game over! It's a tie.\n";
        }
        else
        {
            std::cout << "Game over! Winner: " << winner << "\n";
        }

        // Save game in manager and display totals
        manager.save_game(game);

        int x = 0;
        int o = 0;
        int t = 0;
        manager.get_winner_total(o, x, t);

        std::cout << "Scoreboard -> X wins: " << x
                  << "  O wins: " << o
                  << "  Ties: "   << t << "\n\n";

        std::cout << "Play again? (y/n): ";
        std::cin >> choice;
        std::cout << "\n";
    }

    std::cout << "Thanks for playing!\n";
    return 0;
}
