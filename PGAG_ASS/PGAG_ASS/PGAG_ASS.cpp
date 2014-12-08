#include <iostream>
#include <SDL.h>
#include "Vec2.h"
#include "Texture.h"

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
		return -1;
	}
	SDL_Renderer *rend = SDL_CreateRenderer(window, -1, 0);

	std::string filename("Space.bmp");
	SDL_Texture *g;
	Texture text;

	g = &text.createTexture(rend, filename);

	bool playing = true;
	while (playing)
	{
		SDL_Event incoming;
		while (SDL_PollEvent(&incoming))
		{
			switch (incoming.type)
			{
			case SDL_QUIT:
				playing = false;
				break;
			}
		}
		SDL_SetRenderDrawColor(rend, 0xFF, 0x0, 0x0, 0xFF);
		SDL_RenderClear(rend);

		SDL_Rect des;
		des.x = 0;
		des.y = 0;
		SDL_QueryTexture(g, NULL, NULL, &des.w, &des.h);
		SDL_RenderCopy(rend, g, NULL, &des);

		SDL_RenderPresent(rend);

	}
	///pause before we leave
	SDL_Delay(2000);
	///destroy and quit out of window
	SDL_DestroyTexture(g);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}