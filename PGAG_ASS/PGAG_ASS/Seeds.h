#pragma once
#include "Texture.h"
class Seeds : public Texture
{
public:
	void Seeds::Draw( int width, int height, int rand, SDL_Renderer *r){
		unsigned int current = SDL_GetTicks();
		SDL_Rect RenderSize;
		SDL_Rect TextureSize;
		float temp = (current / 100) % 4;

		switch (rand){
		case 0:
			TextureSize.x = pos1;
			POS = pos1;
			break;
		case 1:
			TextureSize.x = pos2;
			POS = pos2;
			break;
		case 2:
			TextureSize.x = pos3;
			POS = pos3;
			break;
		case 3:
			TextureSize.x = pos4;
			POS = pos4;
			break;
		}
		RenderSize.x = temp *17.4;
		RenderSize.y = 0;
		TextureSize.y = 700;
		TextureSize.h = height;
		TextureSize.w = width;
		RenderSize.h = height;
		RenderSize.w = width;
		SDL_RenderCopy(r, Texture::getText(), &RenderSize, &TextureSize);
	}
	Seeds();
	~Seeds();
	int pos1, pos2, pos3, pos4;
	int POS;
private:
	
};

