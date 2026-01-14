#pragma once

#pragma once

class Enemy
{
public:

	Enemy();
	void Update();
	void Draw();

	static int isAlive;
	static int respawnTime;
	int posX;
	int posY;
	int speed;
	int radius;


};