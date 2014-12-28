#include "Diamond.h"


Diamond::Diamond(){
	collected = false;
}


Diamond::~Diamond(){
	Texture::~Texture();
}
Vec2 Diamond::getPos(){
	return pos;
}
void Diamond::setPos(Vec2 p){
	pos = p;
}
void Diamond::update(Player *p){
	if (collected){
		Diamond::~Diamond();
	}
	if (((p->getPos().x + 30) >= pos.x) && ((p->getPos().x + 30) <= (pos.x + 44)) && p->onPlatform == true){
		collected = true;
	}
}