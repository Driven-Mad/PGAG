#pragma once
#include "Texture.h"
#include "Camera.h"
#include "Blockade.h"
class Diamond : public Texture
{
public:
	Diamond();
	~Diamond();
	void Diamond::Draw(Blockade *b, Camera *c, SDL_Renderer *r){
		unsigned int current = SDL_GetTicks();
		Uint32 tempSeconds = Uint32(current / 100);
		float diamondSparkle = float(tempSeconds % 4);
		SDL_Rect TextureSize;
		TextureSize.x = b->getPosition().x - c->getPos().x + 100;
		TextureSize.y = pos.y = b->getPosition().y - 40;
		TextureSize.h = 57;
		TextureSize.w = 44.5;
		SDL_Rect RenderSize;
		RenderSize.x = int(46.5 * diamondSparkle);
		RenderSize.y = 0;
		RenderSize.h = 57;
		RenderSize.w = 44.5;
		SDL_RenderCopy(r, Texture::getText(), &RenderSize, &TextureSize);
		pos.x = b->getPosition().x + 100;
	}
	void update(Player *p);
	Vec2 getPos();
	void setPos(Vec2 p);
	bool collected;
private:
	Vec2 pos;
};

