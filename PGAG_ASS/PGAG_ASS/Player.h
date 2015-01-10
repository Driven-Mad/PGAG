#ifndef PLAYER_H
#define PLAYER_H
//------------------------------------------------------------------
/// \file    Player.h
/// \author  Lloyd Phillips
/// \brief   This is the Player class, Inherits from Texture class
//------------------------------------------------------------------
#include "Texture.h"
#include "Camera.h"
#include "Vec2.h"
#include "SDL.h"
class Player : public Texture{
public:
	/// \brief Constructor
	Player();
	/// \brief destructor
	~Player();
	/// \brief Virtual Function for drawing the texture
	/// \re-defined to suit player takes the Camera, renderer
	void Draw(Camera *c, SDL_Renderer *r){
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
	/// \brief Updates the player
	/// \Update taking in DT and returns True or False
	bool update(float DT);
	///Getters and Setters
	/// \brief gets the players Position on X Y basis
	Vec2 getPos();
	/// \brief sets the players Position on X Y basis
	void setPos(Vec2 p);
	/// \brief gets the players Velocity on X Y basis
	Vec2 getVel();
	/// \brief sets the players velocity on X Y basis
	void setVel(Vec2 v);
	/// \brief gets the players health
	int getHealth();
	/// \brief sets the players health
	void setHealth(int i);
	/// \brief gets the players Magic
	int getMagic();
	/// \brief sets the players magic
	void setMagic(int i);
	bool movingL, movingR, isJumping, idle, onGround, hittingAWall, onPlatform, casting, canClimb, inRange, hasWon; ///<Different states of the Player on a true/false basis
private:
	Vec2 oldPos, pos, vel; ///<Position, Velocity, and Oldpoition(for Jumping)
	int stance, magic, health; ///<Stances, Health, Magic
};
#endif ///!PLAYER_H