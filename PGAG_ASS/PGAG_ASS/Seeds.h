#ifndef SEED_H
#define SEED_H
#include "Texture.h"
#include "Camera.h"
#include "Player.h"
class Seeds : public Texture
{
public:
	void Seeds::Draw( Camera *c, SDL_Renderer *r){
		unsigned int current = SDL_GetTicks();
		SDL_Rect RenderSize;
		SDL_Rect TextureSize;
		float temp = float((current / 100) % 4);
		
		RenderSize.x = int(temp *17.4);
		RenderSize.y = 0;
		RenderSize.h = 17;
		RenderSize.w = 17;
		TextureSize.x = int(Position.x - c->getPos().x);
		TextureSize.y = int(Position.y);
		TextureSize.h = 17;
		TextureSize.w = 17;

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
#endif
