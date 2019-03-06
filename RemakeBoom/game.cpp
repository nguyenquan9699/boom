#pragma comment(lib,"winmm.lib")
#include <Windows.h>
#include <mmsystem.h>
#include "game.h"
#include "console.h"
#include "header.h"
#include <time.h>

void game::loadImgMap(char *map)
{
	char *path1 = new char[50];
	char *path2 = new char[50];
	char *path3 = new char[50];

	strcpy_s(path1, 50, "rs/img/map/");
	strcat_s(path1, 50, map); strcpy_s(path2, 50, path1); strcpy_s(path3, 50, path1);
	
	strcat_s(path1, 50, "/empty.bmp");
	path1[strlen(path1)] = '\0';
	loadBmp(imgEmpty, path1);

	strcat_s(path2, 50, "/rock.bmp");
	path2[strlen(path2)] = '\0';
	loadBmp(imgRock, path2);

	strcat_s(path3, 50, "/ground.bmp");
	path3[strlen(path3)] = '\0';
	loadBmp(imgGround, path3);
}

void game::loadImg()
{
	loadBmp(imgPlayer[0], "rs/img/player/1w.bmp");
	loadBmp(imgPlayer[1], "rs/img/player/1ww.bmp");
	loadBmp(imgPlayer[2], "rs/img/player/1s.bmp");
	loadBmp(imgPlayer[3], "rs/img/player/1ss.bmp");
	loadBmp(imgPlayer[4], "rs/img/player/1a.bmp");
	loadBmp(imgPlayer[5], "rs/img/player/1aa.bmp");
	loadBmp(imgPlayer[6], "rs/img/player/1d.bmp");
	loadBmp(imgPlayer[7], "rs/img/player/1dd.bmp");
	loadBmp(imgPlayer[8], "rs/img/player/2w.bmp");
	loadBmp(imgPlayer[9], "rs/img/player/2ww.bmp");
	loadBmp(imgPlayer[10], "rs/img/player/2s.bmp");
	loadBmp(imgPlayer[11], "rs/img/player/2ss.bmp");
	loadBmp(imgPlayer[12], "rs/img/player/2a.bmp");
	loadBmp(imgPlayer[13], "rs/img/player/2aa.bmp");
	loadBmp(imgPlayer[14], "rs/img/player/2d.bmp");
	loadBmp(imgPlayer[15], "rs/img/player/2dd.bmp");

	loadBmp(imgGrave, "rs/img/player/grave.bmp");
	loadBmp(imgInvincible, "rs/img/player/Invincible.bmp");

	loadBmp(imgBoom[0], "rs/img/boom/boom_1a.bmp");
	loadBmp(imgBoom[1], "rs/img/boom/boom_1b.bmp");
	loadBmp(imgBoom[2], "rs/img/boom/boom_2a.bmp");
	loadBmp(imgBoom[3], "rs/img/boom/boom_2b.bmp");

	loadBmp(imgItem[0], "rs/img/item/upgrade.bmp");
	loadBmp(imgItem[1], "rs/img/item/gloves.bmp");
	loadBmp(imgItem[2], "rs/img/item/heart.bmp");
	loadBmp(imgItem[3], "rs/img/item/boost.bmp");
	loadBmp(imgItem[4], "rs/img/item/addboom.bmp");

	loadBmp(imgExplode[0], "rs/img/boom/explode_ha.bmp");
	loadBmp(imgExplode[1], "rs/img/boom/explode_hb.bmp");
	loadBmp(imgExplode[2], "rs/img/boom/explode_va.bmp");
	loadBmp(imgExplode[3], "rs/img/boom/explode_vb.bmp");
	loadBmp(imgExplode[4], "rs/img/boom/explode_centera.bmp");
	loadBmp(imgExplode[5], "rs/img/boom/explode_centerb.bmp");
	
	loadBmp(imgSubins, "rs/img/menu/subins.bmp");
	loadBmp(imgInstruction, "rs/img/menu/instruction.bmp");
	loadBmp(imgAuthor, "rs/img/menu/author.bmp");
	loadBmp(imgPanel, "rs/img/menu/panel.bmp");
	loadBmp(imgPlaya, "rs/img/menu/playa.bmp");
	loadBmp(imgPlayb, "rs/img/menu/playb.bmp");
	loadBmp(imgPlayc, "rs/img/menu/playc.bmp");
	loadBmp(imgExita, "rs/img/menu/exita.bmp");
	loadBmp(imgExitb, "rs/img/menu/exitb.bmp");
	loadBmp(imgExitc, "rs/img/menu/exitc.bmp");
	loadBmp(imgTrans, "rs/img/menu/trans.bmp");
	loadBmp(imgTextPlayer, "rs/img/menu/text_player.bmp");
	loadBmp(imgTextWin, "rs/img/menu/text_win.bmp");
	loadBmp(imgFrame, "rs/img/menu/frame.bmp");

	loadBmp(imgNumber[0], "rs/img/number/0.bmp");
	loadBmp(imgNumber[1], "rs/img/number/1.bmp");
	loadBmp(imgNumber[2], "rs/img/number/2.bmp");
	loadBmp(imgNumber[3], "rs/img/number/3.bmp");
	loadBmp(imgNumber[4], "rs/img/number/4.bmp");
	loadBmp(imgNumber[5], "rs/img/number/5.bmp");
	loadBmp(imgNumber[6], "rs/img/number/6.bmp");
	loadBmp(imgNumber[7], "rs/img/number/7.bmp");
	loadBmp(imgNumber[8], "rs/img/number/8.bmp");
	loadBmp(imgNumber[9], "rs/img/number/9.bmp");

}

