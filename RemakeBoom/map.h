#pragma once
#include "header.h"

class map
{
private:
	int x = 0;
	int y = 0;
	int row = ROWMAP;
	int col = COLMAP;
	float** arrayMap = NULL;
public:
	int getRow()
	{
		return row;
	}
	int getCol()
	{
		return col;
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}

	void setRow(int row)
	{
		this->row = row;
	}
	void setCol(int col)
	{
		this->col = col;
	}
	void setX(int x)
	{
		this->x = x;
	}
	void setY(int y)
	{
		this->y = y;
	}

	void loadMap();
	void init();
	void del();
	float check(int x, int y)
	{
		return arrayMap[x][y];
	}
	void set(int x, int y, float type)
	{
		this->arrayMap[x][y] = type;
	}
};

