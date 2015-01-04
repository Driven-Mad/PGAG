#ifndef ENEMY_H
#define ENEMY_H
#include "Texture.h"
#include "Player.h"
#include "Camera.h"
#include "Diamond.h"
class Enemy : public Texture{
public:
	Enemy();
	~Enemy();
	///Virtual function from Texture so it can be re-defiened
	void Draw(Camera *c, SDL_Renderer *r){
		unsigned int current = SDL_GetTicks();
		SDL_Rect RenderSize, TextureSize;
		float temp = float((current / 100) % 6), temp2 = float((current / 100) % 4), temp3 = float((current / 100) % 3);
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
		RenderSize.h = 70;
		RenderSize.w = 100;
		TextureSize.x = int(Position.x - c->getPos().x);
		TextureSize.y = int(Position.y);
		TextureSize.h = 70;
		TextureSize.w = 100;
		SDL_RenderCopy(r, Texture::getText(), &RenderSize, &TextureSize);
	}
	///Update function, taking in the players position, Delta Timer and health of player.
	void update(Player *p, float DT, Diamond *d);
	///Get the position of the enemy.
	Vec2 getPos();

private:
	///Private Variables
	///Vec2s
	Vec2 Position, Vel;
	///Ints
	int timer;
	///Bools
	bool startTimer, recentlyAttacked, movingL, movingR, idle, attackL, attackR;
};
#endif ///!ENEMY_H
