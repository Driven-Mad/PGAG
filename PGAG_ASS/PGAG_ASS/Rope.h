#ifndef ROPE_H
#define ROPE_H
#include "Texture.h"
#include "Player.h"
#include "Camera.h"
#include "Blockade.h"
class Rope :public Texture{
public:
	Rope();
	~Rope();
	void setPos(Vec2 p);
	Vec2 getPos();
	void setRenderX(int x);
	void update(Player *p);
	void Rope::Draw(Camera *c, SDL_Renderer *r){
		SDL_Rect TextureSize;
		TextureSize.x = int(pos.x - c->getPos().x);
		TextureSize.y = int(pos.y);
		TextureSize.h = 376;
		TextureSize.w = 16;
		SDL_RenderCopy(r, Texture::getText(), &RenderSize, &TextureSize);
	}
	bool isDown;
private:
	int stance = 0, timer;
	Vec2 pos;
	SDL_Rect RenderSize;
};
#endif


