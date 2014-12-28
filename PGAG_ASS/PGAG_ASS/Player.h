#ifndef PLAYER_H
#define PLAYER_H
#include "Texture.h"
#include "Camera.h"
#include "Vec2.h"
#include "SDL.h"
class Player : public Texture{
public:
	Player();
	~Player();
	///Virtual function re-defined for textures
	void Player::Draw(Camera *c, SDL_Renderer *r){
		unsigned int current = SDL_GetTicks();
		SDL_Rect RenderSize;
		Uint32 tempSeconds = Uint32(current / 100);
		float spriteJumping = float(tempSeconds % 15), spriteWalking = float(tempSeconds % 4);
		switch (stance){
		case 0:
			RenderSize.x = 0;
			RenderSize.y = 272;
			break;
		case 1:
			RenderSize.x = int(spriteWalking * 77);
			RenderSize.y = 136;
			break;
		case 2:
			RenderSize.x = int(spriteWalking * 77);
			RenderSize.y = 136;
			break;
		case 3:
			RenderSize.x = int(spriteJumping * 77);
			RenderSize.y = 0;
			break;
		}
		SDL_Rect TextureSize;
		TextureSize.x = int(pos.x - c->getPos().x);
		TextureSize.y = int(pos.y);
		TextureSize.h = 136;
		TextureSize.w = 77;
		RenderSize.h = 136;
		RenderSize.w = 77;
		SDL_RenderCopy(r, Texture::getText(), &RenderSize, &TextureSize);
	}
	///Updates player function based on DT
	bool update(float DT);
	///Getters and Setters
	Vec2 getPos();
	void setPos(Vec2 p);
	Vec2 getVel();
	void setVel(Vec2 v);
	int getHealth();
	void setHealth(int i);
	int getMagic();
	void setMagic(int i);
	bool movingL, movingR, isJumping, idle, onGround, hittingAWall, onPlatform, casting, canClimb, inRange;
private:
	///Vec2s
	Vec2 oldPos, pos, vel;
	///Ints
	int stance, magic, health;;
};
#endif