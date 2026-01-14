#include "bullet.h"
#include <Novice.h>

Bullet::Bullet()
{
	posx = -100;
	posy = -100;
	radius = 10;
	speed = 10;
	isShot = true;
}

void Bullet::Update()
{
	if (isShot)
	{
		posy -= speed;

		if (posy < 0)
		{
			posy = -100;
			posx = -100;
			isShot = false;
		}
	}
}

void Bullet::Draw()
{
	Novice::DrawEllipse(
		posx, posy,
		radius, radius,
		0.0f,
		WHITE,
		kFillModeSolid
	);
}