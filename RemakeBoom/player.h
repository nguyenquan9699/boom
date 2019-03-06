#pragma once
#include "console.h"
#include "map.h"
#include "boom.h"

class player
{
private:
	int x, y;
	int numBoom = 1;
	int usedBoom = 0;
	int power = 1;
	int speed;
	int live = 1;
	int push = 0;
	int ID = 0;
	int invincible = 0;

	map* thisMap;
public:
	int flagBoom[MAXBOOM] = { 0,0,0,0,0 };
	void setMap(map*const thisMap)
	{
		this->thisMap = thisMap;
	}
	map* getMap()
	{
		return thisMap;
	}

	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	int getNumBoom()
	{
		return numBoom;
	}
	int getUsedBoom()
	{
		return usedBoom;
	}
	int getPower()
	{
		return power;
	}
	int getSpeed()
	{
		return speed;
	}
	int getLive()
	{
		return live;
	}
	int getPush()
	{
		return push;
	}
	int getID()
	{
		return ID;
	}
	int getInvincible()
	{
		return invincible;
	}

	void setX(int x)
	{
		this->x = x;
	}
	void setY(int y)
	{
		this->y = y;
	}
	void setNumBoom(int numBoom)
	{
		this->numBoom = numBoom;
	}
	void setUsedBoom(int usedBoom)
	{
		this->usedBoom = usedBoom;
	}

	void setPower(int power)
	{
		this->power = power;
	}
	void setSpeed(int speed)
	{
		this->speed = speed;
	}
	void setLive(int live)
	{
		this->live = live;
	}

	void setPush(int push)
	{
		this->push = push;
	}
	void setID(int ID)
	{
		this->ID = ID;
	}
	void setInvincible(int invincible)
	{
		this->invincible = invincible;
	}
	int init(int ID);
	int move();
	char action(int ID);
	int isDead();
	void show(int action);
	void hide();
	void useItem(float type, int ID);
};

