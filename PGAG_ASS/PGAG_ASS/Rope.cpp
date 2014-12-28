#include "Rope.h"
Rope::Rope(){
	RenderSize.x = 0;
	RenderSize.y = 0;
	RenderSize.h = 256;
	RenderSize.w = 16;
	pos = Vec2(0.0, 0.0);
	timer = 0;
	isDown = false;
}
Rope::~Rope(){
}

void Rope::setPos(Vec2 p){
	pos = p;	
}

Vec2 Rope::getPos(){
	return pos;
}
void Rope::setRenderX(int x){
	RenderSize.x = x;
}
void Rope::update(Player *p){
	timer++;
	if (p->casting == true && RenderSize.x != 240 && timer == 100 && isDown == false){
			RenderSize.x += 16;
	}
	if (timer == 101){
		timer = 0;
	}
	if (RenderSize.x == 240){
		isDown = true;
	}
	if (isDown == true){
		unsigned int current = SDL_GetTicks();
		Uint32 tempSeconds = Uint32(current / 300);
		float F = float(tempSeconds % 10);
		RenderSize.x = F * 16 + 96;
		p->setMagic(0);
	}

	if (p->getPos().x + 30  >= pos.x && p->getPos().x + 30  <= pos.x + 16 && p->getPos().y + 136 >= pos.y){
		if (isDown){
			p->canClimb = true;
		}
		p->inRange = true;
	}

	else {
		p->canClimb = false;
		p->inRange = false;
	}

}

