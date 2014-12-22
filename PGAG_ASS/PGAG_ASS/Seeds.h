#pragma once
#include "Texture.h"
class Seeds : public Texture
{
public:
	void Seeds::Draw( Vec2 pos, int width, int height, int rand, SDL_Renderer *r){
		unsigned int current = SDL_GetTicks();
		SDL_Rect RenderSize;
		SDL_Rect TextureSize;
		float temp = (current / 100) % 4;
		
		RenderSize.x = temp *17.4;
		RenderSize.y = 0;
		RenderSize.h = height;
		RenderSize.w = width;
		TextureSize.x = pos.x;
		TextureSize.y = pos.y;
		TextureSize.h = height;
		TextureSize.w = width;

		SDL_RenderCopy(r, Texture::getText(), &RenderSize, &TextureSize);
	}
	Seeds();
	~Seeds();
	Vec2 getPos();
	void setPos(Vec2 p);
	bool isActive;
private:
	Vec2 Position;
};

