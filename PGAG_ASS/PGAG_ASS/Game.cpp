#include "Game.h"
#include <iostream>

Game::Game(){
	
	//DT = 0.0f;
	unsigned int lastTime = SDL_GetTicks();
}


Game::~Game(){

}
SDL_Renderer* Game::init(){
	SDL_Window *window;
	///Initialise Video
	SDL_Init(SDL_INIT_VIDEO);
	///create alterable varibales for quick change and later use.
	int levelx = 0, levely = 0, levelWid = 2048, levelLen = 1536;
	int winX = 100, winY = 100, winWid = 1024, winLen = 768;
	///Create window using pointer, and SDL
	window = SDL_CreateWindow("Magical world", winX, winY, winWid, winLen,
		SDL_WINDOW_OPENGL);
	///Error tracking
	if (window == NULL){
		std::printf("GOOD LAWD YOU SUCK");
		SDL_Quit;
	}

	SDL_Renderer *rend = SDL_CreateRenderer(window, -1, 0);
	return rend;
}
void Game::draw(SDL_Renderer *R)
{
}

void Game::updateTimer(){
	unsigned int current = SDL_GetTicks();
	float DT = (float)(current - lastTime) / 100000.0f;
	lastTime = current;
}

float* Game::getDT()
{
	return &DT;
}