#include <iostream>
#include "MSSFMLController.h"

MSSFMLController::MSSFMLController(MinesweeperBoard &board, MSSFMLView &view, sf::RenderWindow &window): board(board), view(view), window(window)
{}

void MSSFMLController::play()
{

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            int col = div(event.mouseButton.x, 55).quot;
            int row = div(event.mouseButton.y, 55).quot;

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    board.revealField(row, col);
                } else if (event.mouseButton.button == sf::Mouse::Right)
                {
                    board.toggleFlag(row, col);
                }
            }
        }

        window.clear();
        view.draw(window);
        window.display();
    }
}
