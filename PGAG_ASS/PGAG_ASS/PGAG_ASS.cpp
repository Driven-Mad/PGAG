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
	///Global Variables for the main function
	///ints
	int levelx = 0, levely = 0, levelWid = 2048, levelLen = 768, winX = 100, winY = 100, winWid = 1024, winLen = 768, mouseX = 0, mouseY = 0;
	///Boolians
	bool playing = false, menu = true, instruction = false, running = true;
	///Create a renderer
	Game App;
	SDL_Renderer *rend = App.init();
	///Initalise LastTime for me to get on with using DT
	unsigned int lastTime = SDL_GetTicks();
	///////////////////////////////////////////
	///Initalising instances of Classes////////
	///////////////////////////////////////////->
	Texture *BackGround = new Texture();
	BackGround->setfilename("Space.bmp");
	BackGround->createTexture(rend);
	Texture *Menu = new Texture();
	Menu->setfilename("Menu.bmp");
	Menu->createTexture(rend);
	Texture *Instructions = new Texture();
	Instructions->setfilename("Instructions.bmp");
	Instructions->createTexture(rend);
	Texture *EndScene = new Texture();
	EndScene->setfilename("EndScene.bmp");
	EndScene->createTexture(rend);
	Texture *BackGround2 = new Texture();
	BackGround2->setfilename("Day.bmp");
	BackGround2->createTexture(rend);
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
	Texture *Light1 = new Texture();
	Light1->setfilename("Lights1.bmp");
	Light1->createTexture(rend);
	Texture *Light2 = new Texture();
	Light2->setfilename("Lights2.bmp");
	Light2->createTexture(rend);
	Camera *cam = new Camera();
	///////////////////////////////////////////->
	///Bool for RUNNING game BEGINS->
	while (running){
		///Bool for MENU while loop BEGINS->
		while (menu){
			SDL_SetRenderDrawColor(rend, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(rend);
			Menu->Draw(Vec2(0.0f, 0.0f), winWid, winLen, Vec2(0, 0), winWid, winLen, rend);
			SDL_Event incoming;
			while (SDL_PollEvent(&incoming)){
				if (incoming.type == SDL_MOUSEBUTTONDOWN){
					SDL_GetMouseState(&mouseX, &mouseY);
					if (mouseX >= 52 && mouseY >= 62 && mouseX <= 247 && mouseY <= 180){
						playing = true;
						menu = false;
						instruction = false;
					}
					if (mouseX >= 811 && mouseY >= 62 && mouseX <= 981 && mouseY <= 180){
						playing = false;
						menu = false;
						instruction = false;
						running = false;
					}
					if (mouseX >= 237 && mouseY >= 327 && mouseX <= 825 && mouseY <= 422){
						playing = false;
						menu = false;
						instruction = true;
					}
				}
			}
			SDL_RenderPresent(rend);
		}
		///Bool for MENU while loop ENDS ->

		///Bool for Instructions while loop BEGINS->
		while (instruction){
			SDL_SetRenderDrawColor(rend, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(rend);
			Instructions->Draw(Vec2(0.0f, 0.0f), winWid, winLen, Vec2(0, 0), winWid, winLen, rend);
			SDL_Event incoming;
			while (SDL_PollEvent(&incoming)){
				if (incoming.type == SDL_MOUSEBUTTONDOWN){
					SDL_GetMouseState(&mouseX, &mouseY);
					if (mouseX >= 0 && mouseY >= 0 && mouseX <= 1028 && mouseY <= 768){
						playing = false;
						menu = true;
						instruction = false;
					}
				}
			}
			SDL_RenderPresent(rend);
		}
		///Bool for Instuctions while loop ENDS ->
		///Bool for Playing while loop BEGINS->
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
			float LightSparkle = float(tempSeconds % 4);
			if (!diamond->collected){
				BackGround->Draw(-cam->getPos(), levelWid, levelLen, Vec2(0, 0), winWid, winLen, rend);
			}
			if (diamond->collected){
				BackGround2->Draw(-cam->getPos(), levelWid, levelLen, Vec2(0, 0), winWid, winLen, rend);
				if (play->getHealth() >= 0){
					EndScene->Draw(Vec2(0.0f, 0.0f), winWid, winLen, Vec2(0, 0), winWid, winLen, rend);
				}
			}
			Hill->Draw(Vec2(-cam->getPos().x, float(winLen) - 72.0f), levelWid, 72, Vec2(0.0f, 0.0f), levelWid, 72, rend);
			Block->Draw(cam, rend);
			diamond->Draw(Block, cam, rend);
			Health->Draw(Vec2(0.0f, 0.0f), 86, 80, Vec2(play->getHealth() * 86.0f, 0.0f), 86, 80, rend);
			Magic->Draw(Vec2(winWid - 80.0f, 0.0f), 86, 80, Vec2(play->getMagic() * 86.0f, 0.0f), 86, 80, rend);
			for (int i = 0; i < 4; i++){
				Seed[i].Draw(cam, rend);
			}
			En->Draw(cam, rend);
			Rpe->Draw(cam, rend);
			play->Draw(cam, rend);
			if (play->casting){
				//	Light1->Draw(play->getPos() - cam->getPos(), 30, 60, Vec2(77 * LightSparkle, 0), 77, 136, rend);
				Light2->Draw(play->getPos() - cam->getPos(), 77, 136, Vec2(77 * LightSparkle, 0), 77, 136, rend);
			}
			//////////////////->

			//////////////////
			///UPDATES////////
			//////////////////->
			for (int i = 0; i < 4; i++){
				Seed[i].update(play);
			}
			Block->update(play);
			cam->update(play->getPos());
			playing = play->update(DT);
			En->update(play, DT, diamond);
			Rpe->update(play);
			diamond->update(play);
			//////////////////->

			SDL_RenderPresent(rend);
		}
		///Bool for PLAYING while loop ENDS->
	}
	///Bool for RUNNING game ENDS ->
	///pause before we leave
	SDL_Delay(2000);
	///destroy and quit out of window
	delete play, Health, Magic, En, BackGround, Hill, BackGround2, Block, cam, diamond, EndScene, Instructions, Menu, Rpe, Light1, Light2;
	for (int i = 0; i < 4; i++)
		Seed[i].~Seeds;
	SDL_Quit();
	return 0;
}