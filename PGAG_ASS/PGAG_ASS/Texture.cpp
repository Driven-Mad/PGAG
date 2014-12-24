#include "Texture.h"
///Constructor
Texture::Texture(){
	Texture::text = NULL;
}
///Destructor
Texture::~Texture(){
	if (text){
		SDL_DestroyTexture(text);
	}
}
///Check if the image loads ok!
int Texture::checkImageLoad(SDL_Surface *I){
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
///Free image up
void Texture::freeImage(SDL_Surface *I){
	SDL_FreeSurface(I);
}
///Load image file.
SDL_Surface Texture::loadImage(std::string filename){
	SDL_Surface *image = SDL_LoadBMP(filename.c_str());
	checkImageLoad(image);
	return *image;
}
///Load image to a texture
SDL_Texture* Texture::createTexture(SDL_Renderer *r){
	SDL_Surface &i = loadImage(filename);
	SDL_SetColorKey(&i, 1, SDL_MapRGB(i.format, 255, 0, 255));
	///Create the texture from the image and renderer
	text = SDL_CreateTextureFromSurface(r, &i);
	if (text == NULL){
		std::cout << "you're texture didn't load, booo hooo";
	}
	freeImage(&i);
	///Return the texture 
	return text;
}
///////////////////////
///Getters and Setters/
///////////////////////
std::string Texture::getfilename(){
	return filename;
}
void Texture::setfilename(std::string s){
	filename = s;
}
SDL_Texture* Texture::getText()
{
	return text;
}
void Texture::setTexture(SDL_Texture *t)
{
	text = t;
}
