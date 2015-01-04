#ifndef DIAMOND_H
#define DIAMOND_H
#include "Texture.h"
#include "Camera.h"
#include "Blockade.h"
class Diamond : public Texture
{
public:
	Diamond();
	~Diamond();
	///Draw function (virtual) re-defined to suit Diamonds
		void Draw(Blockade *b, Camera *c, SDL_Renderer *r){
		unsigned int current = SDL_GetTicks();
		Uint32 tempSeconds = Uint32(current / 100);
		float diamondSparkle = float(tempSeconds % 4);
		SDL_Rect TextureSize;
		TextureSize.x = b->getPosition().x - c->getPos().x + 100;
		TextureSize.y = pos.y = b->getPosition().y - 40;
		TextureSize.h = 57;
		TextureSize.w = 44.5;
		SDL_Rect RenderSize;
		RenderSize.x = int(46.5 * diamondSparkle);
		RenderSize.y = 0;
		RenderSize.h = 57;
		RenderSize.w = 44.5;
		SDL_RenderCopy(r, Texture::getText(), &RenderSize, &TextureSize);
		pos.x = b->getPosition().x + 100;
	}
	///Update Function taking in the player.
	void update(Player *p);
	///Gets the position in x,y,
	Vec2 getPos();
	///sets the position in x,y,(vec2)
	void setPos(Vec2 p);
	///Boolian if collected or not.
	bool collected;
private:
	///Private Variables
	///Vec2's
	Vec2 pos;
};
#endif ///!DIAMOND_H
