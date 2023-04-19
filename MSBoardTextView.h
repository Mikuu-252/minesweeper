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
