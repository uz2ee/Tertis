
#ifndef _GAME_
#define _GAME_

#include "board.h"
#include "tile.h"
#include <time.h>





enum color {BLACK, RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW, WHITE, COLOR_MAX}; // Colors

class Game
{
public:

    Game(Board *pBoard, Tile *tetrominos, int pScreenHeight);

    void drawScene ();
    void createNewPiece ();

	//4 variables that define a piece
    int mPosX, mPosY;               // Position of the piece that is falling down
    int tetroType, mRotation;          // Kind and rotation the piece that is falling down


private:

    int mScreenHeight;              // Screen height in pixels
    int mNextPosX, mNextPosY;       // Position of the next piece
    int nextTetroType, mNextRotation;  // Kind and rotation of the next piece

    Board *mBoard;
    Tile *tetromino;

    int getRand (int pA, int pB);
    void initGame();
    void drawPiece (int pX, int pY, int pTetroType, int pRotation);
    void drawBoard ();



};
#endif
