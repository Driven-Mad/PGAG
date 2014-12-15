#include "Texture.h"

Texture::Texture(){
	SDL_Texture *text = NULL;
}


Texture::~Texture(){
	if (text){
		SDL_DestroyTexture(text);
	}
}

int Texture::checkImageLoad(SDL_Surface *I){
	///Check if the image loads ok!
	if (I == NULL){
		std::cout << "sorry your image has not been loaded";
		SDL_Delay(200);
		SDL_Quit();
		return -1;
	}
	else{
		return 1;
	}
}

void Texture::freeImage(SDL_Surface *I){
	///Free image up
	SDL_FreeSurface(I);
}

SDL_Surface Texture::loadImage(std::string filename){
	///Load image.
	SDL_Surface *image = SDL_LoadBMP(filename.c_str());
	checkImageLoad(image);
	return *image;
}

SDL_Texture* Texture::createTexture(SDL_Renderer *r){
	///Load image file
	SDL_Surface &i = loadImage(filename);
	SDL_SetColorKey(&i, 1, SDL_MapRGB(i.format, 255, 0, 255));
	///Create the texture from the image and renderer
	text = SDL_CreateTextureFromSurface(r, &i);
	///Do a quick check if the texture has loaded
	if (text == NULL){
		std::cout << "you're texture didn't load, booo hooo";
	}
	///free up the image
	freeImage(&i);
	///Return the texture 
	return text;
}
///Getter for the filename
std::string Texture::getfilename(){
	return filename;
}

///Setter for the filename
void Texture::setfilename(std::string s){
	filename = s;
}

void Texture::Draw(int TposX, int TposY, int Twidth, int Theight, int RposX, int RposY, int Rwidth, int Rheight, SDL_Renderer *r){
	SDL_Rect TextureSize;
	TextureSize.x = TposX;
	TextureSize.y = TposY;
	TextureSize.h = Theight;
	TextureSize.w = Twidth;
	SDL_Rect RenderSize;
	RenderSize.x = RposX;
	RenderSize.y = RposY;
	RenderSize.h = Rheight;
	RenderSize.w = Rwidth;
	//SDL_QueryTexture(text, NULL, NULL, &des.w, &des.h);
	SDL_RenderCopy(r, text, &RenderSize, &TextureSize);
}