int game::initAll()
{
	resizeConsole(800, 393);
	removeScrollbar();
	showConsoleCursor(0);
	_strupr_s(typeMap, 10);
	SetConsoleTitle(typeMap);
	
	Sleep(100);
	drawBmp(375, 0, imgSubins);
	drawBmp(375, 15, imgPanel);

	thisMap = new map;
	thisMap->init();
	thisMap->loadMap();

	for (int i = 0; i < NUMPLAYER; i++)
	{
		thisPlayer[i] = new player;
		thisPlayer[i]->init(i + 1);
		thisPlayer[i]->setMap(thisMap);
	}

	for (int i = 0; i < MAXBOOM*NUMPLAYER; i++)
	{
		thisBoom[i] = new boom;
		thisBoom[i]->setMap(thisMap);
	}
	return 1;
}

int game::delAll()
{
	thisMap->del();
	delete thisMap;

	for (int i = 0; i < NUMPLAYER; i++)
	{
		delete thisPlayer[i];
	}
	return 1;
}

int game::menuLoop()
{
	loadImg();
	// Set windows
	system("color 72");
	resizeConsole(900, 480);
	removeScrollbar();
	showConsoleCursor(0);
	SetConsoleTitle("FIGHT >o< DIE");

	HANDLE handle = GetStdHandle(STD_INPUT_HANDLE);
	DWORD prev_mode;
	GetConsoleMode(handle, &prev_mode);
	SetConsoleMode(handle, prev_mode & ~ENABLE_QUICK_EDIT_MODE);

	HWND hwnd = GetConsoleWindow();
	DWORD style = GetWindowLong(hwnd, GWL_STYLE);
	style &= ~WS_MAXIMIZEBOX;
	SetWindowLong(hwnd, GWL_STYLE, style);
	SetWindowPos(hwnd, NULL, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE | SWP_FRAMECHANGED);

	Sleep(100);
	drawBmp(250, 27, imgPanel);
	drawBmp(308, 200, imgPlayb);
	drawBmp(308, 280, imgExita);
	drawBmp(0, 200, imgInstruction);
	drawBmp(550, 200, imgAuthor);

	int chon = 0;
	int c = 0;
	int high1 = 220;
	int high2 = 300;
	int checkMin = 0;

	while (true)
	{
		c++;
		
		if (chon == 0)
		{
			high1 < 220 ? high1++ : high1>210 ? high1-- : high1++;
			Sleep(100);	
			drawBmp(540, high1, imgTrans);
			drawBmp(540, high1, imgPlayer[c % 8]);
		}
		else if (chon == 1)
		{
			high2 < 300 ? high2++ : high2 > 290 ? high2-- : high2++;
			Sleep(100);
			drawBmp(540, high2, imgTrans);
			drawBmp(540, high2, imgPlayer[c % 8 + 8]);
		}
		if (GetAsyncKeyState('W') || GetAsyncKeyState(VK_NUMPAD5))
		{
			chon--;
			if (chon == 0)
			{
				drawBmp(540, 300, imgTrans);
				drawBmp(308, 280, imgExitc);
				drawBmp(308, 200, imgPlayb);
				drawBmp(308, 280, imgExita);
			}
			else if (chon == 1)
			{
				drawBmp(540, 220, imgTrans);			
				drawBmp(308, 200, imgPlayc);
				drawBmp(308, 200, imgPlaya);
				drawBmp(308, 280, imgExitb);
			}	
		}
		else if (GetAsyncKeyState('S') || GetAsyncKeyState(VK_NUMPAD2))
		{	
			chon++;
			if (chon == 0)
			{
				drawBmp(540, 300, imgTrans);
				drawBmp(308, 280, imgExitc);
				drawBmp(308, 200, imgPlayb);
				drawBmp(308, 280, imgExita);
			}
			else if (chon == 1)
			{
				drawBmp(540, 220, imgTrans);
				drawBmp(308, 200, imgPlayc);
				drawBmp(308, 200, imgPlaya);
				drawBmp(308, 280, imgExitb);
			}
		}
		else if (GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(VK_RETURN))
		{
			if (chon == 1)
			{
				exit(0);
			}
			if (chon == 0)
			{
				system("cls");
				Sleep(100);
				chooseMap();
				loadImgMap(typeMap);

				initAll();
				mainLoop();
				delAll();

				system("cls");
				resizeConsole(900, 480);
				removeScrollbar();
				Sleep(100);
				drawBmp(250, 27, imgPanel);
				drawBmp(308, 200, imgPlayb);
				drawBmp(308, 280, imgExita);
				drawBmp(0, 200, imgInstruction);
				drawBmp(550, 200, imgAuthor);
			}
		}
		if (chon < 0)
		{
			chon = 0;
		}
		else if (chon > 1)
		{
			chon = 1;
		}
		
	}
}

