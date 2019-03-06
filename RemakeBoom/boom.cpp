#include "bmp.h"
#include "item.h"
#include "boom.h"
#include "player.h"

void boom::show(int ID)
{
	drawBmp(x * 32, y * 32, imgBoom[(time % 2) + ((ID - 1) << 1)]);
}

void boom::hide()
{
	drawBmp(x * 32, y * 32, imgEmpty);
}

void boom::updateTime()
{
	time++;
}

int boom::checkExplode()
{
	// Explode domino
	if (thisMap->check(x, y) == EXPLODE && time <= BOOMTIMEEXPLODE1)
	{
		time = BOOMTIMEEXPLODE1 + 1;
		thisMap->set(x, y, BOOM1);
	}
	// Time boom start explode
	if (time >= BOOMTIMEEXPLODE1 && time <= BOOMTIMEEXPLODE2)
	{
		setStatus(0);
		int ew = 1, es = 1, ea = 1, ed = 1;
		// ew: up es: down ea: left ed: right

		for (int i = 1; i <= power; ++i)
		{
			// Check size
			if (x + i > thisMap->getCol() - 1)
			{
				ed = 0;
			}
			if (x - i < 0)
			{
				ea = 0;
			}
			if (y + i > thisMap->getRow() - 1)
			{
				es = 0;
			}
			if (y - i < 0)
			{
				ew = 0;
			}

			// Check item
			// ROCK or GROUND + ITEM
			if (ed == 1 && (thisMap->check(x + i, y) == ROCK || (int)thisMap->check(x + i, y) != thisMap->check(x + i, y)))
			{
				ed = 0;
			}
			if (ea == 1 && (thisMap->check(x - i, y) == ROCK || (int)thisMap->check(x - i, y) != thisMap->check(x - i, y)))
			{
				ea = 0;
			}
			if (es == 1 && (thisMap->check(x, y + i) == ROCK || (int)thisMap->check(x, y + i) != thisMap->check(x, y + i)))
			{
				es = 0;
			}
			if (ew == 1 && (thisMap->check(x, y - i) == ROCK || (int)thisMap->check(x, y - i) != thisMap->check(x, y - i)))
			{
				ew = 0;
			}
			
			// Paint effect and set map
			thisMap->set(x, y, EXPLODE);
			drawBmp(x * 32, y * 32, imgExplode[4 + (time == 22)]);
			if (ed)
			{
				thisMap->set(x + i, y, EXPLODE);
				drawBmp((x + i) * 32, y * 32, imgExplode[0 + (time == 22)]);
			}
			if (ea)
			{
				thisMap->set(x - i, y, EXPLODE);
				drawBmp((x - i) * 32, y * 32, imgExplode[0 + (time == 22)]);
			}
			if (es)
			{
				thisMap->set(x, y + i, EXPLODE);
				drawBmp(x * 32, (y + i) * 32, imgExplode[2 + (time == 22)]);
			}
			if (ew)
			{
				thisMap->set(x, y - i, EXPLODE);
				drawBmp(x * 32, (y - i) * 32, imgExplode[2 + (time == 22)]);
			}
		}
	}
	else if (time == BOOMTIMEEXPLODE3)
	{
		int ew = 1, es = 1, ea = 1, ed = 1;
		
		for (int i = 1; i <= power; i++)
		{
			// Check size
			if (x + i > thisMap->getCol() - 1)
			{
				ed = 0;
			}
			if (x - i < 0)
			{
				ea = 0;
			}
			if (y + i > thisMap->getRow() - 1)
			{
				es = 0;
			}
			if (y - i < 0)
			{
				ew = 0;
			}
			// Check item
			if (ed == 1 && (thisMap->check(x + i, y) == ROCK || (int)thisMap->check(x + i, y) != thisMap->check(x + i, y)))
			{
				ed = 0;
				if (thisMap->check(x + i, y) != ROCK)
				{
					item temp;
					temp.setType(thisMap->check(x + i, y) - GROUND);
					thisMap->set(x + i, y, thisMap->check(x + i, y) - GROUND);
					temp.setX(x + i);
					temp.setY(y);
					temp.hide();
					temp.show();
				}
			}
			if (ea == 1 && (thisMap->check(x - i, y) == ROCK || (int)thisMap->check(x - i, y) != thisMap->check(x - i, y)))
			{
				ea = 0;
				if (thisMap->check(x - i, y) != ROCK)
				{
					item temp;
					temp.setType(thisMap->check(x - i, y) - GROUND);
					thisMap->set(x - i, y, thisMap->check(x - i, y) - GROUND);
					temp.setX(x - i);
					temp.setY(y);
					temp.hide();
					temp.show();
				}
			}
			if (es == 1 && (thisMap->check(x, y + i) == ROCK || (int)thisMap->check(x, y + i) != thisMap->check(x, y + i)))
			{
				es = 0;
				if (thisMap->check(x, y + i) != ROCK)
				{
					item temp;
					temp.setType(thisMap->check(x, y + i) - GROUND);
					thisMap->set(x, y + i, thisMap->check(x, y + i) - GROUND);
					temp.setX(x);
					temp.setY(y + i);
					temp.hide();
					temp.show();
				}
			}
			if (ew == 1 && (thisMap->check(x, y - i) == ROCK || (int)thisMap->check(x, y - i) != thisMap->check(x, y - i)))
			{
				ew = 0;
				if (thisMap->check(x, y - i) != ROCK)
				{
					item temp;
					temp.setType(thisMap->check(x, y - i) - GROUND);
					thisMap->set(x, y - i, thisMap->check(x, y - i) - GROUND);
					temp.setX(x);
					temp.setY(y - i);
					temp.hide();
					temp.show();
				}
			}

			// Hide effect and set map
			hide();
			thisMap->set(x, y, EMPTY);

			if (ed)
			{
				drawBmp((x + i) * 32, y * 32, imgEmpty);
				thisMap->set(x + i, y, EMPTY);
			}
			if (ea)
			{
				drawBmp((x - i) * 32, y * 32, imgEmpty);
				thisMap->set(x - i, y, EMPTY);
			}
			if (es)
			{
				drawBmp(x * 32, (y + i) * 32, imgEmpty);
				thisMap->set(x, y + i, EMPTY);
			}
			if (ew)
			{
				drawBmp(x * 32, (y - i) * 32, imgEmpty);
				thisMap->set(x, y - i, EMPTY);
			}

		}

		return 1;
	}

	return 0;
}

