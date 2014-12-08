#include "Texture.h"


Texture::Texture()
{
}


Texture::~Texture()
{
}

int Texture::checkImageLoad(SDL_Surface *I)
{
	if (I == NULL)
	{
		std::cout << "sorry your image has not been loaded";
		SDL_Delay(200);
		SDL_Quit();
		return -1;
	}
	else
	{
		return 1;
	}
}

void Texture::freeImage(SDL_Surface *I)
{
	SDL_FreeSurface(I);
}

SDL_Surface Texture::loadImage(std::string filename)
{
	SDL_Surface *image = SDL_LoadBMP(filename.c_str());
	checkImageLoad(image);
	return *image;
}

SDL_Texture& Texture::createTexture(SDL_Renderer *r, std::string f)
{
	SDL_Surface i = loadImage(f);
	SDL_Texture *text = SDL_CreateTextureFromSurface(r, &i);
	if (text == NULL)
	{
		std::cout << "you're texture didn't load, booo hooo";
	}
	freeImage(&i);
	return *text;
}