#include <iostream>
#include <SDL.h>
#include "Seeds.h"
#include "Vec2.h"
#include "Player.h"
#include "Texture.h"
#include "Enemy.h"
#include "Game.h"
#include "Camera.h"
#include "Blockade.h"
#include "Rope.h"
#include "Diamond.h"
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
	Blockade *Block = new Blockade();
	Block->setfilename("Hill.bmp");
	Block->createTexture(rend);
	SDL_Rect BlockSize;
	BlockSize.h = 50;
	BlockSize.w = 200;
	BlockSize.x = 1000;
	BlockSize.y = winLen - 500;
	Block->setPosition(BlockSize);
	Diamond *diamond = new Diamond();
	diamond->setfilename("Diamond.bmp");
	diamond->createTexture(rend);
	Rope *Rpe = new Rope();
	Rpe->setfilename("Rope.bmp");
	Rpe->createTexture(rend);
	Rpe->setPos(Vec2(float(Block->getPosition().x),float( Block->getPosition().y + 30.0f)));
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
		Uint32 tempSeconds = Uint32(current / 100);
		float diamondSparkle = float(tempSeconds % 4);
		BackGround->Draw(-cam->getPos(), levelWid, levelLen, Vec2(0, 0), winWid, winLen, rend);
		Hill->Draw(Vec2(-cam->getPos().x, float(winLen) - 72.0f), levelWid, 72, Vec2(0.0f, 0.0f), levelWid, 72, rend);
		Block->Draw(cam, rend);
		diamond->Draw(Block,cam, rend);
		Health->Draw(Vec2(0.0f, 0.0f), 86, 80, Vec2(play->getHealth() * 86.0f, 0.0f), 86, 80, rend);
		Magic->Draw(Vec2(winWid - 80.0f, 0.0f), 86, 80, Vec2(play->getMagic() * 86.0f, 0.0f),86, 80, rend);
		for (int i = 0; i < 4; i++){
			Seed[i].Draw(cam, rend);
		}
		En->Draw(cam, rend);
		Rpe->Draw(cam, rend);
		play->Draw(cam, rend);
		//////////////////->

		//////////////////
		///UPDATES////////
		//////////////////->
		for (int i = 0; i < 4; i++){
			Seed[i].update(play);
		}
		Block->update(play);
		cam->update(play->getPos());
		play->update(DT);
		En->update(play,DT);
		Rpe->update(play);
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