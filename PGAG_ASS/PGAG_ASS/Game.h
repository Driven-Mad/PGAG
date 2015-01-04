#ifndef GAME_H
#define GAME_H
#include <SDL.h>
#include <iostream>
#include "Seeds.h"
#include "Vec2.h"
#include "Player.h"
#include "Texture.h"
#include "Enemy.h"
#include "Camera.h"
#include "Blockade.h"
#include "Rope.h"
#include "Diamond.h"
class Game{
public:
	Game();
	~Game();
	///Returns a renderer
	SDL_Renderer* init();
	bool running(SDL_Renderer* rend);
private:
};
#endif ///!GAME_H

