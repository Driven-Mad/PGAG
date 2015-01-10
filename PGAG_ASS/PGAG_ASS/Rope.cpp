#include "Rope.h"
//Constructor
Rope::Rope(){
	RenderSize.x = 0;
	RenderSize.y = 0;
	RenderSize.h = 256;
	RenderSize.w = 16;
	pos = Vec2(0.0, 0.0);
	timer = 0;
	isDown = false;
}
//Destructor
Rope::~Rope(){
	Texture::~Texture();
}

//Getters and Setters
void Rope::setPos(Vec2 p){
	pos = p;	
}
Vec2 Rope::getPos(){
	return pos;
}
void Rope::setRenderX(int x){
	RenderSize.x = x;
}

//update Function
void Rope::update(Player *p){
	timer++;
	//Sets the renderize based on the timer, as it went to fast otherwise
	if (p->casting == true && RenderSize.x != 240 && timer == 100 && isDown == false){
			RenderSize.x += 16;
	}
	//resets the timer
	if (timer == 101){
		timer = 0;
	}
	//at a point in rednersize the rope is fully down
	if (RenderSize.x == 240){
		isDown = true;
	}
	//When it is down we just want a loop through animation to show a bit of movement
	if (isDown == true){
		unsigned int current = SDL_GetTicks();
		Uint32 tempSeconds = Uint32(current / 300);
		int F = tempSeconds % 10;
		RenderSize.x = F * 16 + 96;
		p->setMagic(0);
	}
	//If player is under rope
	if (p->getPos().x + 30  >= pos.x && p->getPos().x + 30  <= pos.x + 16 && p->getPos().y + 136 >= pos.y){
		//Then the player can climb up it
		if (isDown){
			p->canClimb = true;
		}
		//and the player is in range
		p->inRange = true;
	}
	//else the rope is out of range and the player can't climb
	else {
		p->canClimb = false;
		p->inRange = false;
	}

}

