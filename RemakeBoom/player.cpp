#include "player.h"

char player::action(int ID)
{
	if (GetAsyncKeyState(key[5 * (ID - 1)])) return 1;
	else if (GetAsyncKeyState(key[5 * (ID - 1) + 1])) return 2;
	else if (GetAsyncKeyState(key[5 * (ID - 1) + 2])) return 3;
	else if (GetAsyncKeyState(key[5 * (ID - 1) + 3])) return 4;
	else if (GetAsyncKeyState(key[5 * (ID - 1) + 4])) return 0;
	else return -1;
}

void player::show(int action)
{
	if (action != 0 && action != -1)
	{
		drawBmp(x * 32, y * 32, imgPlayer[(action - 1) * 2 + 8 * (ID - 1)]);
	}
}

void player::hide()
{
	drawBmp(x * 32, y * 32, imgEmpty);
}

int player::move()
{
	int action = this->action(ID);

	if (thisMap->check(x, y) == EXPLODE) 
	{
		if (invincible == 0)
		{
			invincible = 20;
			live--;
			drawBmp(475 + 200 * (ID - 1), 252, imgEmpty);
			drawNumber(475 + 200 * (ID - 1), 252, live);
			thisMap->set(x, y, PLAYER1 + ID - 1);
			
		}
		show(3);
	}

	switch (action)
	{
	case 1:
		if (y > 0)
		{
			if (thisMap->check(x, y - 1) == EMPTY)
			{
				if (thisMap->check(x, y) == BOOM1)
				{
					thisMap->set(x, y, BOOM1);
				}
				else
				{
					thisMap->set(x, y, EMPTY);
				}

				hide();
				thisMap->set(x, y - 1, PLAYER1 + ID - 1);
				drawBmp(x * 32, (y - 1) * 32, imgPlayer[(action - 1) * 2 + 8 * (ID - 1) + 1]);
				y--;
				show(action);
			}
			else if ((int)thisMap->check(x, y - 1) != thisMap->check(x, y - 1) || thisMap->check(x, y - 1) == ROCK)
			{
				hide();
				show(action);
			}
			else if (thisMap->check(x, y - 1) == BOOM1)
			{
				if (push)
				{
					return -1;
				}
				else
				{
					hide();
					show(action);
				}
			}
			else
			{
				useItem(thisMap->check(x, y - 1), ID);
				thisMap->set(x, y, EMPTY);
				hide();
				thisMap->set(x, y - 1, PLAYER1 + ID - 1);
				y--;
				hide();
				show(action);
			}
		}
		else
		{
			drawBmp(x * 32, y * 32, imgPlayer[(action - 1) * 2 + 8 * (ID - 1) + 1]);
			hide();
			show(action);
		}
		return 1;
	case 2:
		if (y < thisMap->getRow() - 1)
		{
			if (thisMap->check(x, y + 1) == EMPTY)
			{
				if (thisMap->check(x, y) == BOOM1)
				{
					thisMap->set(x, y, BOOM1);
				}
				else
				{
					thisMap->set(x, y, EMPTY);
				}
				hide();
				thisMap->set(x, y + 1, PLAYER1 + ID - 1);
				drawBmp(x * 32, (y + 1) * 32, imgPlayer[(action - 1) * 2 + 8 * (ID - 1) + 1]);
				y++;
				show(action);
			}
			else if ((int)thisMap->check(x, y + 1) != thisMap->check(x, y + 1) || thisMap->check(x, y + 1) == ROCK)
			{
				hide();
				show(action);
			}
			else if (thisMap->check(x, y + 1) > 79)
			{
				if (push)
				{
					return -2;
				}
				else
				{
					hide();
					show(action);
				}
			}
			else
			{
				useItem(thisMap->check(x, y + 1), ID);
				thisMap->set(x, y, EMPTY);
				hide();
				thisMap->set(x, y + 1, PLAYER1 + ID - 1);
				y++;
				hide();
				show(action);
			}
		}
		else
		{
			drawBmp(x * 32, y * 32, imgPlayer[(action - 1) * 2 + 8 * (ID - 1) + 1]);
			hide();
			show(action);
		}
		return 2;
	case 3:
		if (x > 0)
		{
			if (thisMap->check(x - 1, y) == EMPTY)
			{
				if (thisMap->check(x, y) == BOOM1)
				{
					thisMap->set(x, y, BOOM1);
				}
				else
				{
					thisMap->set(x, y, EMPTY);
				}
				hide();
				thisMap->set(x - 1, y, PLAYER1 + ID - 1);
				drawBmp((x - 1) * 32, (y) * 32, imgPlayer[(action - 1) * 2 + 8 * (ID - 1) + 1]);
				x--;
				show(action);
			}
			else if ((int)thisMap->check(x - 1, y) != thisMap->check(x - 1, y) || thisMap->check(x - 1, y) == ROCK)
			{
				hide();
				show(action);
			}
			else if (thisMap->check(x - 1, y) > 79)
			{
				if (push)
				{
					return -3;
				}
				else
				{
					hide();
					show(action);
				}
			}
			else
			{
				useItem(thisMap->check(x - 1, y), ID);
				thisMap->set(x, y, EMPTY);
				hide();
				thisMap->set(x - 1, y, PLAYER1 + ID - 1);
				x--;
				hide();
				show(action);
			}
		}
		else
		{
			drawBmp(x * 32, y * 32, imgPlayer[(action - 1) * 2 + 8 * (ID - 1) + 1]);
			hide();
			show(action);
		}
		return 3;
	case 4:
		if (x < thisMap->getCol() - 1)
		{
			if (thisMap->check(x + 1, y) == EMPTY)
			{
				if (thisMap->check(x, y) == BOOM1)
				{
					thisMap->set(x, y, BOOM1);
				}
				else
				{
					thisMap->set(x, y, EMPTY);
				}
				hide();
				thisMap->set(x + 1, y, PLAYER1 + ID - 1);
				drawBmp((x + 1) * 32, (y) * 32, imgPlayer[(action - 1) * 2 + 8 * (ID - 1) + 1]);
				x++;
				show(action);
			}
			else if (thisMap->check(x + 1, y) == GROUND || (int)thisMap->check(x + 1, y) != thisMap->check(x + 1, y) || thisMap->check(x + 1, y) == ROCK)
			{
				hide();
				show(action);
			}
			else if (thisMap->check(x + 1, y) > 79)
			{
				if (push)
				{
					return -4;
				}
				else
				{
					hide();
					show(action);
				}
			}
			else
			{
				useItem(thisMap->check(x + 1, y), ID);
				thisMap->set(x, y, EMPTY);
				hide();
				thisMap->set(x + 1, y, PLAYER1 + ID - 1);
				x++;
				hide();
				show(action);
			}
		}
		else
		{
			drawBmp(x * 32, y * 32, imgPlayer[(action - 1) * 2 + 8 * (ID - 1) + 1]);
			hide();
			show(action);
		}
		return 4;
	case 0:
		if (thisMap->check(x, y) != BOOM1) return 5;
		else return 0;
	}
	return 0;
}

void player::useItem(float type, int ID)
{
	if (type == HEART)
	{
		live++;
		drawNumber(475 + 200 * (ID - 1), 252, live);
	}
	else if (type == ADDBOOM)
	{
		if (numBoom < MAXBOOM)
		{
			numBoom++;
			drawNumber(475 + 200 * (ID - 1), 320, numBoom);
		}
	}
	else if (type == UPGRADE)
	{
		power++;
		drawNumber(475 + 200 * (ID - 1), 184, power);
	}
	else if (type == GLOVE)
	{
		push = 1;
		drawNumber(475 + 200 * (ID - 1), 218, push);
	}
	else
	{
		speed *= 0.8;
		drawNumber(475 + 200 * (ID - 1), 286, speed);
	}
}

int player::init(int ID)
{
	this->ID = ID;
	x = 0 + (ID - 1) * 10;
	y = 0 + (ID - 1) * 10;
	live = 2;
	numBoom = 1;
	usedBoom = 0;
	power = 1;
	push = 0;
	invincible = 0;
	return 1;
}

int player::isDead()
{
	if (live == 0)
	{
		hide();
		drawBmp(32 * x, 32 * y, imgGrave);
		return 1;
	}
	return 0;
}