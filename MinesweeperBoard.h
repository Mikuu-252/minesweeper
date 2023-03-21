//
// Created by mikuu on 08.03.2023.
//

#ifndef SAPER_MINESWEEPERBOARD_H
#define SAPER_MINESWEEPERBOARD_H

enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

class MinesweeperBoard
{
    struct Field
    {
        bool hasMine;
        bool hasFlag;
        bool isRevealed;
    };

    // sugerowane:
    // Array2D<Field> board;

    // tablica 2D
    Field board[100][100]{};

    int width;                // rzeczywista szerokość planszy
    int height;               // rzeczywista wysokość planszy

private:
    void clear_board();



public:
    MinesweeperBoard();
    MinesweeperBoard(int width, int height, GameMode mode);
    void debug_display() const;

    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;
    int countMines(int row, int col) const;
    bool hasFlag(int row, int col) const;
    void toggleFlag(int row, int col);
    void revealField(int row, int col);
    bool isRevealed(int row, int col) const;
    GameState getGameState() const;
    char getFieldInfo(int row, int col) const;
};


#endif //SAPER_MINESWEEPERBOARD_H
