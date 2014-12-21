#pragma once
#include "Texture.h"
#include "Vec2.h"
#include "Player.h"
class Enemy : public Texture
{
public:
	void Enemy::Draw(int width, int height, SDL_Renderer *r){
		unsigned int current = SDL_GetTicks();
		SDL_Rect RenderSize;
		SDL_Rect TextureSize;
		float temp = (current / 100) % 6;
		float temp2 = (current / 100) % 4;
		float temp3 = (current / 100) % 3;
		if (movingL){
			RenderSize.x = temp *100;
			RenderSize.y = 440;
		}
		if (movingR){
			RenderSize.x = temp * 100;
			RenderSize.y = 70;
		}
		if (attackL){
			RenderSize.x = temp2 * 100;
			RenderSize.y =135;
		}
		if (attackL){
			RenderSize.x = temp2 * 100;
			RenderSize.y = 500;
		}
		if (idle){
			RenderSize.x = temp3 * 100;
			RenderSize.y = 0;
		}
		RenderSize.h = height;
		RenderSize.w = width;
		TextureSize.x = Position.x;
		TextureSize.y = Position.y;
		TextureSize.h = height;
		TextureSize.w = width;
		SDL_RenderCopy(r, Texture::getText(), &RenderSize, &TextureSize);
	}
	int update(float pos, float DT, int health);

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

