#include <iostream>
#include <SDL.h>
#include "Seeds.h"
#include "Vec2.h"
#include "Player.h"
#include "Texture.h"
#include "Enemy.h"
#include "Game.h"
#include "Camera.h"
#include <vector>

int main(int argc, char *argv[]){
	int levelx = 0, levely = 0, levelWid = 2048, levelLen = 768;
	int winX = 100, winY = 100, winWid = 1024, winLen = 768;
	Game App;
	SDL_Renderer *rend = App.init();
	unsigned int lastTime = SDL_GetTicks();
	///////////////////////////////////////////
	///Initalising instances of Classes////////
	///////////////////////////////////////////->
	Texture *BackGround = new Texture();
	BackGround->setfilename("Space.bmp");
	BackGround->createTexture(rend);
	Player *play = new Player();
	play->setfilename("Tree2.bmp");
	play->createTexture(rend);
	Texture *Blockade = new Texture();
	Blockade->setfilename("Hill.bmp");
	Blockade->createTexture(rend);
	Texture *Hill = new Texture();
	Hill->setfilename("Hill.bmp");
	Hill->createTexture(rend);
	Texture *Health = new Texture();
	Health->setfilename("Health.bmp");
	Health->createTexture(rend);
	Texture *Magic = new Texture();
	Magic->setfilename("Magic.bmp");
	Magic->createTexture(rend);
	Enemy *En = new Enemy();
	En->createTexture(rend);
	Seeds Seed[4];
	for (int i = 0; i < 4; i++){
		Seed[i].setPos(Vec2(float(rand() % 1700 + 100), float(winLen-80)));
		Seed[i].createTexture(rend);
	}
	Camera *cam = new Camera();
	///////////////////////////////////////////->
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
					break;
				case SDLK_RIGHT:
					play->movingR = true;
					break;
				case SDLK_UP :
					play->isJumping = true;
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

		///Creating a DT
		unsigned int current = SDL_GetTicks();
		float DT = (float)(current - lastTime) / 100000.0f;
		lastTime = current;
		///Sets background default colour
		SDL_SetRenderDrawColor(rend, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(rend);
		//////////////////
		///Drawring///////
		//////////////////->
		BackGround->Draw(-cam->getPos(), levelWid, levelLen, Vec2(0, 0), winWid, winLen, rend);
		Hill->Draw(Vec2(-cam->getPos().x, float(winLen) - 72.0f), levelWid, 72, Vec2(0.0f, 0.0f), levelWid, 72, rend);
		Blockade->Draw(Vec2(1800 - cam->getPos().x, float(winLen) - 300.0f), 200, 300, Vec2(0, 0), levelWid, 72, rend);
		Health->Draw(Vec2(0.0f, 0.0f), 86, 80, Vec2(play->getHealth() * 86.0f, 0.0f), 86, 80, rend);
		Magic->Draw(Vec2(winWid - 80.0f, 0.0f), 86, 80, Vec2(play->getMagic() * 86.0f, 0.0f),86, 80, rend);
		for (int i = 0; i < 4; i++){
			Seed[i].Draw(cam, rend);
		}
		En->Draw(cam, rend);
		play->Draw(cam, rend);
		//////////////////->

		//////////////////
		///UPDATES////////
		//////////////////->
		for (int i = 0; i < 4; i++){
			Seed[i].update(play);
		}
		cam->update(play->getPos());
		play->update(DT);
		En->update(play,DT);
		if (play->getHealth() < 0)
		{
			playing = false;
		}
		//////////////////->
		SDL_RenderPresent(rend);
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