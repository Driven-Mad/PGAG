#include <iostream>
#include <SDL.h>
#include "Vec2.h"
#include "Texture.h"

int main(int argc, char *argv[]){
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
		return -1;
	}
	int x = 1;

	SDL_Renderer *rend = SDL_CreateRenderer(window, -1, 0);
	///Create our BackGround
	Texture *BackGround = new Texture();
	BackGround->setfilename("Space.bmp");
	BackGround->createTexture(rend);

	Texture *Player = new Texture();
	Player->setfilename("Tree.bmp");
	Player->createTexture(rend);


	bool playing = true;
	while (playing){
		SDL_Event incoming;
		for (int i = 0; i<10000000; i++)
		{
			if (i == 9999999){
				x++;
			}
		}
		
		if (x > 16)
		{
			x = 1;
		}
		while (SDL_PollEvent(&incoming)){
			switch (incoming.type){
			case SDL_QUIT:
				playing = false;
				break;
			}
		}
		
		///Sets background default colour (not accustom to Hex so using default from labs)
		SDL_SetRenderDrawColor(rend, 0xFF, 0x0, 0x0, 0xFF);
		SDL_RenderClear(rend);
		///Draw my background to the screen
		BackGround->Draw(0, 0,winWid,winLen,0,0,winWid,winLen, rend);
		
			switch (x)
			{
			case 1:
				Player->Draw(0, 0, 77, 132, 0, 123, 77, 132, rend);
				break;
			case 2:
				Player->Draw(0, 0, 77, 132, 77, 123, 77, 132, rend);
				break;
			case 3:
				Player->Draw(0, 0, 77, 132, 154, 123, 77, 132, rend);
				break;
			case 4:
				Player->Draw(0, 0, 77, 132, 231, 123, 77, 132, rend);
				break;
			case 5:
				Player->Draw(0, 0, 77, 132, 308, 123, 77, 132, rend);
				break;
			case 6:
				Player->Draw(0, 0, 77, 132, 385, 123, 77, 132, rend);
				break;
			case 7:
				Player->Draw(0, 0, 77, 132, 462, 123, 77, 132, rend);
				break;
			case 8:
				Player->Draw(0, 0, 77, 132, 539, 123, 77, 132, rend);
				break;
			case 9:
				Player->Draw(0, 0, 77, 132, 0, 260, 77, 132, rend);
				break;
			case 10:
				Player->Draw(0, 0, 77, 132, 77, 260, 77, 132, rend);
				break;
			case 11:
				Player->Draw(0, 0, 77, 132, 154, 260, 77, 132, rend);
				break;
			case 12:
				Player->Draw(0, 0, 77, 132, 231, 260, 77, 132, rend);
				break;
			case 13:
				Player->Draw(0, 0, 77, 132, 308, 260, 77, 132, rend);
				break;
			case 14:
				Player->Draw(0, 0, 77, 132, 385, 260, 77, 132, rend);
				break;
			case 15:
				Player->Draw(0, 0, 77, 132, 462, 260, 77, 132, rend);
				break;
			case 16:
				Player->Draw(0, 0, 77, 132, 539, 260, 77, 132, rend);
				break;
		}
			
		SDL_RenderPresent(rend);
	}
	///pause before we leave
	SDL_Delay(2000);
	///destroy and quit out of window
	delete Player;
	delete BackGround;
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}