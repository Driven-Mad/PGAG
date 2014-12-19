#include "Seeds.h"


Seeds::Seeds()
{
	Texture::setTexture(NULL);
	setfilename("Seed.bmp");
	Position = Vec2(0.0f, 0.0f);
	isActive = true;
}


Seeds::~Seeds()
{
	SDL_DestroyTexture(Texture::getText());
}
Vec2 Seeds::getPos(){
	return Position;
}
void Seeds::setPos(Vec2 p){
	Position = p;
}