#include "bmp.h"
#include "header.h"
#include <Windows.h>
#include <stdio.h>
#include "item.h"
#include <math.h>

int item::show()
{
	Img img;

	float typeItem = item::getType();

	if (typeItem == EMPTY)
	{
		img = imgEmpty;
	}

	if (typeItem == ROCK)
	{
		img = imgRock;
	}
	else if (typeItem == GROUND || int(typeItem) != typeItem)
	{
		img = imgGround;
	}
	else if (typeItem == HEART)
	{
		img = imgItem[2];
	}
	else if (typeItem == BOOST)
	{
		img = imgItem[3];
	}
	else if (typeItem == UPGRADE)
	{
		img = imgItem[0];
	}
	else if (typeItem == GLOVE)
	{
		img = imgItem[1];
	}
	else if (typeItem == ADDBOOM)
	{
		img = imgItem[4];
	}

	drawBmp(item::getX() * 32, item::getY() * 32, img);
	return 1;
}

int item::hide()
{
	drawBmp(x * 32, y * 32, imgEmpty);
	return 1;
}


