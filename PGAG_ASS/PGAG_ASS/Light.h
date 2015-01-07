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
	Light(SDL_Renderer *r);
	~Light();
	void update(float DT, SDL_Renderer *rend, Player *p, Camera *c, Rope *r);
	SDL_Point pixel;
	bool switched;
private:
	Vec2 pos, vel;
	SDL_Surface *image;
	SDL_Texture *lightTexture;
	Uint8 x;
	bool increasing, decreasing;
};

