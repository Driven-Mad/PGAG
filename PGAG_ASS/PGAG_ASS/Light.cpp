#include "Light.h"


Light::Light(SDL_Renderer *rend){
	pos.x = rand() % 2048;
	pos.y = rand() % 756;
	vel.x = rand() % 20000 - 10000;
	vel.y = rand() % 10000 + 1;
	x = rand() % 255;

	switched = false;
	std::string file = "light.png";
	image = IMG_Load(file.c_str());
	if (image == NULL){
		std::cout << "sorry your image has not been loaded";
		SDL_Delay(200);
		SDL_Quit();
	}
	SDL_SetColorKey(image, 1, SDL_MapRGB(image->format, 255, 0, 255));
	decreasing = false;
	increasing = true;
	lightTexture = SDL_CreateTextureFromSurface(rend, image);
	SDL_SetTextureBlendMode(lightTexture, SDL_BLENDMODE_BLEND);
	SDL_FreeSurface(image);
}


Light::~Light(){
	
}

void Light::update(float DT, SDL_Renderer *rend, Player *p, Camera *c, Rope *r){
	pixel.x = pos.x;
	pixel.y = pos.y;
	
	//SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(image->format, 255, 0, 255));

	SDL_SetTextureAlphaMod(lightTexture, x);
	SDL_Rect TextureSize;
	TextureSize.x = pos.x - c->getPos().x;
	TextureSize.y = pos.y;
	TextureSize.h = 10;
	TextureSize.w = 10;
	///Render box, what you want to render off the image.
	SDL_Rect RenderSize;
	RenderSize.x = 0;
	RenderSize.y = 0;
	RenderSize.h = 10;
	RenderSize.w = 10;
	SDL_RenderCopy(rend, lightTexture, &RenderSize, &TextureSize);
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
	//SDL_RenderDrawPoint(rend, pos.x - c->getPos().x, pos.y);
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