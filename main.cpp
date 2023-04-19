#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "MinesweeperBoard.h"
//#include "MSBoardTextView.h"
//#include "MSTextController.h"
#include "MSSFMLView.h"
#include "MSSFMLController.h"

int main()
{
    srand(time(nullptr));

    /*KONSOLA
    MinesweeperBoard board (5, 5, GameMode::EASY);
    MSBoardTextView view ( board );
    MSTextController ctrl ( board, view );
    ctrl.play();
    */

    //GRAFIKA
    sf::RenderWindow window(sf::VideoMode(800, 600), "Grafika w C++/SFML");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(30);

    MinesweeperBoard board(7, 4, EASY);
    MSSFMLView view (board);

    MSSFMLController ctrl (board, view, window);

    ctrl.play();


    return 0;
}
