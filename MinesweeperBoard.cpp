//
// Created by mikuu on 08.03.2023.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "MinesweeperBoard.h"

MinesweeperBoard::MinesweeperBoard()
{
    width = 5;
    height = 7;

    clear_board();

    board[0][0].hasMine = true;
    board[1][1].isRevealed = true;
    board[0][2].hasMine = true;
    board[0][2].hasFlag = true;
}


MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode)
{
    GameMode difficulty = mode;

    this->width = width;
    this->height = height;

    int size = width * height;
    int mineProcent;

    srand(time(nullptr));

    clear_board();

    if(difficulty == DEBUG)
    {
        for (int column = 0; column < width; ++column)
        {
            board[0][column].hasMine = true;
        }

        for (int row = 0; row < height; row = row + 2) {
            board[row][0].hasMine = true;
        }

        for (int column = 0; column < width; ++column)
        {
            for (int row = 0; row < height; ++row) {
                if (row == column)
                {
                    board[row][column].hasMine = true;
                }
            }
        }
    }
    else
    {
        if(difficulty == EASY) mineProcent = 10;
        if(difficulty == NORMAL) mineProcent = 20;
        if(difficulty == HARD) mineProcent = 30;

        double mineNumber = std::ceil((size * mineProcent * 1.00)/100);

        for (int minePlaced = 0; minePlaced < mineNumber; ++minePlaced) {
            int columnRand = rand() % width;
            int rowRand = rand() % height;

            if (board[columnRand][rowRand].hasMine) --minePlaced;
            else board[columnRand][rowRand].hasMine = true;

        }

    }



}

void MinesweeperBoard::clear_board()
{
    for (int column = 0; column < height; ++column)
    {
        for (int row = 0; row < width; ++row)
        {
            board[column][row].hasFlag = false;
            board[column][row].hasMine = false;
            board[column][row].isRevealed = false;
        }
    }
}

void MinesweeperBoard::debug_display() const
{
    //Display number
    std::cout << "     ";
    for (int i = 0; i < width; ++i) {
        std::cout << "  " << i << "  ";
    }
    std::cout << "\n";

    //Display board
    for (int row = 0; row < height; ++row)
    {
        std::cout << "  " << row << "  ";
        for (int column = 0; column < width; ++column)
        {
            std::cout << "[";
            if(board[row][column].hasMine)
            {
                std::cout << "M";
            }
            else
            {
                std::cout << ".";
            }

            if(board[row][column].isRevealed)
            {
                std::cout << "o";
            }
            else
            {
                std::cout << ".";
            }

            if(board[row][column].hasFlag)
            {
                std::cout << "f";
            }
            else
            {
                std::cout << ".";
            }

            std::cout << "]";
        }
        std::cout << "\n";
    }

    std::cout << getMineCount();
}

int MinesweeperBoard::getBoardWidth() const
{
    return width;
}

int MinesweeperBoard::getBoardHeight() const
{
    return height;
}

int MinesweeperBoard::getMineCount() const
{
    int mineCount = countMines(1,0);
    return mineCount;
}

int MinesweeperBoard::countMines(int row, int col) const {
    if(board[row][col].isRevealed)
    {
        int mineNumber = 0;
        if (board[row-1][col].hasMine) mineNumber++;
        if (board[row+1][col].hasMine) mineNumber++;
        if (board[row][col-1].hasMine) mineNumber++;
        if (board[row][col+1].hasMine) mineNumber++;
        if (board[row-1][col-1].hasMine) mineNumber++;
        if (board[row+1][col-1].hasMine) mineNumber++;
        if (board[row-1][col+1].hasMine) mineNumber++;
        if (board[row+1][col+1].hasMine) mineNumber++;
    }


    return mineNumber;
}
