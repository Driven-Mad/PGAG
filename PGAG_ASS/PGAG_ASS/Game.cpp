#include "Game.h"
Game::Game(){
}
Game::~Game(){
}

////////////////////
///Creates a render/
////////////////////
SDL_Renderer* Game::init(){
	SDL_Window *window;
	///Initialise Video
	SDL_Init(SDL_INIT_VIDEO);
	///create alterable varibales for quick change and later use.
	int levelx = 0, levely = 0, levelWid = 2048, levelLen = 1536, winX = 100, winY = 100, winWid = 1024, winLen = 768;
	///Create window using pointer, and SDL
	window = SDL_CreateWindow("Magical world", winX, winY, winWid, winLen, SDL_WINDOW_OPENGL);
	///Error tracking
	if (window == NULL){
		std::printf("GOOD LAWD YOU SUCK");
		SDL_Quit;
	}
	///Create a renderer through creating a window
	SDL_Renderer *rend = SDL_CreateRenderer(window, -1, 0);
	return rend;
}