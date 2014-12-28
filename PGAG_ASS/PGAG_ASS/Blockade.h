#ifndef BLOCKADE_H
#define BLOCKADE_H
#include "Texture.h"
#include "Player.h"
#include "Camera.h"
class Blockade :public Texture{
public:
	Blockade();
	~Blockade();
	void Blockade::Draw(Camera *C, SDL_Renderer *r){
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
		//SDL_QueryTexture(text, NULL, NULL, &des.w, &des.h);
		SDL_RenderCopy(r, Texture::getText(), &RenderSize, &TextureSize);
	}
	SDL_Rect getPosition();
	void setPosition(SDL_Rect p);
	void update(Player *P);
private:
	SDL_Rect Position;
};

#endif // !BLOCKADE_H
