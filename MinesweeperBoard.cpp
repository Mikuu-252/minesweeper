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
    gameState = RUNNING;

    clear_board();

    board[0][0].hasMine = true;
    board[1][1].isRevealed = true;
    board[0][2].hasMine = true;
    board[0][2].hasFlag = true;
}

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode)
{
    difficulty = mode;
    gameState = RUNNING;
    firstMove = true;

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

        mineNumber = std::ceil((size * mineProcent * 1.00)/100);
        mineLeft = mineNumber;

        for (int minePlaced = 0; minePlaced < mineNumber; minePlaced++) {
            int colRand = rand() % width;
            int rowRand = rand() % height;

            if (board[rowRand][colRand].hasMine) minePlaced--;
            else board[rowRand][colRand].hasMine = true;
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
    return mineNumber;
}

int MinesweeperBoard::countMines(int row, int col) const {
    if(!board[row][col].isRevealed)
    {
        return -1;
    }
    else if(row < 0 || col < 0 || col > width || row > height)
    {
        return -1;
    }
    else
    {
        int mineNumber = 0;

        for(int rowCheck = -1; rowCheck <= 1; ++rowCheck)
        {
            for (int colCheck = -1; colCheck <= 1; ++colCheck) {
                if (row+rowCheck < 0 || col+colCheck < 0 || col+rowCheck > width || row+colCheck > height)
                {
                    continue;
                }
                else
                {
                    if (board[row+rowCheck][col+colCheck].hasMine)
                    {
                        mineNumber += 1;
                    }
                }
            }
        }
        return mineNumber;
    }
}

bool MinesweeperBoard::hasFlag(int row, int col) const
{
    if(board[row][col].hasFlag) return true;
    else { return false; }
}

void MinesweeperBoard::toggleFlag(int row, int col) {
    if (!board[row][col].isRevealed)
    {
        if(board[row][col].hasFlag)
        {
            board[row][col].hasFlag = false;

            if (board[row][col].hasMine)
            {
                mineLeft++;
            }
            if (!board[row][col].hasMine)
            {
                mineLeft--;
            }

            if(mineLeft == 0)
            {
                gameState = FINISHED_WIN;
            }

        }
        else
        {
            board[row][col].hasFlag = true;

            if (board[row][col].hasMine)
            {
                mineLeft--;
            }
            if (!board[row][col].hasMine)
            {
                mineLeft++;
            }

            if(mineLeft == 0)
            {
                gameState = FINISHED_WIN;
            }

        }
    }

}

void MinesweeperBoard::revealField(int row, int col) {

    if (board[row][col].isRevealed ||
        (row < 0 || col < 0 || col > width || row > height) ||
        getGameState()==FINISHED_LOSS ||
        getGameState()==FINISHED_WIN ||
        board[row][col].hasFlag)
    {
        return;
    }

    if (!board[row][col].isRevealed && !board[row][col].hasMine)
    {
        board[row][col].isRevealed = true;
        firstMove = false;

        if(mineLeft == 0)
        {
            gameState = FINISHED_WIN;
        }
    }

    if(!board[row][col].isRevealed && board[row][col].hasMine)
    {
        if(firstMove)
        {
            firstMove = false;
            board[row][col].hasMine = false;
            board[row][col].isRevealed = true;

            wrongRNG:

            int columnRand = rand() % width;
            int rowRand = rand() % height;

            if (board[columnRand][rowRand].hasMine) goto wrongRNG;
            else board[columnRand][rowRand].hasMine = true;
        }
        else
        {
            board[row][col].isRevealed = true;
            gameState = FINISHED_LOSS;
        }
    }
}

bool MinesweeperBoard::isRevealed(int row, int col) const {
    if (board[row][col].isRevealed)
    {
        return true;
    }
    else
    {
        return false;
    }
}

char MinesweeperBoard::getFieldInfo(int row, int col) const {
    if (row < 0 || col < 0 || col > width || row > height) return '#';
    if (!board[row][col].isRevealed && board[row][col].hasFlag) return 'F';
    if (!board[row][col].isRevealed && !board[row][col].hasFlag) return '_';
    if (board[row][col].isRevealed && board[row][col].hasMine) return 'x';
    if (board[row][col].isRevealed && countMines(row,col) == 0) return ' ';
    if (board[row][col].isRevealed && countMines(row,col) != 0) return countMines(row,col)+'0';
    return 'e';
}

GameState MinesweeperBoard::getGameState() const {
    return gameState;
}



