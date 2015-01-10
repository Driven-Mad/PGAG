//------------------------------------------------------------------
/// \file    Game.h
/// \author  Lloyd Phillips
/// \brief   This is the Game class
//------------------------------------------------------------------
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
	/// \brief Constructor
	Game();
	/// \brief destructor
	~Game();
	/// \brief Initilises Textures
	void initTextures();
	/// \brief Loads the Menu
	void loadMenu();
	/// \brief Loads the Instructions
	void loadInstructions();
	/// \brief Loads the Game
	void loadGame();
	///Getters and Setter for states
	/// \brief returns playing, True or False
	bool getPlaying();
	/// \brief sets playing, True or False
	void setPlaying(bool b);
	/// \brief returns Menu, True or False
	bool getMenu();
	/// \brief sets Menu, True or False
	void setMenu(bool b);
	/// \brief returns Instructions, True or False
	bool getInstructions();
	/// \brief sets instruction, True or False
	void setInstructions(bool b);
	/// \brief returns running, True or False
	bool getRunning();
	/// \brief sets running, True or False
	void setRunning(bool b);
	/// \brief returns level1, True or False
	bool getLevel1();
	/// \brief sets level1, True or False
	void setLevel1(bool b);
	/// \brief returns level2, True or False
	bool getLevel2();
	/// \brief sets level2, True or False
	void setLevel2(bool b);
private:
	int levelx = 0, levely = 0, levelWid = 2048, levelLen = 768, winX = 100, winY = 100, winWid = 1024, winLen = 768, mouseX = 0, mouseY = 0; ///<level sizes and Mouses X & Y position
	bool playing = false, menu = true, instruction = false, running = true; ///<states of the game
	Texture *BackGround; ///<texture for backGround
	Texture *Menu; ///<texture for Menu
	Texture *Instructions; ///<texture for Instructions
	Texture *EndScene; ///<texture for EndSchene
	Texture *BackGround2; ///<texture for backGround2
	Texture *Hill; ///<texture for hill
	Texture *Health; ///<texture for health
	Texture *Magic; ///<texture for magic
	Enemy *En, *En2; ///<Enemy's 
	Seeds Seed[4]; ///<Seeds
	Camera *cam;  ///<Camera
	Player *play;  ///<Player
	Blockade *Block; ///<Blockade
	Diamond *diamond;  ///<Diamond
	Rope *Rpe; ///<Ropes
	unsigned int lastTime; ///<Starting the DT
	SDL_Renderer* rend; ///<Renderer
	Light *lights[500]; ///<Lights
	bool level1, level2;///Level states
};
#endif ///!GAME_H