int game::mainLoop()
{
	
	// Player sts
	drawBmp(475, 150, imgPlayer[3]);
	drawBmp(675, 150, imgPlayer[11]);

	drawBmp(375, 184, imgItem[0]);
	drawNumber(475, 184, thisPlayer[0]->getPower());
	drawNumber(675, 184, thisPlayer[1]->getPower());
	drawBmp(375, 218, imgItem[1]);
	drawNumber(475, 218, thisPlayer[0]->getPush());
	drawNumber(675, 218, thisPlayer[1]->getPush());
	drawBmp(375, 252, imgItem[2]);
	drawNumber(475, 252, thisPlayer[0]->getLive());
	drawNumber(675, 252, thisPlayer[1]->getLive());
	drawBmp(375, 286, imgItem[3]);
	drawNumber(475, 286, thisPlayer[0]->getSpeed());
	drawNumber(675, 286, thisPlayer[1]->getSpeed());
	drawBmp(375, 320, imgItem[4]);
	drawNumber(475, 320, thisPlayer[0]->getNumBoom());
	drawNumber(675, 320, thisPlayer[1]->getNumBoom());

	int checkMin = 0;
	HWND hwnd = GetConsoleWindow();
	while (true)
	{
		// Settings
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			return 1;
		}
		if (GetAsyncKeyState(VK_F1))		
		{
			changeMusic();
			if (music == 0)
			{
				mciSendStringA("open \"rs/audio/1.wav\" type mpegvideo alias music", nullptr, 0, nullptr);
				mciSendStringA("play music repeat", nullptr, 0, nullptr);
			}
			else
			{
				mciSendStringA("pause music", nullptr, 0, nullptr);
			}			
		}
		if (GetAsyncKeyState(VK_F2)) changeSound();

		// Before, after
		int t = 1;
		int s = 1;

		thisPlayer[0]->getSpeed() > thisPlayer[1]->getSpeed() ? t-- : s--;
		
		// Put boom
		int moveoft = 0;
		moveoft = thisPlayer[t]->move();
		int moveofs = 0;
		moveofs = thisPlayer[s]->move();

		// Check game over

		if (gameOver(thisPlayer[0]->isDead()*thisPlayer[0]->getID() + thisPlayer[1]->isDead()*thisPlayer[1]->getID())) return 1;

		// Invincivle --
		if (thisPlayer[t]->getInvincible() != 0)
		{
			drawBmp(thisPlayer[t]->getX() * 32, thisPlayer[t]->getY() * 32, imgInvincible);
			drawBmp(thisPlayer[t]->getX() * 32, thisPlayer[t]->getY() * 32, imgPlayer[3 + 8 * (thisPlayer[t]->getID() - 1)]);
			thisPlayer[t]->setInvincible(thisPlayer[t]->getInvincible() - 1);
		}
		if (thisPlayer[s]->getInvincible() != 0)
		{
			drawBmp(thisPlayer[s]->getX() * 32, thisPlayer[s]->getY() * 32, imgInvincible);
			drawBmp(thisPlayer[s]->getX() * 32, thisPlayer[s]->getY() * 32, imgPlayer[3 + 8 * (thisPlayer[s]->getID() - 1)]);
			thisPlayer[s]->setInvincible(thisPlayer[s]->getInvincible() - 1);
		}
		
		// Move
		if (moveoft == 5)
		{
			for (int i = 0; i < thisPlayer[t]->getNumBoom(); i++)
			{
				if (thisPlayer[t]->flagBoom[i] == 0)
				{
					thisBoom[(thisPlayer[t]->getID() - 1)*MAXBOOM + i]->setX(thisPlayer[t]->getX());
					thisBoom[(thisPlayer[t]->getID() - 1)*MAXBOOM + i]->setY(thisPlayer[t]->getY());
					thisBoom[(thisPlayer[t]->getID() - 1)*MAXBOOM + i]->setPower(thisPlayer[t]->getPower());
					thisBoom[(thisPlayer[t]->getID() - 1)*MAXBOOM + i]->setTime(0);
					thisBoom[(thisPlayer[t]->getID() - 1)*MAXBOOM + i]->show(thisPlayer[t]->getID());

					thisPlayer[t]->flagBoom[i] = 1;
					thisPlayer[t]->setUsedBoom(thisPlayer[t]->getUsedBoom() + 1);
					thisMap->set(thisBoom[(thisPlayer[t]->getID() - 1)*MAXBOOM + i]->getX(), thisBoom[(thisPlayer[t]->getID() - 1)*MAXBOOM + i]->getY(), BOOM1);
					
					break;
				}
			}
		}

		if (moveofs == 5)
		{
			for (int i = 0; i < thisPlayer[s]->getNumBoom(); i++)
			{
				if (thisPlayer[s]->flagBoom[i] == 0)
				{
					thisBoom[(thisPlayer[s]->getID() - 1)*MAXBOOM + i]->setX(thisPlayer[s]->getX());
					thisBoom[(thisPlayer[s]->getID() - 1)*MAXBOOM + i]->setY(thisPlayer[s]->getY());
					thisBoom[(thisPlayer[s]->getID() - 1)*MAXBOOM + i]->setPower(thisPlayer[s]->getPower());
					thisBoom[(thisPlayer[s]->getID() - 1)*MAXBOOM + i]->setTime(0);
					thisBoom[(thisPlayer[s]->getID() - 1)*MAXBOOM + i]->show(thisPlayer[s]->getID());

					thisPlayer[s]->flagBoom[i] = 1;
					thisPlayer[s]->setUsedBoom(thisPlayer[s]->getUsedBoom() + 1);
					thisMap->set(thisBoom[(thisPlayer[s]->getID() - 1)*MAXBOOM + i]->getX(), thisBoom[(thisPlayer[s]->getID() - 1)*MAXBOOM + i]->getY(), BOOM1);
					break;
				}
			}
		}

		// Push boom, boom explode
		int xT = 0, yT = 0, xS = 0, yS = 0;
		switch (moveoft)
		{
		case -1:
			xT = 0; yT = -1;
			break;
		case -2:
			xT = 0; yT = 1;
			break;
		case -3:
			xT = -1; yT = 0;
			break;
		case -4:
			xT = 1; yT = 0;
			break;
		}
		switch (moveofs)
		{
		case -1:
			xS = 0; yS = -1;
			break;
		case -2:
			xS = 0; yS = 1;
			break;
		case -3:
			xS = -1; yS = 0;
			break;
		case -4:
			xS = 1; yS = 0;
			break;
		}

		for (int i = 0; i < thisPlayer[s]->getNumBoom() || i < thisPlayer[t]->getNumBoom(); i++)
		{
			// Explode
				
				//
			if (i < thisPlayer[s]->getNumBoom() && thisPlayer[s]->flagBoom[i])
			{
				if(thisBoom[(thisPlayer[s]->getID() - 1)*MAXBOOM + i]->getTime()==20 && sound == 1)	PlaySound(TEXT("rs/audio/2.wav"), NULL, SND_FILENAME | SND_ASYNC);
				thisBoom[(thisPlayer[s]->getID() - 1)*MAXBOOM + i]->updateTime();
				thisBoom[(thisPlayer[s]->getID() - 1)*MAXBOOM + i]->show(thisPlayer[s]->getID());
				if (thisBoom[(thisPlayer[s]->getID() - 1)*MAXBOOM + i]->checkExplode())
				{
					thisPlayer[s]->flagBoom[i] = 0;
					thisPlayer[s]->setUsedBoom(thisPlayer[s]->getUsedBoom() - 1);
					thisMap->set(thisBoom[(thisPlayer[s]->getID() - 1)*MAXBOOM + i]->getX(), thisBoom[(thisPlayer[s]->getID() - 1)*MAXBOOM + i]->getY(), EMPTY);
				}
			}
			if (i < thisPlayer[t]->getNumBoom() && thisPlayer[t]->flagBoom[i])
			{
				if (thisBoom[(thisPlayer[t]->getID() - 1)*MAXBOOM + i]->getTime() == 20 && sound == 1) PlaySound(TEXT("rs/audio/2.wav"), NULL, SND_FILENAME | SND_ASYNC);
				thisBoom[(thisPlayer[t]->getID() - 1)*MAXBOOM + i]->updateTime();
				thisBoom[(thisPlayer[t]->getID() - 1)*MAXBOOM + i]->show(thisPlayer[t]->getID());
				if (thisBoom[(thisPlayer[t]->getID() - 1)*MAXBOOM + i]->checkExplode())
				{
					thisPlayer[t]->flagBoom[i] = 0;
					thisPlayer[t]->setUsedBoom(thisPlayer[t]->getUsedBoom() - 1);
					thisMap->set(thisBoom[(thisPlayer[t]->getID() - 1)*MAXBOOM + i]->getX(), thisBoom[(thisPlayer[t]->getID() - 1)*MAXBOOM + i]->getY(), EMPTY);
				}
			}
			
			// Push boom
				// Update status
			if (thisBoom[(thisPlayer[t]->getID() - 1)*MAXBOOM + i]->getX() == thisPlayer[t]->getX() + xT
				&& thisBoom[(thisPlayer[t]->getID() - 1)*MAXBOOM + i]->getY() == thisPlayer[t]->getY() + yT) 
			{
				thisBoom[(thisPlayer[t]->getID() - 1)*MAXBOOM + i]->setStatus(moveoft);
			}
			
			if (thisBoom[(thisPlayer[s]->getID() - 1)*MAXBOOM + i]->getX() == thisPlayer[s]->getX() + xS 
				&& thisBoom[(thisPlayer[s]->getID() - 1)*MAXBOOM + i]->getY() == thisPlayer[s]->getY() + yS)
				thisBoom[(thisPlayer[s]->getID() - 1)*MAXBOOM + i]->setStatus(moveofs);
				// Boom move
			thisBoom[(thisPlayer[t]->getID() - 1)*MAXBOOM + i]->move(thisPlayer[t]->getID());
			thisBoom[(thisPlayer[s]->getID() - 1)*MAXBOOM + i]->move(thisPlayer[s]->getID());
		}

		Sleep(100);
	}
}

