#include <iostream>
#include <SFML/Graphics.hpp>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"

int main()
{
    /*KONSOLA
    MinesweeperBoard board (5, 5, GameMode::EASY);
    MSBoardTextView view ( board );
    MSTextController ctrl ( board, view );
    ctrl.play();
    */


    sf::RenderWindow window(sf::VideoMode(800, 600), "Grafika w C++/SFML");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(30);

    MinesweeperBoard board(7, 4, DEBUG);
    MSSFMLView view (board);  // przekazujemy przez referencję planszę jako argument konstruktora

    // symulujemy rozgrywkę
    board.toggleFlag(0,0);
    board.revealField(3,2);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        view.draw(window);
        window.display();
    }

    return 0;
}
