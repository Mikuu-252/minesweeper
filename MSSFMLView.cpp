//
// Created by mikuu on 12.04.2023.
//

#include <iostream>
#include "MSSFMLView.h"


MSSFMLView::MSSFMLView(MinesweeperBoard &board): board(board)
{init();}

void MSSFMLView::init() {

    fieldSize.xsizeField = 50;
    fieldSize.ysizeField = 50;
    fieldSize.spaceField = 5;

    sf::RectangleShape field(sf::Vector2f(fieldSize.xsizeField, fieldSize.ysizeField));
    field.setFillColor(sf::Color(140,140,140));

    this->field = field;
}

void MSSFMLView::draw(sf::RenderWindow &window) {


    int xsizeFlag = 20;
    int spaceFlag = 5;
    sf::CircleShape flag(xsizeFlag, 3);
    flag.setFillColor(sf::Color(0,255,0));
    //flag.rotate(90);


    for (int col = 0; col < board.getBoardWidth(); ++col) {
        for (int row = 0; row < board.getBoardHeight(); ++row) {
            field.setPosition(fieldSize.spaceField+(col*fieldSize.xsizeField)+(fieldSize.spaceField*col),
                              fieldSize.spaceField+(row*fieldSize.ysizeField)+(fieldSize.spaceField*row));
            window.draw(field);

            flag.setPosition(fieldSize.spaceField+(col*fieldSize.xsizeField)+(fieldSize.spaceField*col),
                             fieldSize.spaceField+(row*fieldSize.ysizeField)+(fieldSize.spaceField*row));;
            window.draw(flag);

        }
    }

};