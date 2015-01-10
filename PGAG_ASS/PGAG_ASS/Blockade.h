#ifndef BLOCKADE_H
#define BLOCKADE_H
//------------------------------------------------------------------
/// \file    Blockade.h
/// \author  Lloyd Phillips
/// \brief   This is the Blockade class
//------------------------------------------------------------------
#include "Texture.h"
#include "Player.h"
#include "Camera.h"
class Blockade :public Texture{
public:
	/// \brief Constructor
	Blockade();
	/// \brief Destructor
	~Blockade();
	/// \brief Virtual Function for drawing the texture
	/// \re-defined to suit blockade takes the Camera and the renderer
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
	/// \brief returns the position in form of, x,y,w,h
	SDL_Rect getPosition();
	/// \brief Sets the position in form of x,y,w,h
	void setPosition(SDL_Rect p);
	/// \brief Updates the blockade
	/// \Update taking in the player for collision.
	void update(Player *P);
private:
	SDL_Rect Position; ///<Position of the Blockade in form of x,y,w,h
};

#endif /// !BLOCKADE_H
