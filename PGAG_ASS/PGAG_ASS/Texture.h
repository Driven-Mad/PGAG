#pragma once
#include <iostream>
#include <SDL.h>
class Texture
{
public:
	Texture();
	~Texture();
	SDL_Texture& createTexture(SDL_Renderer *renderer, std::string filename);

private:
	SDL_Texture *text;
	int checkImageLoad(SDL_Surface *I);
	void freeImage(SDL_Surface *I);
	SDL_Surface loadImage(std::string filename);
	
};

