#pragma once
#include "player.h"

class boom
{
private:
	int time = 0;
	int power = 0;
	int x = 0;
	int y = 0;
	int status = 0;

	map* thisMap;
public:
	void setMap(map*const thisMap)
	{
		this->thisMap = thisMap;
	}
	map* getMap()
	{
		return thisMap;
	}

	int getPower()
	{
		return power;
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	int getTime()
	{
		return time;
	}
	int getStatus()
	{
		return status;
	}
	void setPower(int power)
	{
		this->power = power;
	}
	void setX(int x)
	{
		this->x = x;
	}
	void setY(int y)
	{
		this->y = y;
	}
	void setTime(int time)
	{
		this->time = time;
	}
	void setStatus(int status)
	{
		this->status = status;
	}
	void updateTime();

	void show(int ID);
	void hide();
	int checkExplode();
	void move(int ID);
};

