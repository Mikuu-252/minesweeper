//
// Created by mikuu on 12.04.2023.
//

#ifndef SAPER_MSSFMLVIEW_H
#define SAPER_MSSFMLVIEW_H
#include "MinesweeperBoard.h"
#include <SFML/Graphics.hpp>

struct fieldAttribute {
    float xsizeField;
    float ysizeField;
    float borderField;
    sf::Color baseColor;
    sf::Color revealColor;
};


class MSSFMLView {
    MinesweeperBoard &board;

    sf::RectangleShape field;
    fieldAttribute fieldAttribute;

    sf::CircleShape flag;
    float flagSize;

    sf::CircleShape mine;
    float mineSize;

    sf::Font font;
    float fontSize;
    sf::Text mineNumber;

    void init();

public:
    MSSFMLView( MinesweeperBoard &board );
    void draw( sf::RenderWindow &window );
};


#endif //SAPER_MSSFMLVIEW_H
