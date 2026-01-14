#include "player.h"
#include <Novice.h>

Player::Player()
{
	for (int i = 0;i < 10;i++)
	{
		bullet[i] = new Bullet;
	}
	posx = 100;
	posy = 100;
	radius = 30;
	speed = 4;
}

Player::~Player()
{
	for (int i = 0;i < 10;i++)
	{
		delete bullet[i];
	}
}

void Player::Update(char* keys, char* preKeys)
{
	if (keys[DIK_A])
	{
		posx -= speed;
	}

	if (keys[DIK_D])
	{
		posx += speed;
	}

	if (keys[DIK_W])
	{
		posy -= speed;
	}

	if (keys[DIK_S])
	{
		posy += speed;
	}


	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE])
	{
		for (int i = 0;i < 10;i++)
		{
			if (!bullet[i]->isShot)
			{
				bullet[i]->posy = posy;
				bullet[i]->posx = posx;
				bullet[i]->isShot = true;
				break;
			}
		}
	}

	for (int i = 0;i < 10;i++)
	{
		if (bullet[i]->isShot)
		{
			bullet[i]->Update();
		}
	}

}

void Player::Draw()
{
	Novice::DrawEllipse(
		posx, posy,
		radius, radius,
		0.0f,
		WHITE,
		kFillModeSolid
	);

	for (int i = 0;i < 10;i++)
	{
		bullet[i]->Draw();
	}
}