void game::play()
{
	// Play music
	char* errorString = new char[MAXERRORLENGTH];
	mciGetErrorStringA(mciSendStringA("open \"rs/audio/1.wav\" type mpegvideo alias music", nullptr, 0, nullptr), errorString, MAXERRORLENGTH);
	mciGetErrorStringA(mciSendStringA("play music repeat", nullptr, 0, nullptr), errorString, MAXERRORLENGTH);
	menuLoop();
}

int game::gameOver(int ID)
{
	int high = 178;
	int c = 0;

	if (ID != 0)
	{
		drawBmp(25, 150, imgTextPlayer);
		drawBmp(400, 150, imgFrame);
		drawBmp(490, 150, imgTextWin);
	}
	while (1)
	{
		
		c++;
		if (ID == 2)
		{

			high < 178 ? high++ : high > 168? high-- : high++;
			Sleep(100);
			drawBmp(418, high, imgTrans);
			drawBmp(418, high, imgPlayer[c % 8]);
			if (GetAsyncKeyState(13)) return 1;
		}
		else if (ID == 1)
		{
			high < 178 ? high++ : high > 168 ? high-- : high++;
			Sleep(100);
			drawBmp(418, high, imgTrans);
			drawBmp(418, high, imgPlayer[c % 8 + 8]);
			if (GetAsyncKeyState(13)) return 1;
		}
		else if (ID == 3)
		{
			if (GetAsyncKeyState(13)) return 1;
		}
		else
		{
			return 0;
		}
	}
}

