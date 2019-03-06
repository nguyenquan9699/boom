#pragma once
#include "map.h"
#include "player.h"

class game
{
private:
	int music = 1;
	int sound = 1;
	map*  thisMap;
	player* thisPlayer[NUMPLAYER];
	boom* thisBoom[NUMPLAYER*MAXBOOM];
	char typeMap[10];
public:
	void loadImg();
	void loadImgMap(char *map);
	int initAll();
	int delAll();
	int menuLoop();
	int mainLoop();
	void play();
	int gameOver(int ID);
	void changeSound()
	{
		sound = 1 - sound;
	}
	void changeMusic()
	{
		music = 1 - music;
	}
	void chooseMap();
};

