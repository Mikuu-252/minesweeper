#ifndef SAPER_MINESWEEPERBOARD_H
#define SAPER_MINESWEEPERBOARD_H

enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};

class MinesweeperBoard
{
    Field board[100][100]{};

    int width;
    int height;
    int mineNumber;
    int mineLeft;
    GameState gameState;
    GameMode difficulty;
    bool firstMove;

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
