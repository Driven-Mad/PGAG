#pragma once
#include "Texture.h"
#include "Vec2.h"
#include <SDL.h>

class Player : public Texture
{
	
public:
	Player();
	~Player();
	void Player::Draw(Vec2 texturePosition, int width, int height, SDL_Renderer *r){
		unsigned int current = SDL_GetTicks();
		SDL_Rect RenderSize;
		Uint32 tempSeconds = Uint32(current / 100);
		float spriteJumping = float(tempSeconds % 15);
		float spriteWalking = float(tempSeconds % 4);
		switch (stance)
		{
		case 0:
			RenderSize.x = 0;
			RenderSize.y = 272;
			break;
		case 1:
			RenderSize.x = int(spriteWalking * 77);
			RenderSize.y = 136;
			break;
		case 2:
			RenderSize.x = int(spriteWalking * 77);
			RenderSize.y = 136;
			break;
		case 3:
			RenderSize.x = int(spriteJumping * 77);
			RenderSize.y = 0;
			break;
		}
		SDL_Rect TextureSize;
		TextureSize.x = int(texturePosition.x);
		TextureSize.y = int(texturePosition.y);
		TextureSize.h = height;
		TextureSize.w = width;
		RenderSize.h = height;
		RenderSize.w = width;
		SDL_RenderCopy(r, Texture::getText(), &RenderSize, &TextureSize);
	}
	
	void update(float DT);
	Vec2 getPos();
	void setPos(Vec2 p);
	Vec2 getVel();

	void setVel(Vec2 v);
	bool movingL, movingR, isJumping, idle, onGround;
	int getHealth();
	void setHealth(int i);
	int getMagic();
	void setMagic(int i);
	int health;

private:
	Vec2 oldPos;
	Vec2 pos;
	Vec2 vel;
	int stance;
	int magic;
};

