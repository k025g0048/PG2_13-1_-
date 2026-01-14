#include <Novice.h>
#include "Enemy.h"
#include "player.h"
#include "bullet.h"
#include <math.h>

const char kWindowTitle[] = "LC1C_07_カナザシ_レイジ_";

int Enemy::isAlive;
int Enemy::respawnTime;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player* player = new Player();

	
	Enemy* enemyA = new Enemy();
	Enemy* enemyB = new Enemy();

	enemyA->posY = 100;
	enemyA->posX = 50;



	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);



		///
		/// ↓更新処理ここから
		///

		player->Update(keys, preKeys);

		

		if (Enemy::isAlive)
		{
		
			enemyA->Update();
			enemyB->Update();

			for (int i = 0;i < 10;i++)
			{

				if (enemyA->radius + player->bullet[i]->radius > sqrtf((float)(pow(player->bullet[i]->posx - enemyA->posX, 2) + pow(player->bullet[i]->posy - enemyA->posY, 2))))
				{
					Enemy::isAlive = false;
					Enemy::respawnTime = 0;
				}
			}

			for (int i = 0;i < 10;i++)
			{

				if (enemyB->radius + player->bullet[i]->radius > sqrtf((float)(pow(player->bullet[i]->posx - enemyB->posX, 2) + pow(player->bullet[i]->posy - enemyB->posY, 2))))
				{
					Enemy::isAlive = false;
					Enemy::respawnTime = 0;
				}
			}

		}
		else
		{
			if (Enemy::respawnTime < 60)
			{
				Enemy::respawnTime++;
			}
			else
			{
				Enemy::isAlive = true;
			}
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		player->Draw();

		if(Enemy::isAlive)
		{
			enemyA->Draw();
			enemyB->Draw();
		}
		

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
