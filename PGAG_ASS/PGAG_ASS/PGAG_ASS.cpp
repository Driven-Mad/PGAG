#include <iostream>
#include <SDL.h>
#include "Game.h"

int main(int argc, char *argv[]){
	///Create a new game
	Game *App = new Game();
	///While it's running
	while (App->getRunning()){
		///While state is on Menu
		while (App->getMenu()){
			///Initilise the Textures, player etc.
			App->initTextures();
			///load the Menu
			App->loadMenu();
		}
		///while state is on instructions
		while (App->getInstructions()){
			///Load the Instructions
			App->loadInstructions();
		}
		///While game state is playing
		while (App->getPlaying()){
			///Load the Game
			App->loadGame();
		}
	}
	App->~Game();
	return 0;
}