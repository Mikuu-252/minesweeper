//
// Created by mikuu on 01.04.2023.
//

#ifndef CPP_2023_LAB_01_MSTEXTCONTROLLER_H
#define CPP_2023_LAB_01_MSTEXTCONTROLLER_H


#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

class MSTextController {


    MinesweeperBoard &board;
    MSBoardTextView &view;

public:
    MSTextController(MinesweeperBoard &board, MSBoardTextView &view);
    void play();

};


#endif //CPP_2023_LAB_01_MSTEXTCONTROLLER_H
