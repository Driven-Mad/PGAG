#include "Light.h"


Light::Light(){
	pos.x = rand() % 2048;
	pos.y = rand() % 756;
	vel.x = rand() % 10000 + 1;
	vel.y = rand() % 10000 + 1;
	switched = false;
}


Light::~Light(){
}

void Light::update(float DT, SDL_Renderer *rend, Player *p, Camera *c, Rope *r){
	pixel.x = pos.x;
	pixel.y = pos.y;
	if (pos.y >= 700 && !r->isDown){
		pos.y = 0;
	}
	if (pos.x >= 2048 && !r->isDown){
		pos.x = 0;
	}
	if (p->casting && !r->isDown){
		if (pos.x > (p->getPos().x  + 33.0f)){
			pos.x = (pos.x - (vel.x * DT) * 8) ;
		}
		if (pos.x < (p->getPos().x  + 33.0f)){
			pos.x = (pos.x + (vel.x * DT) * 8);
		}
		if (pos.y < p->getPos().y + 65.0f){
			pos.y = (pos.y + (vel.y * DT) * 4);
		}
		if (pos.y > p->getPos().y + 65.0f){
			pos.y = (pos.y - (vel.y * DT) * 4);
		}
	}
	if (!p->casting && !switched){
		pos.x = ((pos.x + (vel.x * DT)));
		pos.y = ((pos.y + (vel.y * DT)));
	}
	if (r->isDown && !switched){
		vel.y = rand() % 20000 - 10000;
		vel.x = rand() % 20000 - 10000;
		switched = true;
	}
	if (r->isDown && switched){
		pos.x = ((pos.x + (vel.x * DT)));
		pos.y = ((pos.y + (vel.y * DT)));
	}
	SDL_RenderDrawPoint(rend, pos.x - c->getPos().x, pos.y);
}