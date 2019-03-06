#pragma once

class item
{
private:
	int x = 0;
	int y = 0;
	float type = 0;
public:
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	float getType()
	{
		return type;
	}

	void setX(int x)
	{
		this->x = x;
	}
	void setY(int y)
	{
		this->y = y;
	}
	void setType(float type)
	{
		this->type = type;
	}

	int show();
	int hide();
};

