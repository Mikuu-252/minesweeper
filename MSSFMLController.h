#ifndef CPP_2023_LAB_01_MSSFMLCONTROLLER_H
#define CPP_2023_LAB_01_MSSFMLCONTROLLER_H


#include "MinesweeperBoard.h"
#include "MSSFMLView.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>

class MSSFMLController {


    MinesweeperBoard &board;
    MSSFMLView &view;
    sf::RenderWindow &window;

public:
    MSSFMLController(MinesweeperBoard &board, MSSFMLView &view, sf::RenderWindow &window);
    void play();

};


#endif //CPP_2023_LAB_01_MSSFMLCONTROLLER_H
