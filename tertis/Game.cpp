
#include "game.h"
#include <stdlib.h>
using namespace std;
#include <iostream>
#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#define PI 3.14159265358979323846
#include<math.h>
#include "tile.h"


Game::Game(Board *pBoard, Tile *pPieces, int pScreenHeight)
{
	mScreenHeight = pScreenHeight;

	// Get the pointer to the Board and Tetromino classes
	mBoard = pBoard;
	tetromino = pPieces;

	// Game initialization
	initGame ();
}

/*
returns a random number between two numbers
*/
int Game::getRand(int pA, int pB)
{
	return rand() % (pB - pA +1) +pA;
}

/*
new game is initialied by creating two pieces: current and next piece randomly and then sets their positions
*/
void Game::initGame()
{
	//init random numbers
	srand(GetTickCount());

	//1st piece
	tetroType = getRand(0, 6);
	mRotation = getRand(0, 3);
	mPosX = (BOARD_WIDTH/2) + tetromino->getXInitialPosition(tetroType, mRotation);
	mPosY = tetromino->getYInitialPosition(tetroType, mRotation);

	//next piece
	nextTetroType = getRand(0, 6);
	mNextRotation = getRand(0, 3);
	mNextPosX = (BOARD_WIDTH) + 2;
	mNextPosY = 0;
}

/*
create a random piece
*/
void Game::createNewPiece()
{
	//new piece
	tetroType = nextTetroType;
	mRotation = mNextRotation;
	mPosX = (BOARD_WIDTH/2) + tetromino->getXInitialPosition(tetroType, mRotation);
	mPosY = tetromino->getYInitialPosition(tetroType, mRotation);

	//next piece
	nextTetroType = getRand(0, 6);
	mNextRotation = getRand(0, 3);
}

/*
Metod iterates through the piece matrix and draws each block of the piece
*/
void Game::drawPiece(int pX, int pY, int pTetroType, int pRotation)
{

	color mColor;

    // Obtain the position in pixel in the screen of the block we want to draw
    int mPixelsX = mBoard->getXPosInPixels (pX);
    int mPixelsY = mBoard->getYPosInPixels (pY);

    // Travel the matrix of blocks of the piece and draw the blocks that are filled
    for (int i = 0; i < PIECE_BLOCKS; i++)
    {
        for (int j = 0; j < PIECE_BLOCKS; j++)
        {
			/*tetromino->setColor(tetroType);
				glColor3f(GLfloat(tetromino->red), GLfloat(tetromino->green), GLfloat(tetromino->blue));*/
             //Get the type of the block and draw it with the correct color
            switch (tetromino->getBlockType (pTetroType, pRotation, j, i))
            {
                case 1: mColor = GREEN; glColor3f(0.0f, 1.0f, 0.0f); break;  // For each block of the piece except the pivot
                case 2: mColor = BLUE; glColor3f(0.0f, 0.0f, 1.0f); break;   // For the pivot
            }

            if (tetromino->getBlockType (pTetroType, pRotation, j, i) != 0)
			{
			    cout<<((mPixelsX + i * BLOCK_SIZE)/1000)<<"drawing tiles"<<endl;
			    cout<<mPixelsY <<" Y tiles"<<endl;
			    cout<<BLOCK_SIZE<<" BS tiles"<<endl;
			    cout<<j <<" j tiles"<<endl;
			    cout<<i <<" i tiles"<<endl;
			    //glColor3ub(251,240,208);
				glRectf((GLfloat(mPixelsX + i * BLOCK_SIZE)/1000),
					GLfloat((mPixelsY + j * BLOCK_SIZE)/1000),
					GLfloat(((mPixelsX + i * BLOCK_SIZE) + BLOCK_SIZE - .1)/1000),
					GLfloat(((mPixelsY + j * BLOCK_SIZE) + BLOCK_SIZE - .1))/1000);
			}
        }
    }
}

void Game::drawBoard ()
{
	// Calculate the limits of the board in pixels
    int mX1 = BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2)) - 1;
    int mX2 = BOARD_POSITION + (BLOCK_SIZE * (BOARD_WIDTH / 2));
    int mY = mScreenHeight - (BLOCK_SIZE * BOARD_HEIGHT);

    // Rectangles that delimits the board




	glColor3f(0.0f, 0.0f, 0.0f);
	glRectf(GLfloat(mX1 - BOARD_LINE_WIDTH),
					GLfloat(mY),
					GLfloat(mX1),
					GLfloat(mScreenHeight - 1));

	glRectf(GLfloat(mX2),
					GLfloat(mY),
					GLfloat(mX2 + BOARD_LINE_WIDTH),
					GLfloat(mScreenHeight - 1));



    // Drawing the blocks that are already stored in the board
    mX1 += 1;
    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        for (int j = 0; j < BOARD_HEIGHT; j++)
        {
            // Check if the block is filled, if so, draw it
            if (!mBoard->isFreeBlock(i, j))
			{
				tetromino->setColor(tetroType);
				glColor3f(GLfloat(tetromino->red), GLfloat(tetromino->green), GLfloat(tetromino->blue));
				//glColor3f(0.0f, 1.0f, 1.0f);

				glRectf(GLfloat(mX1 + i * BLOCK_SIZE),
					GLfloat(mY + j * BLOCK_SIZE),
					GLfloat((mX1 + i * BLOCK_SIZE) + BLOCK_SIZE - 1),
					GLfloat((mY + j * BLOCK_SIZE) + BLOCK_SIZE - 1));

				/*glBegin(GL_QUADS);
					glTexCoord2d(0.0f, 0.0f);
					glVertex3f(GLfloat(mX1 + i * BLOCK_SIZE), GLfloat(mY + j * BLOCK_SIZE), 0.0f);
					glTexCoord2d(1.0f, 0.0f);
					glVertex3f(GLfloat((mX1 + i * BLOCK_SIZE) + BLOCK_SIZE - 1), GLfloat(mY + j * BLOCK_SIZE), 0.0f);
					glTexCoord2d(1.0f, 1.0f);
					glVertex3f(GLfloat((mX1 + i * BLOCK_SIZE) + BLOCK_SIZE - 1),GLfloat((mY + j * BLOCK_SIZE) + BLOCK_SIZE - 1), 0.0f);
					glTexCoord2d(0.0f, 1.0f);
					glVertex3f(GLfloat(mX1 + i * BLOCK_SIZE), GLfloat((mY + j * BLOCK_SIZE) + BLOCK_SIZE - 1), 0.0f);
				glEnd();
*/

			}
        }
    }
	//glDisable(GL_TEXTURE_2D);
}



/*
draw all objects of the scene
*/
void Game::drawScene()
{
	//texture = LoadTexture("tile3.bmp");
	drawBoard();
	drawPiece(mPosX, mPosY, tetroType, mRotation);
	//drawPiece(mNextPosX, mNextPosY, nextTetroType, mNextRotation);
}
