#include "Game.h"
//Constructor Creating a renderer
Game::Game(){
	SDL_Window *window;
	//Initialise Video
	SDL_Init(SDL_INIT_VIDEO);
	//Create window using pointer, and SDL
	window = SDL_CreateWindow("Magical world", winX, winY, winWid, winLen, SDL_WINDOW_OPENGL);
	//Error tracking
	if (window == NULL){
		std::printf("GOOD LAWD YOU SUCK");
		SDL_Quit();
	}
	//Create a renderer through creating a window
	rend = SDL_CreateRenderer(window, -1, 0);
	lastTime = SDL_GetTicks();
	level1 = true;
	level2 = false;
}
//Destructor Destroying Everything
Game::~Game(){
	//pause before we leave
	SDL_Delay(2000);
	//destroy and quit out of window
	delete play, Health, Magic, En, BackGround, Hill, BackGround2, Block, cam, diamond, EndScene, Instructions, Menu, Rpe	;
	for (int i = 0; i < 4; i++)
		Seed[i].~Seeds();
	SDL_Quit();
	for (int i = 0; i < 500; i++){
		delete lights[i];
	}
}

//Initalising instances of Classes
void Game::initTextures(){
	BackGround = new Texture();
	BackGround->setfilename("Space.bmp");
	BackGround->createTexture(rend);
	Menu = new Texture();
	Menu->setfilename("Menu.bmp");
	Menu->createTexture(rend);
	Instructions = new Texture();
	Instructions->setfilename("Instructions.bmp");
	Instructions->createTexture(rend);
	EndScene = new Texture();
	EndScene->setfilename("EndScene.bmp");
	EndScene->createTexture(rend);
	BackGround2 = new Texture();
	BackGround2->setfilename("Day.bmp");
	BackGround2->createTexture(rend);
	play = new Player();
	play->setfilename("Tree2.bmp");
	play->createTexture(rend);
	Block = new Blockade();
	Block->setfilename("Hill.bmp");
	Block->createTexture(rend);
	SDL_Rect BlockSize;
	BlockSize.h = 50;
	BlockSize.w = 200;
	BlockSize.x = 1000;
	BlockSize.y = winLen - 500;
	Block->setPosition(BlockSize);
	diamond = new Diamond();
	diamond->setfilename("Diamond.bmp");
	diamond->createTexture(rend);
	Rpe = new Rope();
	Rpe->setfilename("Rope.bmp");
	Rpe->createTexture(rend);
	Rpe->setPos(Vec2(float(Block->getPosition().x), float(Block->getPosition().y + 30.0f)));
	Hill = new Texture();
	Hill->setfilename("Hill.bmp");
	Hill->createTexture(rend);
	Health = new Texture();
	Health->setfilename("Health.bmp");
	Health->createTexture(rend);
	Magic = new Texture();
	Magic->setfilename("Magic.bmp");
	Magic->createTexture(rend);
	En = new Enemy();
	En->createTexture(rend);
	En2 = new Enemy();
	En2->createTexture(rend);
	for (int i = 0; i < 4; i++){
		Seed[i].setPos(Vec2(float(rand() % 1700 + 100), float(winLen - 80)));
		Seed[i].createTexture(rend);
		Seed[i].isActive = true;
	}

	cam = new Camera();
	for (int i = 0; i < 500; i++){
		lights[i] = new Light(rend);
	}
}
//Loads the Menu
void Game::loadMenu(){
	playing = instruction = level2 = false;
	running = menu = level1 = true;
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

//Loads the Instructions
void Game::loadInstructions(){
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

//Loads the Game
void Game::loadGame(){
	while (level1){
		//Creating a DT
		unsigned int current = SDL_GetTicks();
		float DT = (float)(current - lastTime) / 100000.0f;
		lastTime = current;
		//Sets background default colour
		SDL_SetRenderDrawColor(rend, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(rend);
		// Drawring//////////////////->

		Uint32 tempSeconds = Uint32(current / 100);
		float LightSparkle = float(tempSeconds % 4);
		if (!diamond->collected){
			BackGround->Draw(-cam->getPos(), levelWid, levelLen, Vec2(0, 0), winWid, winLen, rend);
		}
		if (diamond->collected){
			play->hasWon = true;
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
		for (int i = 0; i < 500; i++){
			lights[i]->update(DT, rend, play, cam, Rpe);
		}

		// ////////////////->
		//UPDATES//////////////////->
		for (int i = 0; i < 4; i++){
			Seed[i].update(play);
		}
		Block->update(play);
		cam->update(play->getPos());
		playing = level1 = play->update(DT);
		En->update(play, DT, diamond);
		Rpe->update(play);
		diamond->update(play);
		// ////////////////->
		SDL_RenderPresent(rend);
		if (!playing){
			menu = true;
		}
		
		if (play->hasWon){
			level1 = false;
			level2 = true;
			Game::initTextures();
		}
	}
	while (level2){
		//Creating a DT
		unsigned int current = SDL_GetTicks();
		float DT = (float)(current - lastTime) / 100000.0f;
		lastTime = current;
		//Sets background default colour
		SDL_SetRenderDrawColor(rend, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(rend);
		// Drawring//////////////////->

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
			play->hasWon = true;
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
		En2->Draw(cam, rend);
		Rpe->Draw(cam, rend);
		play->Draw(cam, rend);
		for (int i = 0; i < 500; i++){
			lights[i]->update(DT, rend, play, cam, Rpe);
		}
		// ////////////////->
		//UPDATES//////////////////->
		for (int i = 0; i < 4; i++){
			Seed[i].update(play);
		}
		Block->update(play);
		cam->update(play->getPos());
		playing = level2 = play->update(DT);
		En->update(play, DT, diamond);
		En2->update(play, DT, diamond);
		Rpe->update(play);
		diamond->update(play);
		// ////////////////->
		SDL_RenderPresent(rend);
		if (!playing){
			menu = true;
		}
	}
}
//Getters and Setters
bool Game::getPlaying(){
	return playing;
}
void Game::setPlaying(bool b){
	playing = b;
}
bool Game::getMenu(){
	return menu;
}
void Game::setMenu(bool b){
	menu = b;
}
bool Game::getInstructions(){
	return instruction;
}
void Game::setInstructions(bool b){
	instruction = b;
}
bool Game::getRunning(){
	return running;
}
void Game::setRunning(bool b){
	running = b;
}
bool Game::getLevel1(){
	return level1;
}
void Game::setLevel1(bool b){
	level1 = b;
}
bool Game::getLevel2(){
	return level2;
}
void Game::setLevel2(bool b){
	level2 = b;
}