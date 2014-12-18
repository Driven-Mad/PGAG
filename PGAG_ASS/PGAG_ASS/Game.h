#pragma once
#include <SDL.h>
class Game
{
public:
	Game();
	~Game();
	float* getDT();
	void updateTimer();
	SDL_Renderer* init();
	void draw(SDL_Renderer *R);
	void update();

private:
	unsigned int lastTime;
	unsigned int current;
	float DT;
	int levelx = 0, levely = 0, levelWid = 2048, levelLen = 1536;
	int winX = 100, winY = 100, winWid = 1024, winLen = 768;


};

