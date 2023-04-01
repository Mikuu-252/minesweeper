//
// Created by mikuu on 01.04.2023.
//

#include <iostream>
#include "MSTextController.h"
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

MSTextController::MSTextController(MinesweeperBoard &board, MSBoardTextView &view): board(board), view(view)
{}

void MSTextController::play() {
    while(board.getGameState() == RUNNING)
    {
        int playerChoice;
        int col;
        int row;

        view.display();

        std::cout << "Jaka akcje chcesz wykonac? \n 1. Odkryc pole \n 2. Dodac/usunac flage \n";
        std::cin >> playerChoice;
        if (playerChoice == 1)
        {
            std::cout << "\n Jakie pole chcesz odkryc? \n";

            std::cout << "Podaj kolumne:\n";
            std::cin >> col;
            col--;
            std::cout << "Podaj rzad:\n";
            std::cin >> row;
            row--;

            board.revealField(row, col);
        }
        else if(playerChoice == 2)
        {
            std::cout << "\n Gdzie chcesz postawic/usunac flage? \n";

            std::cout << "Podaj kolumne:\n";
            std::cin >> col;
            col--;
            std::cout << "Podaj rzad:\n";
            std::cin >> row;
            row--;

            board.toggleFlag(row, col);
        }
        else
        {
            std::cout << "Wpisz poprawna wartosc \n";
        }
    }

    if (board.getGameState() == FINISHED_WIN)
    {
        std::cout << "Wygrales gratulacje!";
    }
    else if (board.getGameState() == FINISHED_LOSS)
    {
        std::cout << "Przegrales dasz rade kolejnym razem!";
    }
    else
    {
        std::cout << "blad konca gry";
    }

}
