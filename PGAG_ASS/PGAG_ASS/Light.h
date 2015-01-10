//------------------------------------------------------------------
/// \file    Light.h
/// \author  Lloyd Phillips
/// \brief   This is the Light class
//------------------------------------------------------------------
#pragma once
#include <SDL.h>
#include "Vec2.h"
#include "Player.h"
#include <iostream>
#include "Rope.h"
#include "Camera.h"
#include <SDL_image.h>
class Light
{
public:
	/// \brief Constructor
	/// \takes in the renderer
	Light(SDL_Renderer *r);
	/// \brief destructor
	~Light();
	/// \brief Updates the Lights
	/// \Update taking in the player,renderer,DT, camera, rope
	void update(float DT, SDL_Renderer *rend, Player *p, Camera *c, Rope *r);
	/// \brief public boolian if the light has switched direction
	bool switched;
private:
	Vec2 pos, vel; ///<Position and Velocity of the Diamond in form x,y
	SDL_Surface *image; ///<SDLSurface for Image
	SDL_Texture *lightTexture;///<SDLtexture for glow
	SDL_Texture *lightSolid; ///<SDLtexture for solid light
	Uint8 x; ///<IntX for range for Alpha Channel 
	bool increasing, decreasing; ///<Boolian for state of if Alpha is increasing/Decreasing
	int a,b; ///<Int a & b for random 
};

