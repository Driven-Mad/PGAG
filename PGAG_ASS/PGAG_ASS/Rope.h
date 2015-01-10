//------------------------------------------------------------------
/// \file    Rope.h
/// \author  Lloyd Phillips
/// \brief   This is the Rope class, inherits from the Texture class
//------------------------------------------------------------------
#ifndef ROPE_H
#define ROPE_H
#include "Texture.h"
#include "Player.h"
#include "Camera.h"
#include "Blockade.h"
class Rope :public Texture{
public:
	/// \brief Constructor
	Rope();
	/// \brief destructor
	~Rope();
	/// \brief Virtual Function for drawing the texture
	/// \re-defined to suit rope takes the Camera, renderer
	void Draw(Camera *c, SDL_Renderer *r){
		SDL_Rect TextureSize;
		TextureSize.x = int(pos.x - c->getPos().x);
		TextureSize.y = int(pos.y);
		TextureSize.h = 376;
		TextureSize.w = 16;
		SDL_RenderCopy(r, Texture::getText(), &RenderSize, &TextureSize);
	}
	/// \brief sets the position, on a x,y basis
	void setPos(Vec2 p);
	/// \brief returns a position, on a x,y basis
	Vec2 getPos();
	/// \brief Set's Render.x box
	void setRenderX(int x);
	/// \brief Updates the diamond
	/// \Update taking in the player for collision.
	void update(Player *p);
	bool isDown;///< If the rope has come all the way down!
private:
	int stance = 0, timer; ///<Stance and Timer
	Vec2 pos; ///<Position of the Rope
	SDL_Rect RenderSize; ///<RenderSize of the Rope
};
#endif ///!ROPE_H


