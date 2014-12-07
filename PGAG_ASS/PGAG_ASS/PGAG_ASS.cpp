#include <iostream>
#include <SDL.h>
#include "Vec2.h"

int main(int argc, char *argv[])
{
	SDL_Window *window;
	///Initialise Video
	SDL_Init(SDL_INIT_VIDEO);
	///create alterable varibales for quick change and later use.
	int winX = 100;
	int winY = 100;
	int winWid = 1024;
	int winLen = 768;
	///Create window using pointer, and SDL
	window = SDL_CreateWindow("Magical world", winX, winY, winWid, winLen,
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_BORDERLESS);
	///Error tracking
	if (window == NULL){
		std::printf("GOOD LAWD YOU SUCK");
		return 1;
	}
	///pause before we leave
	SDL_Delay(2000);
	///destroy and quit out of window
	SDL_DestroyWindow(window);
	SDL_Quit();

}