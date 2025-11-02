#include <iostream>
#include <string>
#include "tic_tac_toe.h"

int main()
{
    std::cout << "TicTacToe (Board-Full Version)\n\n";

    char again = 'y';
    while (again == 'y' || again == 'Y')
    {
        TicTacToe game;

        std::string first;
        while (true)
        {
            std::cout << "Who goes first? Enter X or O: ";
            std::cin >> first;
            if (first == "X" || first == "O") break;
            std::cout << "Please enter exactly X or O.\n";
        }

        try { game.start_game(first); }
        catch (const std::exception& e) { std::cout << "Error: " << e.what() << "\n"; return 1; }

        while (!game.game_over())
        {
            game.display_board();
            std::cout << "\nCurrent player: " << game.get_player() << "\n";

            int pos = 0;
            std::cout << "Enter position (1-9): ";
            if (!(std::cin >> pos))
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Invalid input. Please enter a number 1-9.\n";
                continue;
            }

            try { game.mark_board(pos); }
            catch (const std::exception& e) { std::cout << "Error: " << e.what() << "\n"; }
            std::cout << "\n";
        }

        std::cout << "Final board:\n";
        game.display_board();
        std::cout << "\nGame over! (Board is full.)\n";

        std::cout << "\nPlay again? (y/n): ";
        std::cin >> again;
        std::cout << "\n";
    }

    std::cout << "Thanks for playing!\n";
    return 0;
}
