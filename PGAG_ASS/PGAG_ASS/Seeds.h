#ifndef SEED_H
#define SEED_H
#include "Texture.h"
#include "Camera.h"
#include "Player.h"
class Seeds : public Texture
{
public:
	///Virtual function re-defined to suit the seeds.
	void Draw( Camera *c, SDL_Renderer *r){
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
	///Gets the position based on an X,y basis
	Vec2 getPos();
	///Sets the position based on an X,y basis
	void setPos(Vec2 p);
	///if the seed is currently active
	bool isActive;
	///Updates based on the player
	void update(Player *p);
private:
	///Private Variables
	///Vec2's
	Vec2 Position;
};
#endif ///!SEED_H
