#pragma once
#include "Bullet.h"

class Player
{
public:
	int posx;
	int posy;
	int radius;
	int speed;

	Player();
	~Player();
	void Update(char* keys, char* preKeys);
	void Draw();

public:
	Bullet* bullet[10];
};