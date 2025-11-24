#include <iostream>
#include <memory>
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"

int main()
{
    TicTacToeManager manager;
    std::unique_ptr<TicTacToe> game;

    char again = 'y';

    while (again == 'y' || again == 'Y')
    {
        char board_choice;
        std::cout << "Play TicTacToe 3 or 4 (enter 3 or 4): ";
        std::cin >> board_choice;

        if (board_choice == '3')
        {
            game = std::make_unique<TicTacToe3>();
        }
        else
        {
            game = std::make_unique<TicTacToe4>();
        }

        std::string first_player;
        std::cout << "First player (X or O): ";
        std::cin >> first_player;

        game->start_game(first_player);

        while (!game->game_over())
        {
            std::cout << *game << "\n";
            std::cin >> *game;
        }

        std::cout << *game << "\n";
        std::cout << "Winner: " << game->get_winner() << "\n";

        manager.save_game(game);

        std::cout << "Play again? (y/n): ";
        std::cin >> again;
    }

    std::cout << "\nGame history and totals:\n";
    std::cout << manager << "\n";

    return 0;
}
