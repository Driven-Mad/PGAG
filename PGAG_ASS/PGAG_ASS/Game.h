#ifndef GAME_H
#define GAME_H
#include <SDL.h>
#include <iostream>
#include "Seeds.h"
#include "Vec2.h"
#include "Player.h"
#include "Texture.h"
#include "Enemy.h"
#include "Camera.h"
#include "Blockade.h"
#include "Rope.h"
#include "Diamond.h"
#include "Light.h"
class Game{
public:
	Game();
	~Game();
	///Initilises Textures
	void initTextures();
	///Loads the Menu
	void loadMenu();
	///Loads the Instructions
	void loadInstructions();
	///Loads the Game
	void loadGame();
	///Getters and Setter for states
	bool getPlaying();
	void setPlaying(bool b);
	bool getMenu();
	void setMenu(bool b);
	bool getInstructions();
	void setInstructions(bool b);
	bool getRunning();
	void setRunning(bool b);

private:
	///Private Variables for the main function
	///ints
	int levelx = 0, levely = 0, levelWid = 2048, levelLen = 768, winX = 100, winY = 100, winWid = 1024, winLen = 768, mouseX = 0, mouseY = 0;
	///Boolians	
	bool playing = false, menu = true, instruction = false, running = true;
	///Textures
	Texture *BackGround;
	Texture *Menu;
	Texture *Instructions;
	Texture *EndScene;
	Texture *BackGround2;
	Texture *Hill;
	Texture *Health;
	Texture *Magic;
	///Enemy
	Enemy *En;
	///Seeds
	Seeds Seed[4];
	///Cameras
	Camera *cam;
	///Players
	Player *play;
	///Blockades
	Blockade *Block;
	///Diamonds
	Diamond *diamond;
	///Ropes
	Rope *Rpe;
	///Starting the DT
	unsigned int lastTime;
	///Creating the renderer
	SDL_Renderer* rend;
	Light *lights[1000];
};
#endif ///!GAME_H

