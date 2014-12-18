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
		Uint32 tempSeconds = current / 100;
		float spriteJumping = tempSeconds % 15;
		float spriteWalking = tempSeconds % 4;
		switch (stance)
		{
		case 0:
			RenderSize.x = 0;
			RenderSize.y = 272;
			break;
		case 1:
			RenderSize.x = spriteWalking * 77;
			RenderSize.y = 136;
			break;
		case 2:
			RenderSize.x = spriteWalking * 77;
			RenderSize.y = 136;
			break;
		case 3:
			RenderSize.x = spriteJumping * 77;
			RenderSize.y = 0;
			break;
		}
		SDL_Rect TextureSize;
		TextureSize.x = texturePosition.x;
		TextureSize.y = texturePosition.y;
		TextureSize.h = height;
		TextureSize.w = width;
		RenderSize.h = height;
		RenderSize.w = width;
		SDL_RenderCopy(r, Texture::getText(), &RenderSize, &TextureSize);
	}
	
	void movement(float DT);
	Vec2 getPos();
	void setPos(Vec2 p);
	Vec2 getVel();
	void setVel(Vec2 v);
	bool movingL, movingR, isJumping, idle, onGround;
	

private:
	Vec2 pos;
	Vec2 vel;
	int stance;
};

