#ifndef GAME_H
#define GAME_H
#include <SDL.h>
#include <iostream>
class Game{
public:
	Game();
	~Game();
	///Returns a renderer
	SDL_Renderer* init();
private:
};
#endif ///!GAME_H

