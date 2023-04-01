//
// Created by mikuu on 24.03.2023.
//

#include "MSBoardTextView.h"
#include <iostream>

MSBoardTextView::MSBoardTextView(MinesweeperBoard &board): board(board)
{}

void MSBoardTextView::display() {

    //Display board
    for (int row = 0; row < board.getBoardHeight(); ++row)
    {
        for (int col = 0; col < board.getBoardWidth(); ++col)
        {
            std::cout << "[";
            std::cout << board.getFieldInfo(row, col);
            std::cout << "]";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
