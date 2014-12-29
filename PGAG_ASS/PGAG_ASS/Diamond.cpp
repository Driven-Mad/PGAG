#include "Diamond.h"
///Constructor
Diamond::Diamond(){
	collected = false;
}
///Destructor
Diamond::~Diamond(){
	Texture::~Texture();
}
///////////////////////
///Getters and Setters/
///////////////////////
Vec2 Diamond::getPos(){
	return pos;
}
void Diamond::setPos(Vec2 p){
	pos = p;
}
///////////////////
///update Function/
///////////////////
void Diamond::update(Player *p){
	///if collected, destroy the diamond
	if (collected){
		Diamond::~Diamond();
	}
	///if the player goes over the diamond, collected == true
	if (((p->getPos().x + 30) >= pos.x) && ((p->getPos().x + 30) <= (pos.x + 44)) && p->onPlatform == true){
		collected = true;
	}
}