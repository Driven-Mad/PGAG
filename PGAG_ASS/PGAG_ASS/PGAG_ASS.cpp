#include <iostream>
#include <SDL.h>
#include "Vec2.h"
#include "Player.h"
#include "Texture.h"
#include "Game.h"

int main(int argc, char *argv[]){
	int levelx = 0, levely = 0, levelWid = 2048, levelLen = 1536;
	int winX = 100, winY = 100, winWid = 1024, winLen = 768;
	Game App;
	SDL_Renderer *rend = App.init();
	unsigned int lastTime = SDL_GetTicks();
	///Create our BackGround
	Texture *BackGround = new Texture();
	BackGround->setfilename("Space.bmp");
	BackGround->createTexture(rend);
	///Player
	Player *play = new Player();
	play->setfilename("Tree2.bmp");
	play->createTexture(rend);
	///Create a hill
	Texture *Hill = new Texture();
	Hill->setfilename("Hill.bmp");
	Hill->createTexture(rend);

	Texture *Health = new Texture();
	Health->setfilename("Health.bmp");
	Health->createTexture(rend);

	Texture *Magic = new Texture();
	Magic->setfilename("Magic.bmp");
	Magic->createTexture(rend);

	Texture *Seed = new Texture();
	Seed->setfilename("Seed.bmp");
	Seed->createTexture(rend);
	///Bool for play while loop;
	bool playing = true;
	while (playing){
		SDL_Event incoming;
		while (SDL_PollEvent(&incoming)){
			switch (incoming.type){
			case SDL_QUIT:
				playing = false;
				break;
			case SDL_KEYDOWN:
				switch (incoming.key.keysym.sym){
				case SDLK_LEFT:
					play->movingL = true;
					play->movingR = false;
					play->idle = false;
					break;
				case SDLK_RIGHT:
					play->movingR = true;
					play->movingL = false;
					play->idle = false;
					break;
				case SDLK_UP :
					play->isJumping = true;
					play->movingR = false;
					play->movingL = false;
					play->idle = false;
					break;
				default:
					play->idle = true;
					break;
				}
				break;
			case SDL_KEYUP:
				play->idle = true;
				play->movingL = false;
				play->movingR = false;
				play->isJumping = false;
				break;
			}
		}
		unsigned int current = SDL_GetTicks();
		float DT = (float)(current - lastTime) / 100000.0f;
		lastTime = current;
		
		
		///Sets background default colour (not accustom to Hex so using default from labs)
		SDL_SetRenderDrawColor(rend, 0xFF, 0x0, 0x0, 0xFF);
		SDL_RenderClear(rend);
		///Draw my background to the screen
		BackGround->Draw(Vec2(0,0),winWid,winLen,Vec2(0,0), rend);
		///Draw a flat Hill;
		Hill->Draw(Vec2(0, winLen-72), levelWid, 72, Vec2(0, 0), rend);
		///Draw health bar/Update it based on players health
		Health->Draw(Vec2(0, 0), 86,80, Vec2(play->getHealth()*86, 0), rend);
		///Draw Magic bar/Update it based on players Magic
		Magic->Draw(Vec2(winWid-80, 0), 86, 80, Vec2(play->getMagic() * 86, 0), rend);
		
		///Setting up for animating sprites ^^		
		play->Draw(play->getPos(), 77, 136, rend);
		SDL_RenderPresent(rend);
		//Updating Movement constantly x
		play->movement(DT);
		
	}
	///pause before we leave
	SDL_Delay(2000);
	///destroy and quit out of window
	delete play;
	delete BackGround;
	delete Hill;
	SDL_Quit();
	return 0;
}