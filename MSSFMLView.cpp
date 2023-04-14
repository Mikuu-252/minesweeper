//
// Created by mikuu on 12.04.2023.
//

#include <iostream>
#include "MSSFMLView.h"


MSSFMLView::MSSFMLView(MinesweeperBoard &board): board(board)
{init();}

void MSSFMLView::init() {

    //FIELD
    fieldAttribute.xsizeField = 50;
    fieldAttribute.ysizeField = 50;
    fieldAttribute.borderField = 5;
    fieldAttribute.baseColor = sf::Color(140,140,140);
    fieldAttribute.revealColor = sf::Color(50,50,50);

    sf::RectangleShape field(sf::Vector2f(fieldAttribute.xsizeField, fieldAttribute.ysizeField));


    field.setFillColor(fieldAttribute.baseColor);
    field.setOutlineThickness(fieldAttribute.borderField);
    field.setOutlineColor(sf::Color(0,0,0));

    this->field = field;

    //FLAG
    flagSize = 15;
    sf::CircleShape flag(flagSize, 3);
    flag.setFillColor(sf::Color(0,150,0));
    flag.rotate(90);

    this->flag = flag;

    //MINE
    mineSize = 12;
    sf::CircleShape mine(mineSize);
    mine.setFillColor(sf::Color(0,0,0));

    this->mine = mine;

    //TEXT
    if (!font.loadFromFile("Roboto-Regular.ttf"))
    {
        std::cout << "error";
    }
    else
    {
        fontSize = 30;
        mineNumber.setFont(font);
        mineNumber.setFillColor(sf::Color(255,255,255));
        mineNumber.setCharacterSize(fontSize);
    }
}

void MSSFMLView::draw(sf::RenderWindow &window) {


    for (int col = 0; col < board.getBoardWidth(); ++col) {
        for (int row = 0; row < board.getBoardHeight(); ++row) {

            field.setPosition((col * fieldAttribute.xsizeField) + (col * fieldAttribute.borderField),
                              (row * fieldAttribute.ysizeField) + (row * fieldAttribute.borderField));

            if (board.isRevealed(row,col))
            {
                field.setFillColor(fieldAttribute.revealColor);
            }
            else
            {
                field.setFillColor(fieldAttribute.baseColor);
            }

            window.draw(field);

            if(board.getFieldInfo(row,col) == 'F'){
                flag.setPosition((flagSize*2.5) + (col * fieldAttribute.xsizeField) + (col * fieldAttribute.borderField),
                                 (flagSize/2) + (row * fieldAttribute.ysizeField) + (row * fieldAttribute.borderField));
                window.draw(flag);
            }

            if(board.getFieldInfo(row,col) == 'x'){
                mine.setPosition(mineSize + (col * fieldAttribute.xsizeField) + (col * fieldAttribute.borderField),
                                 mineSize + (row * fieldAttribute.ysizeField) + (row * fieldAttribute.borderField));
                window.draw(mine);
            }

            if (board.getFieldInfo(row,col) > 48 && board.getFieldInfo(row,col) < 58) {
                mineNumber.setPosition((fontSize / 2) + (col * fieldAttribute.xsizeField) + (col * fieldAttribute.borderField),
                                       (fontSize / 4) + (row * fieldAttribute.ysizeField) + (row * fieldAttribute.borderField));
                mineNumber.setString(board.getFieldInfo(row, col));
                window.draw(mineNumber);
            }
        }
    }

}