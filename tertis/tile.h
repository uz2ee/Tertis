
#ifndef _tile_
#define _tile_

class Tile
{
public:

	float red;
	float green;
	float blue;
	int type;
	int getBlockType(int tetroType, int rotationType, int sizeX, int sizeY);
	int getXInitialPosition(int tetroType, int rotationType);
	int getYInitialPosition(int tetroType, int rotationType);
	void setColor(int t);

};

#endif
