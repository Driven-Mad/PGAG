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
	///sets the position, on a x,y basis
	void setPos(Vec2 p);
	///returns a position, on a x,y basis
	Vec2 getPos();
	///Set's Render.x box
	void setRenderX(int x);
	///Update based on player
	void update(Player *p);
	///Draw function re-defined to suit the rope.
	void Rope::Draw(Camera *c, SDL_Renderer *r){
		SDL_Rect TextureSize;
		TextureSize.x = int(pos.x - c->getPos().x);
		TextureSize.y = int(pos.y);
		TextureSize.h = 376;
		TextureSize.w = 16;
		SDL_RenderCopy(r, Texture::getText(), &RenderSize, &TextureSize);
	}
	///If the rope has come all the way down!
	bool isDown;
private:
	///Private Variables
	///Int's
	int stance = 0, timer;
	///Vec2's
	Vec2 pos;
	///SDL_Rect's
	SDL_Rect RenderSize;
};
#endif ///!ROPE_H


