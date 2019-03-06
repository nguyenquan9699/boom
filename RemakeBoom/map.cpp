#include <time.h>
#include <windows.h>
#include "item.h"
#include "map.h"

void map::loadMap()
{
	Sleep(10);
	drawBmp(0, 0, imgEmpty);
	for (int x = 0; x < col; x++)
	{
		for (int y = 0; y < row; y++)
		{
			if (arrayMap[x][y] == PLAYER1) drawBmp(x * 32, y * 32, imgPlayer[2]);
			else if (arrayMap[x][y] == PLAYER2)
			{
				drawBmp((COLMAP - 1) * 32, (ROWMAP - 1) * 32, imgEmpty);
				drawBmp(x * 32, y * 32, imgPlayer[10]);
			}
			else
			{
				item temp;
				temp.setX(x);
				temp.setY(y);
				temp.setType(arrayMap[x][y]);
				temp.show();
			}
		}
	}
}

void map::init()
{
	arrayMap = new float*[col];
	for (int i = 0; i < col; i++)
	{
		map::arrayMap[i] = new float[row];
	}

	srand(time(0));
	int randnum;
	for (int x = 0; x < col; x++)
	{
		for (int y = 0; y < row; y++)
		{
			if (x == 0 && y == 0) arrayMap[x][y] = PLAYER1;
			else if (x + y == 1 || row + col - x - y - 2 == 1) arrayMap[x][y] = EMPTY;
			else if (x == col - 1 && y == row - 1) arrayMap[x][y] = PLAYER2;
			else if (x % 2 != 0 && y % 2 != 0) arrayMap[x][y] = ROCK;
			else
			{
				randnum = rand() % 100;
				if (randnum == 0) arrayMap[x][y] = HEART + GROUND;
				else if (randnum <= 10) arrayMap[x][y] = ADDBOOM + GROUND;
				else if (randnum <= 20) arrayMap[x][y] = UPGRADE + GROUND;
				else if (randnum <= 30) arrayMap[x][y] = BOOST + GROUND;
				else if (randnum <= 35) arrayMap[x][y] = GLOVE + GROUND;
				else if (randnum <= 75) arrayMap[x][y] = GROUND;
				else
				{
					arrayMap[x][y] = EMPTY;
				}
			}
		}
	}
}

void map::del()
{
	for (int i = 0; i < col; i++)
	{
		delete arrayMap[i];
	}
	delete arrayMap;
}