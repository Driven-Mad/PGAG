#include <iostream>
#include <SDL.h>
#include "Game.h"

int main(int argc, char *argv[]){
	///Create a renderer
	Game App;
	SDL_Renderer *rend = App.init();
	App.run(rend);
	return 0;
}