#pragma once

class  Bullet
{
public:
	Bullet();
	int posx;
	int posy;
	int radius;
	int speed;
	bool isShot;

	void Update();
	void Draw();

};