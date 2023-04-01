//
// Created by mikuu on 24.03.2023.
//

#ifndef CPP_2023_LAB_01_MSBOARDTEXTVIEW_H
#define CPP_2023_LAB_01_MSBOARDTEXTVIEW_H


#include "MinesweeperBoard.h"

class MSBoardTextView {
    MinesweeperBoard &board;

public:
    MSBoardTextView( MinesweeperBoard &board );
    void display();

};


#endif //CPP_2023_LAB_01_MSBOARDTEXTVIEW_H
