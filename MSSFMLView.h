//
// Created by mikuu on 12.04.2023.
//

#ifndef SAPER_MSSFMLVIEW_H
#define SAPER_MSSFMLVIEW_H
#include "MinesweeperBoard.h"
#include <SFML/Graphics.hpp>

struct fieldSize {
    int xsizeField;
    int ysizeField;
    int spaceField;
};

class MSSFMLView {
    MinesweeperBoard &board;

    sf::RectangleShape field;
    fieldSize fieldSize;
    void init();

public:
    MSSFMLView( MinesweeperBoard &board );
    void draw( sf::RenderWindow &window );
};


#endif //SAPER_MSSFMLVIEW_H
