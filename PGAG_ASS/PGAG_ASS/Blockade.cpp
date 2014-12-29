#include "Blockade.h"
///Constructor
Blockade::Blockade(){
}
///Destructor
Blockade::~Blockade(){
}
///////////////////////
///Getters and Setters/
///////////////////////
SDL_Rect Blockade::getPosition(){
	return Position;
}
void Blockade::setPosition(SDL_Rect p){
	Position = p;
}
///////////////////
///update Function/
///////////////////
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
	///If the player is hitting the side of the Blockade
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