void game::chooseMap() 
{
	srand(time(NULL));
	system("cls");
	Img mapViewer[8];
	loadBmp(mapViewer[0], "rs/img/map/beach.bmp");
	loadBmp(mapViewer[1], "rs/img/map/city.bmp");
	loadBmp(mapViewer[2], "rs/img/map/classic.bmp");
	loadBmp(mapViewer[3], "rs/img/map/desert.bmp");
	loadBmp(mapViewer[4], "rs/img/map/forest.bmp");
	loadBmp(mapViewer[5], "rs/img/map/tunel.bmp");
	loadBmp(mapViewer[6], "rs/img/map/winter.bmp");
	loadBmp(mapViewer[7], "rs/img/map/farm.bmp");

	drawBmp(50, 30, mapViewer[0]);
	drawBmp(50 + 300 * 1, 30, mapViewer[1]);
	drawBmp(50 + 300 * 2, 30, mapViewer[2]);

	drawBmp(50, 30 + 150, mapViewer[3]);
	drawBmp(50 + 300 * 1, 30 + 150, mapViewer[4]);
	drawBmp(50 + 300 * 2, 30 + 150, mapViewer[5]);

	drawBmp(50, 30 + 150 * 2, mapViewer[6]);
	drawBmp(50 + 300, 30 + 150 * 2, mapViewer[7]);


	int choose = 0;
	int c = 0;
	int high[9] = { 49, 49, 49, 199, 199, 199, 349 , 349 , 349};
	int wide[9] = { 124, 424, 124 + 300 * 2, 124, 124 + 300, 124 + 300 * 2, 124, 124 + 300, 124 + 300*2 };

	while (true)
	{
		c++;

		Sleep(100);
		drawBmp(wide[choose], high[choose], imgTrans);
		drawBmp(wide[choose], high[choose], imgPlayer[c % 8]);
		drawBmp(wide[choose] - 110, high[choose], imgTrans);
		drawBmp(wide[choose] - 110, high[choose], imgPlayer[c % 8 + 8]);
		drawBmp(50 + 300*2, 30 + 150 * 2, mapViewer[c % 7]);

		if (GetAsyncKeyState(key[1]))
		{
			drawBmp(wide[choose], high[choose], imgTrans);
			drawBmp(wide[choose] - 110, high[choose], imgTrans);
			choose += 3;
		}
		if (GetAsyncKeyState(key[0]))
		{
			drawBmp(wide[choose], high[choose], imgTrans);
			drawBmp(wide[choose] - 110, high[choose], imgTrans);
			choose -= 3;
		}
		if (GetAsyncKeyState(key[2]))
		{
			drawBmp(wide[choose], high[choose], imgTrans);
			drawBmp(wide[choose] - 110, high[choose], imgTrans);
			choose -= 1;
		}
		if (GetAsyncKeyState(key[3]))
		{
			drawBmp(wide[choose], high[choose], imgTrans);
			drawBmp(wide[choose] - 110, high[choose], imgTrans);
			choose += 1;
		}
		if (GetAsyncKeyState(key[9]))
		{
			while (true)
			{
				switch (choose)
				{
				case 0: strcpy_s(typeMap, 10, "beach"); return;
				case 1: strcpy_s(typeMap, 10, "city"); return;
				case 2: strcpy_s(typeMap, 10, "classic"); return;
				case 3: strcpy_s(typeMap, 10, "desert"); return;
				case 4: strcpy_s(typeMap, 10, "forest"); return;
				case 5: strcpy_s(typeMap, 10, "tunel"); return;
				case 6: strcpy_s(typeMap, 10, "winter"); return;
				case 7: strcpy_s(typeMap, 10, "farm"); return;
				case 8:
					choose = rand() % 7;
				}
			}
		}
		if (choose < 0)
		{
			choose = 8;
		}
		if (choose > 8)
		{
			choose = 0;
		}
	}
}