#ifndef BLOCKADE_H
#define BLOCKADE_H
#include "Texture.h"
#include "Player.h"
#include "Camera.h"
class Blockade :public Texture{
public:
	Blockade();
	~Blockade();
	///Virtual Function from Texture re-defined to suit blockade
	void Draw(Camera *C, SDL_Renderer *r){
		SDL_Rect TextureSize;
		TextureSize.x = int(Position.x - C->getPos().x);
		TextureSize.y = int(Position.y);
		TextureSize.h = Position.h;
		TextureSize.w = Position.w;
		SDL_Rect RenderSize;
		RenderSize.x = int(0);
		RenderSize.y = int(0);
		RenderSize.h = 72;
		RenderSize.w = 2048;
		SDL_RenderCopy(r, Texture::getText(), &RenderSize, &TextureSize);
	}
	///returns the position (in form of, x,y,w,h
	SDL_Rect getPosition();
	///Set the position in form of x,y,w,h
	void setPosition(SDL_Rect p);
	///Update taking in the player.
	void update(Player *P);
private:
	///Private Variables
	///SDL_Rect's
	SDL_Rect Position;
};

#endif /// !BLOCKADE_H
