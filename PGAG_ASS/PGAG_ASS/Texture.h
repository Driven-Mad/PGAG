#ifndef TEXTURE_H
#define TEXTURE_H
#include <iostream>
#include <SDL.h>
#include "Vec2.h"

class Texture{
public:
	Texture();
	~Texture();
	///function to create a texture
	SDL_Texture* createTexture(SDL_Renderer *renderer);
	SDL_Texture* getText();
	void setTexture(SDL_Texture *t);
	///getter for filename
	std::string getfilename();
	///setter for filename
	void setfilename(std::string s);
	///Draws Texture to screen
	void Texture::Draw(Vec2 texturePosition, int width, int height, Vec2 renderPosition, SDL_Renderer *r){
		SDL_Rect TextureSize;
		TextureSize.x = texturePosition.x;
		TextureSize.y = texturePosition.y;
		TextureSize.h = height;
		TextureSize.w = width;
		SDL_Rect RenderSize;
		RenderSize.x = renderPosition.x;
		RenderSize.y = renderPosition.y;
		RenderSize.h = height;
		RenderSize.w = width;
		//SDL_QueryTexture(text, NULL, NULL, &des.w, &des.h);
		SDL_RenderCopy(r, text, &RenderSize, &TextureSize);
	}
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

