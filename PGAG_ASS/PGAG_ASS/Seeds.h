#ifndef SEED_H
#define SEED_H
//------------------------------------------------------------------
/// \file    Seeds.h
/// \author  Lloyd Phillips
/// \brief   This is the Seeds class, inherits from the Texture class
//------------------------------------------------------------------
#include "Texture.h"
#include "Camera.h"
#include "Player.h"
class Seeds : public Texture
{
public:
	/// \brief Constructor
	Seeds();
	/// \brief destructor
	~Seeds();
	/// \brief Virtual Function for drawing the texture
	/// \re-defined to suit seeds takes the Camera, renderer
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
	/// \brief Gets the position based on an X,y basis
	Vec2 getPos();
	/// \brief Sets the position based on an X,y basis
	void setPos(Vec2 p);
	/// \brief Updates the Seeds
	/// \Update taking in the player for collision.
	void update(Player *p);
	bool isActive; ///< if the seed is currently active
private:
	Vec2 Position; ///< Position of the Seed
};
#endif ///!SEED_H
