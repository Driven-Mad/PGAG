#include "Seeds.h"
//Constructor
Seeds::Seeds(){
	Texture::setTexture(NULL);
	setfilename("Seed.bmp");
	Position = Vec2(0.0f, 0.0f);
	isActive = true;
}
//Destructors
Seeds::~Seeds()
{
	SDL_DestroyTexture(Texture::getText());
}

//Getters and Setters
Vec2 Seeds::getPos(){
	return Position;
}
void Seeds::setPos(Vec2 p){
	Position = p;
}

//update Function
void Seeds::update(Player *p){
	//If player goes near the seed then it will be destroyed and the magic will have an extra one :)
	if (p->getPos().x + 30 >= (Position.x - 5) &&
		p->getPos().x + 30 <= (Position.x + 5) &&
		p->getPos().y + 98 >= (Position.y - 10) &&
		p->getPos().y + 98 <= (Position.y + 10) &&
		isActive){
		isActive = false;
		SDL_DestroyTexture(Texture::getText());
		p->setMagic(p->getMagic() + 1);
	}
}