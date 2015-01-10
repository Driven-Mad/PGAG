#include "Light.h"

//constructor
Light::Light(SDL_Renderer *rend){
	pos.x = float(rand() % 2048);
	pos.y = float(rand() % 756);
	vel.x = float(rand() % 20000 - 10000);
	vel.y = float(rand() % 10000 + 1);
	x = rand() % 255;
	a = rand() % 4 + 4 ;
	b = a - 4;
	switched = false;
	std::string file = "light.png";
	image = IMG_Load(file.c_str());
	if (image == NULL){
		std::cout << "sorry your image has not been loaded";
		SDL_Delay(200);
		SDL_Quit();
	}
	decreasing = false;
	increasing = true;
	lightTexture = SDL_CreateTextureFromSurface(rend, image);
	lightSolid = SDL_CreateTextureFromSurface(rend, image);
	SDL_SetTextureBlendMode(lightTexture, SDL_BLENDMODE_BLEND);
	SDL_FreeSurface(image);
}
//destructor
Light::~Light(){
	
}
//update function
void Light::update(float DT, SDL_Renderer *rend, Player *p, Camera *c, Rope *r){
	SDL_SetTextureAlphaMod(lightTexture, x);
	SDL_Rect TextureSize;
	TextureSize.x = int(pos.x - c->getPos().x);
	TextureSize.y = int(pos.y);
	TextureSize.h = a;
	TextureSize.w = a;
	SDL_Rect TextureSize2;
	TextureSize2.x = (int(pos.x - c->getPos().x) + 2);
	TextureSize2.y = (int(pos.y) + 2);
	TextureSize2.h = b;
	TextureSize2.w = b;
	//Render box, what you want to render off the image.
	SDL_Rect RenderSize;
	RenderSize.x = 0;
	RenderSize.y = 0;
	RenderSize.h = 10;
	RenderSize.w = 10;
	SDL_RenderCopy(rend, lightTexture, &RenderSize, &TextureSize);
	SDL_RenderCopy(rend, lightSolid, &RenderSize, &TextureSize2);
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
		vel.y = float(rand() % 20000 - 10000);
		vel.x = float(rand() % 20000 - 10000);
		switched = true;
	}
	if (r->isDown && switched){
		pos.x = ((pos.x + (vel.x * DT)));
		pos.y = ((pos.y + (vel.y * DT)));
	}
	if (x == 0){
		increasing = true;
		decreasing = false;
	}
	if (x == 255){
		decreasing = true;
		increasing = false;
	}
	if (increasing){
		x += 1;
	}
	if (decreasing){
		x -= 1;
	}
}