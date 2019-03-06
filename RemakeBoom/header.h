#pragma once
#include "bmp.h"

const int key[10] = { 0x57 , 0x53, 0x41, 0x44, 32, 0x65, 0x62, 0x61, 0x63, 13 }; // up down left right

#define ROWMAP 11
#define COLMAP 11

#define EMPTY 0
#define ROCK -1
#define GROUND 0.5
#define HEART 3
#define BOOST 4
#define UPGRADE 1
#define GLOVE 2
#define ADDBOOM 5
#define PLAYER1 10
#define PLAYER2 11
#define BOOM1 80
#define BOOM2 81
#define EXPLODE 100

#define MAXBOOM 5
#define NUMPLAYER 2

#define BOOMTIMEEXPLODE1 20
#define BOOMTIMEEXPLODE2 22
#define BOOMTIMEEXPLODE3 24

extern Img imgSubins;
extern Img imgInstruction;
extern Img imgAuthor;
extern Img imgPlayer[16];
extern Img imgBoom[4];
extern Img imgExplode[6];
extern Img imgEmpty, imgGround, imgRock, imgExita, imgExitb, imgPlaya, imgPlayb, imgPanel, imgPlayc, imgExitc, imgInvincible;
extern Img imgItem[5];
extern Img imgTrans;
extern Img imgNumber[10];
extern Img imgTextPlayer;
extern Img imgTextWin;
extern Img imgGrave;
extern Img imgFrame;