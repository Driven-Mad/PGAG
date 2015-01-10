//------------------------------------------------------------------
/// \file    Texture.h
/// \author  Lloyd Phillips
/// \brief   This is the Texture class
//------------------------------------------------------------------
#ifndef TEXTURE_H
#define TEXTURE_H
#include <iostream>
#include <SDL.h>
#include "Vec2.h"

class Texture{
public:
	/// \brief Constructor
	Texture();
	/// \brief destructor
	~Texture();
	/// \brief function to create a texture
	SDL_Texture* createTexture(SDL_Renderer *renderer);
	/// \brief Gets the Texture
	SDL_Texture* getText();
	/// \brief sets the Texture
	void setTexture(SDL_Texture *t);
	///getter for filename
	std::string getfilename();
	///setter for filename
	void setfilename(std::string s);
	/// \brief Virtual Function for drawing the texture
	virtual void Draw(Vec2 texturePosition, int width, int height, Vec2 renderPosition, int Rwidth, int Rheight, SDL_Renderer *r){
		/// \brief Texture box, what you want to see on screen
		SDL_Rect TextureSize;
		TextureSize.x = int(texturePosition.x);
		TextureSize.y = int(texturePosition.y);
		TextureSize.h = height;
		TextureSize.w = width;
		/// \brief Render box, what you want to render off the image.
		SDL_Rect RenderSize;
		RenderSize.x = int(renderPosition.x);
		RenderSize.y = int(renderPosition.y);
		RenderSize.h = Rheight;
		RenderSize.w = Rwidth;
		SDL_RenderCopy(r, text, &RenderSize, &TextureSize);
	}
private:
	
	std::string filename;///< File Name for Texture
	SDL_Texture *text; ///<Texture handle for our texture
	int checkImageLoad(SDL_Surface *I); ///<Check to see if the image loaded ok.
	void freeImage(SDL_Surface *I);///<Free the image once we have done with it
	SDL_Surface loadImage(std::string filename);///<Load an image
};
#endif ///!TEXTURE_H

