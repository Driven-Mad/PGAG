#include "Blockade.h"

Blockade::Blockade(){
}

Blockade::~Blockade(){
}

SDL_Rect Blockade::getPosition(){
	return Position;
}
void Blockade::setPosition(SDL_Rect p){
	Position = p;
}
void Blockade::update(Player *P){
	///if the player gets up on the blockade
	if ((P->getPos().y >= Position.y - Position.h*2 - 1) &&
		(P->getPos().y <= Position.y - Position.h*2 + 1) &&
		(P->getPos().x + 30 >= Position.x) &&
		(P->getPos().x <= Position.x + Position.w)){
		P->onPlatform = true;
	}
	else{
		P->onPlatform = false;
	}
	
	if ((P->getPos().x + 30 >= Position.x) &&
		(P->getPos().x <= Position.x + Position.w) && 
		P->getPos().y >= Position.y - Position.h &&
		P->getPos().y <= Position.y){
		P->hittingAWall = true;
	}
	else{
		P->hittingAWall = false;
	}

}