void boom::move(int ID)
{
	switch (status)
	{
	case 0:
		return;
	case -1:
		if (y - 1 < 0) 
		{
			status = 0;
		}
		else
		{
			float temp = thisMap->check(x, y - 1);

			if (temp == ROCK || (int)temp != temp || temp == PLAYER1 || temp == PLAYER2 || temp == BOOM1 || temp == BOOM2)
			{
				status = 0;
			}
			else
			{
				hide();
				thisMap->set(x, y - 1, thisMap->check(x, y));
				thisMap->set(x, y, EMPTY);
				setY(y - 1);
				show(ID);
			}
		}
		return;
	case -2:
		if (y + 1 >= thisMap->getRow())
		{
			status = 0;
		}
		else
		{
			float temp = thisMap->check(x, y + 1);

			if (temp == ROCK || (int)temp != temp || temp == PLAYER1 || temp == PLAYER2 || temp == BOOM1 || temp == BOOM2)
			{
				status = 0;
			}
			else
			{
				hide();
				thisMap->set(x, y + 1, thisMap->check(x, y));
				thisMap->set(x, y, EMPTY);
				setY(y + 1);
				show(ID);
			}
		}
		return;
	case -3:
		if (x - 1 < 0)
		{
			status = 0;
		}
		else
		{
			float temp = thisMap->check(x - 1, y);

			if (temp == ROCK || (int)temp != temp || temp == PLAYER1 || temp == PLAYER2	|| temp == BOOM1 || temp == BOOM2)
			{
				status = 0;
			}
			else
			{
				hide();
				thisMap->set(x - 1, y, thisMap->check(x, y));
				thisMap->set(x, y, EMPTY);
				setX(x - 1);
				show(ID);
			}
		}
		return;
	case -4:
		if (x + 1 >= thisMap->getCol())
		{
			status = 0;
		}
		else
		{
			float temp = thisMap->check(x + 1, y);

			if (temp == ROCK || (int)temp != temp || temp == PLAYER1 || temp == PLAYER2 || temp == BOOM1 || temp == BOOM2)
			{
				status = 0;
			}
			else
			{
				hide();
				thisMap->set(x + 1, y, thisMap->check(x, y));
				thisMap->set(x, y, EMPTY);
				setX(x + 1);
				show(ID);
			}
		}
		return;
	}
}
