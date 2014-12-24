#pragma once
#include "Texture.h"
#include "Vec2.h"
#include "Player.h"
class Enemy : public Texture
{
public:
	void Enemy::Draw(Vec2 Texturesize, int width, int height, SDL_Renderer *r){
		unsigned int current = SDL_GetTicks();
		SDL_Rect RenderSize;
		SDL_Rect TextureSize;
		float temp = float((current / 100) % 6);
		float temp2 = float((current / 100) % 4);
		float temp3 = float((current / 100) % 3);
		if (movingL){
			RenderSize.x = int(temp * 100);
			RenderSize.y = 440;
		}
		if (movingR){
			RenderSize.x = int(temp * 100);
			RenderSize.y = 70;
		}
		if (attackL){
			RenderSize.x = int(temp2 * 100);
			RenderSize.y =135;
		}
		if (attackL){
			RenderSize.x = int(temp2 * 100);
			RenderSize.y = 500;
		}
		if (idle){
			RenderSize.x = int(temp3 * 100);
			RenderSize.y = 0;
		}
		RenderSize.h = height;
		RenderSize.w = width;
		TextureSize.x = int(Texturesize.x);
		TextureSize.y = int(Texturesize.y);
		TextureSize.h = height;
		TextureSize.w = width;
		SDL_RenderCopy(r, Texture::getText(), &RenderSize, &TextureSize);
	}
	int update(float pos, float DT, int health);
	Vec2 getPos();
	Enemy();
	~Enemy();
private:
	int health;
	bool startTimer;
	Vec2 Position, Vel;
	bool recentlyAttacked;
	bool movingL, movingR, idle, attackL, attackR;
	int timer;

};

