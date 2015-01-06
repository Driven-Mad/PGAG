#pragma once
#include <SDL.h>
#include "Vec2.h"
#include "Player.h"
#include <iostream>
#include "Rope.h"
#include "Camera.h"
class Light
{
public:
	Light();
	~Light();
	void update(float DT, SDL_Renderer *rend, Player *p, Camera *c, Rope *r);
	SDL_Point pixel;
	bool switched;
private:
	Vec2 pos, vel;
};

