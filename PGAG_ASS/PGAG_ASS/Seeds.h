#pragma once
#include "Texture.h"
#include "Player.h"
class Seeds : public Texture
{
public:
	void Seeds::Draw( Vec2 pos, int width, int height, int rand, SDL_Renderer *r){
		unsigned int current = SDL_GetTicks();
		SDL_Rect RenderSize;
		SDL_Rect TextureSize;
		float temp = float((current / 100) % 4);
		
		RenderSize.x = int(temp *17.4);
		RenderSize.y = 0;
		RenderSize.h = height;
		RenderSize.w = width;
		TextureSize.x = int(pos.x);
		TextureSize.y = int(pos.y);
		TextureSize.h = height;
		TextureSize.w = width;

		SDL_RenderCopy(r, Texture::getText(), &RenderSize, &TextureSize);
	}
	Seeds();
	~Seeds();
	Vec2 getPos();
	void setPos(Vec2 p);
	bool isActive;
	void update(Player *p);
private:
	Vec2 Position;
};

