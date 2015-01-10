//------------------------------------------------------------------
/// \file    Diamond.h
/// \author  Lloyd Phillips
/// \brief   This is the diamond class, Inherits from Texture class
//------------------------------------------------------------------
#ifndef DIAMOND_H
#define DIAMOND_H
#include "Texture.h"
#include "Camera.h"
#include "Blockade.h"

class Diamond : public Texture
{
public:
	/// \brief Constructor
	Diamond();
	/// \brief destructor
	~Diamond();
	/// \brief Virtual Function for drawing the texture
	/// \re-defined to suit diamond takes the Camera, renderer and blockade
	void Draw(Blockade *b, Camera *c, SDL_Renderer *r){
		unsigned int current = SDL_GetTicks();
		Uint32 tempSeconds = Uint32(current / 100);
		float diamondSparkle = float(tempSeconds % 4);
		SDL_Rect TextureSize;
		TextureSize.x = int(b->getPosition().x - c->getPos().x + 100);
		pos.y = float(TextureSize.y = int(b->getPosition().y - 40));
		TextureSize.h = 57;
		TextureSize.w = 45;
		SDL_Rect RenderSize;
		RenderSize.x = int(46.5 * diamondSparkle);
		RenderSize.y = 0;
		RenderSize.h = 57;
		RenderSize.w = 45;
		SDL_RenderCopy(r, Texture::getText(), &RenderSize, &TextureSize);
		pos.x = b->getPosition().x + 100.0f;
	}
	/// \brief Updates the diamond
	/// \Update taking in the player for collision.
	void update(Player *p);
	/// \brief returns the position in form of, x,y
	Vec2 getPos();
	/// \brief sets the position in form of, x,y
	void setPos(Vec2 p);
	/// \brief public boolian if the diamond has been collected
	bool collected;
private:
	Vec2 pos; ///<Position of the Diamond in form x,y
};
#endif ///!DIAMOND_H
