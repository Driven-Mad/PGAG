#pragma once
#include <SDL.h>
#include "Texture.h"
class Game : public Texture
{

public:
	Game();
	~Game();
	//void Player::Draw(Vec2 texturePosition, int width, int height, SDL_Renderer *r){
	//	unsigned int current = SDL_GetTicks();
	//	SDL_Rect RenderSize;
	//	Uint32 tempSeconds = current / 100;
	//	float spriteJumping = tempSeconds % 15;
	//	float spriteWalking = tempSeconds % 4;
	//	switch (stance)
	//	{
	//	case 0:
	//		RenderSize.x = 0;
	//		RenderSize.y = 272;
	//		break;
	//	case 1:
	//		RenderSize.x = spriteWalking * 77;
	//		RenderSize.y = 136;
	//		break;
	//	case 2:
	//		RenderSize.x = spriteWalking * 77;
	//		RenderSize.y = 136;
	//		break;
	//	case 3:
	//		RenderSize.x = spriteJumping * 77;
	//		RenderSize.y = 0;
	//		break;
	//	}
	//	SDL_Rect TextureSize;
	//	TextureSize.x = texturePosition.x;
	//	TextureSize.y = texturePosition.y;
	//	TextureSize.h = height;
	//	TextureSize.w = width;
	//	RenderSize.h = height;
	//	RenderSize.w = width;
	//	SDL_RenderCopy(r, Texture::getText(), &RenderSize, &TextureSize);
	//}
	float* getDT();
	void updateTimer();
	SDL_Renderer* init();
	void draw(SDL_Renderer *R);
	void update();

private:
	unsigned int lastTime;
	unsigned int current;
	float DT;
	int levelx = 0, levely = 0, levelWid = 2048, levelLen = 1536;
	int winX = 100, winY = 100, winWid = 1024, winLen = 768;


};

