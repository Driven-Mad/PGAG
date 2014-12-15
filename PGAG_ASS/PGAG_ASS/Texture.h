#ifndef TEXTURE_H
#define TEXTURE_H
#include <iostream>
#include <SDL.h>

class Texture{
public:
	Texture();
	~Texture();
	///function to create a texture
	SDL_Texture* createTexture(SDL_Renderer *renderer);
	///getter for filename
	std::string getfilename();
	///setter for filename
	void setfilename(std::string s);
	///Draws Texture to screen
	void Draw(int posX, int posY, int width, int height, SDL_Renderer *r);
private:
	///File Name for Texture
	std::string filename;
	///Texture handle for our texture :D
	SDL_Texture *text;
	///Check to see if the image loaded ok.
	int checkImageLoad(SDL_Surface *I);
	///Free the image once we have done with it
	void freeImage(SDL_Surface *I);
	///Load an image
	SDL_Surface loadImage(std::string filename);
};
#endif

