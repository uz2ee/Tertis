
#include "Tile.h"

// Tile definition
	char tetrominos [7 /*kind */ ][4 /* rotation */ ][5 /* horizontal blocks */ ][5 /* vertical blocks */ ] =
	{

	// Square
	  {
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 2, 1, 0},
		{0, 0, 1, 1, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 2, 1, 0},
		{0, 0, 1, 1, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 2, 1, 0},
		{0, 0, 1, 1, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 2, 1, 0},
		{0, 0, 1, 1, 0},
		{0, 0, 0, 0, 0}
		}
	   },

	// I
	  {
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 1, 2, 1, 1},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 2, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 1, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{1, 1, 2, 1, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 1, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 2, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0}
		}
	   }
	  ,
	// L
	  {
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 2, 0, 0},
		{0, 0, 1, 1, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 1, 2, 1, 0},
		{0, 1, 0, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 1, 1, 0, 0},
		{0, 0, 2, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0},
		{0, 1, 2, 1, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
		}
	   },
	// L mirrored
	  {
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 2, 0, 0},
		{0, 1, 1, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0},
		{0, 1, 2, 1, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 1, 0},
		{0, 0, 2, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 1, 2, 1, 0},
		{0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0}
		}
	   },
	// N
	  {
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0},
		{0, 0, 2, 1, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 1, 2, 0, 0},
		{0, 0, 1, 1, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 1, 2, 0, 0},
		{0, 1, 0, 0, 0},
		{0, 0, 0, 0, 0}
		},

	   {
		{0, 0, 0, 0, 0},
		{0, 1, 1, 0, 0},
		{0, 0, 2, 1, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
		}
	   },
	// N mirrored
	  {
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 2, 1, 0},
		{0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 2, 1, 0},
		{0, 1, 1, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0},
		{0, 1, 2, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 1, 0},
		{0, 1, 2, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
		}
	   },
	// T
	  {
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 2, 1, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 1, 2, 1, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 1, 2, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 1, 2, 1, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
		}
	   }
	};

	// Displacement of the piece to the position where it is first drawn in the board when it is created
int tetrominoInitialPosition  [7 /*kind */ ][4 /* r2otation */ ][2 /* position */] =
	{
	/* Square */
	  {
		{-2, -3},
		{-2, -3},
		{-2, -3},
		{-2, -3}
	   },
	/* I */
	  {
		{-2, -2},
		{-2, -3},
		{-2, -2},
		{-2, -3}
	   },
	/* L */
	  {
		{-2, -3},
		{-2, -3},
		{-2, -3},
		{-2, -2}
	   },
	/* L mirrored */
	  {
		{-2, -3},
		{-2, -2},
		{-2, -3},
		{-2, -3}
	   },
	/* N */
	  {
		{-2, -3},
		{-2, -3},
		{-2, -3},
		{-2, -2}
	   },
	/* N mirrored */
	  {
		{-2, -3},
		{-2, -3},
		{-2, -3},
		{-2, -2}
	   },
	/* T */
	  {
		{-2, -3},
		{-2, -3},
		{-2, -3},
		{-2, -2}
	   },
	};


int Tile::getBlockType (int tetroType, int rotationType, int sizeX, int sizeY)
{
    return tetrominos [tetroType][rotationType][sizeX][sizeY];
}
int Tile::getXInitialPosition (int tetroType, int rotationType)
{
    return tetrominoInitialPosition [tetroType][rotationType][0];
}

int Tile::getYInitialPosition (int tetroType, int rotationType)
{
    return tetrominoInitialPosition [tetroType][rotationType][1];
}

void Tile::setColor(int t)
{
	type = t;
	switch(type)
	{
		case 0:		//red
			red = 1.0;
			green = 0.0;
			blue = 0.0;
			break;
		case 1:		 //blue
			red = 0.0;
			green = 0.0;
			blue = 1.0;
			break;
		case 2:		//green
			red = 0.0;
			green = 1.0;
			blue = 0.0;
			break;
		case 3: 	//cyan
			red = 0.0;
			green = 1.0;
			blue = 1.0;
			break;
		case 4:		//magenta
			red = 1.0;
			green = 0.0;
			blue = 1.0;
			break;
		case 5:		//yellow
			red = 1.0;
			green = 1.0;
			blue = 0.0;
			break;
		case 6:		//black
			red = 0.0;
			green = 0.0;
			blue = 0.0;
			break;
	}
}
