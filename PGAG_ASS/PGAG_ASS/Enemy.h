//------------------------------------------------------------------
/// \file    Enemy.h
/// \author  Lloyd Phillips
/// \brief   This is the Enemy class, Inherits from Texture class
//------------------------------------------------------------------
#ifndef ENEMY_H
#define ENEMY_H
#include "Texture.h"
#include "Player.h"
#include "Camera.h"
#include "Diamond.h"
class Enemy : public Texture{
public:
	/// \brief Constructor
	Enemy();
	/// \brief destructor
	~Enemy();
	/// \brief Virtual Function for drawing the texture
	/// \re-defined to suit Enemy takes the Camera and renderer
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
	/// \brief Updates the Enemy
	/// \Update taking in the player for collision, delta time, and Diamonds.
	void update(Player *p, float DT, Diamond *d);
	/// \brief returns the position in form of, x,y
	Vec2 getPos();

private:
	Vec2 Position, Vel; ///<Position and Velocity of the Enemy
	int timer;///<A timer to help the enemy
	bool startTimer, recentlyAttacked, movingL, movingR, idle, attackL, attackR; ///<boolians for states of enemy
};
#endif ///!ENEMY_H
